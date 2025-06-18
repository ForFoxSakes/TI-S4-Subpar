#include <gz/plugin/Register.hh>
#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Entity.hh>

#include <gz/transport/Node.hh>
#include <gz/msgs/stringmsg.pb.h>
#include <gz/msgs/double.pb.h>
#include <gz/msgs/int32.pb.h> // voor key-codes

#include <iostream>
#include <cmath>
#include <regex>
#include <vector>

namespace subpar
{
  class SubparPublisherPlugin : public gz::sim::System,
                                public gz::sim::ISystemConfigure,
                                public gz::sim::ISystemPreUpdate
  {
  public:
    void Configure(const gz::sim::Entity &entity,
                   const std::shared_ptr<const sdf::Element> &,
                   gz::sim::EntityComponentManager &_ecm,
                   gz::sim::EventManager &) override
    {
      this->entity    = entity;
      this->modelName = gz::sim::Model(this->entity).Name(_ecm);
      std::cerr << "🚁 Plugin running on model: " << modelName << "\n";

      // --- Joint-1 en Joint-2 publishers (pitch + yaw) ---
      for (int i = 1; i <= 4; ++i)
      {
        auto p1 = node.Advertise<gz::msgs::Double>(
          "motor_module_" + std::to_string(i) + "_joint_1");
        auto p2 = node.Advertise<gz::msgs::Double>(
          "motor_module_" + std::to_string(i) + "_joint_2");
        jointPubs.emplace_back(p1, p2);
      }

      // --- Thruster publishers (cmd_thrust) ---
      for (int i = 1; i <= 4; ++i)
      {
        auto pt = node.Advertise<gz::msgs::Double>(
          "/model/motor_" + std::to_string(i) +
          "_thruster/joint/motor_module_" + std::to_string(i) +
          "_joint_4/cmd_thrust");
        thrusterPubs.push_back(pt);
      }

      // --- Subscribe aan direction_input (extern via topic) ---
      node.Subscribe("/direction_input",
                     &SubparPublisherPlugin::OnDirectionStringMsg,
                     this);

      // --- Subscribe aan thrust_input (extern via topic) ---
      node.Subscribe("/thrust_input",
                     &SubparPublisherPlugin::OnThrustMsg,
                     this);

      // --- Subscribe aan keyboard-events ---
      node.Subscribe("/keyboard/keypress",
                     &SubparPublisherPlugin::OnKey, this);

      std::cerr << "✅ Subscribed to /keyboard/keypress\n"
                << "✅ Subscribed to /direction_input, /thrust_input\n"
                << "✅ Plugin configured for " << modelName << "\n";
    }

    void PreUpdate(const gz::sim::UpdateInfo &,
                   gz::sim::EntityComponentManager &) override
    {
      // 1) Joint-publishing (pitch & yaw)
      if (directionUpdated)
      {
        gz::msgs::Double m1, m2;
        m1.set_data(angle_j1);
        m2.set_data(angle_j2);
        for (auto &p : jointPubs)
          if (p.first.Publish(m1) && p.second.Publish(m2)) {}
        directionUpdated = false;
      }

      // 2) Thruster-publishing
      if (thrustUpdated)
      {
        gz::msgs::Double mt;
        mt.set_data(lastThrustValue);
        for (auto &pt : thrusterPubs)
          pt.Publish(mt);
        thrustUpdated = false;
      }
    }

    // Callback via /direction_input (StringMsg) blijft beschikbaar
    void OnDirectionStringMsg(const gz::msgs::StringMsg &msg)
    {
      std::smatch m; std::string s = msg.data();
      double pitch=0,yaw=0;
      std::regex rP(R"(pitch\s*:\s*(-?\d+(\.\d+)?))");
      std::regex rY(R"(yaw\s*:\s*(-?\d+(\.\d+)?))");
      if (std::regex_search(s,m,rP)) pitch = std::stod(m[1]);
      if (std::regex_search(s,m,rY))   yaw = std::stod(m[1]);
      angle_j1 = pitch * M_PI/180.0;
      angle_j2 = yaw   * M_PI/180.0;
      directionUpdated = true;
    }

    // Callback via /thrust_input (Double) blijft beschikbaar
    void OnThrustMsg(const gz::msgs::Double &msg)
    {
      lastThrustValue = msg.data();
      thrustUpdated   = true;
    }

void OnKey(const gz::msgs::Int32 &keyMsg)
{
  int code = keyMsg.data();
  constexpr double dAng = 5.0 * M_PI/180.0;  // 5° stap
  constexpr double dTh  = 0.1;               // thrust stap

  switch (code)
  {
    case 87: // W
      angle_j1 += dAng; break;
    case 83: // S
      angle_j1 -= dAng; break;
    case 65: // A
      angle_j2 += dAng; break;
    case 68: // D
      angle_j2 -= dAng; break;
    case 72: // H
      lastThrustValue += dTh; thrustUpdated = true; break;
    case 75: // K
      lastThrustValue -= dTh; thrustUpdated = true; break;
    default:
      return;
  }

  // Clamp pitch tussen –90° en +90°
  const double maxPitch = M_PI/2;
  if (angle_j1 >  maxPitch) angle_j1 =  maxPitch;
  if (angle_j1 < -maxPitch) angle_j1 = -maxPitch;

  // Wrap yaw modulair 2π zodat je full 360° kunt maken
  angle_j2 = std::fmod(angle_j2 + M_PI, 2*M_PI);
  if (angle_j2 < 0)
    angle_j2 += 2*M_PI;
  angle_j2 -= M_PI;

  directionUpdated = true;

  std::cout << "⌨️ Key " << code
            << " → pitch=" << angle_j1*180.0/M_PI
            << "°, yaw="   << angle_j2*180.0/M_PI
            << "°, thrust="<< lastThrustValue << "\n";
}


  private:
    gz::transport::Node node;

    std::vector<std::pair<
      gz::transport::Node::Publisher,
      gz::transport::Node::Publisher>> jointPubs;

    std::vector<gz::transport::Node::Publisher> thrusterPubs;

    std::string modelName;
    gz::sim::Entity entity;

    double angle_j1{0.0}, angle_j2{0.0};
    bool directionUpdated{false};

    double lastThrustValue{0.0};
    bool thrustUpdated{false};
  };
}

// Register the plugin
GZ_ADD_PLUGIN(subpar::SubparPublisherPlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure,
              gz::sim::ISystemPreUpdate)
