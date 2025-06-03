#include <gz/plugin/Register.hh>
#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Entity.hh>
#include <gz/sim/Events.hh>

#include <gz/transport/Node.hh>
#include <gz/msgs/stringmsg.pb.h>
#include <gz/msgs/double.pb.h>

#include <iostream>
#include <chrono>
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
      this->entity = entity;
      gz::sim::Model model(this->entity);
      this->modelName = model.Name(_ecm);

      // joint angle topics (per motor)
      this->topicJ1 = "/" + modelName + "_joint_1";
      this->topicJ2 = "/" + modelName + "_joint_2";

      this->pub_j1 = node.Advertise<gz::msgs::Double>(this->topicJ1);
      this->pub_j2 = node.Advertise<gz::msgs::Double>(this->topicJ2);

      // thrust publishers met correcte namespaces en jointnamen
      for (int i = 1; i <= 4; ++i)
      {
        std::string modelNamespace = "motor_" + std::to_string(i) + "_thruster";
        std::string jointName = "motor_module_" + std::to_string(i) + "_joint_4";
        std::string topic = "/model/" + modelNamespace + "/joint/" + jointName + "/cmd_thrust";

        auto pub = node.Advertise<gz::msgs::Double>(topic);
        if (pub)
        {
          thrustPubs.push_back(pub);
          std::cerr << "✅ Publisher actief op " << topic << "\n";
        }
        else
        {
          std::cerr << "❌ Kon geen publisher maken voor " << topic << "\n";
        }
      }

      node.Subscribe("/direction_input", &SubparPublisherPlugin::OnDirectionStringMsg, this);
      node.Subscribe("/thrust_input", &SubparPublisherPlugin::OnThrustMsg, this);

      std::cerr << "✅ [" << modelName << "] Luistert op /direction_input en /thrust_input\n";
    }

    void PreUpdate(const gz::sim::UpdateInfo &,
                   gz::sim::EntityComponentManager &) override
    {
      if (directionUpdated)
      {
        gz::msgs::Double msg1, msg2;
        msg1.set_data(angle_j1);
        msg2.set_data(angle_j2);
        pub_j1.Publish(msg1);
        pub_j2.Publish(msg2);

        std::cout << "📤 [" << modelName << "] j1 (pitch) = " << angle_j1
                  << " rad, j2 (yaw) = " << angle_j2 << " rad\n";
        directionUpdated = false;
      }

      if (thrustUpdated)
      {
        gz::msgs::Double thrustMsg;
        thrustMsg.set_data(lastThrustValue);

        for (auto &pub : thrustPubs)
          pub.Publish(thrustMsg);

        std::cout << "📤 Broadcast thrust: " << lastThrustValue << " N naar alle thrusters\n";
        thrustUpdated = false;
      }
    }

    void OnDirectionStringMsg(const gz::msgs::StringMsg &msg)
    {
      std::string input = msg.data();
      std::smatch match;

      double pitch_deg = 0, yaw_deg = 0;
      std::regex pitch_rgx(R"(pitch\s*:\s*(-?\d+(\.\d+)?))");
      std::regex yaw_rgx(R"(yaw\s*:\s*(-?\d+(\.\d+)?))");

      if (std::regex_search(input, match, pitch_rgx))
        pitch_deg = std::stod(match[1]);

      if (std::regex_search(input, match, yaw_rgx))
        yaw_deg = std::stod(match[1]);

      angle_j1 = pitch_deg * M_PI / 180.0;
      angle_j2 = yaw_deg * M_PI / 180.0;
      directionUpdated = true;

      std::cout << "📥 [" << modelName << "] Ontvangen: pitch=" << pitch_deg
                << "°, yaw=" << yaw_deg << "°\n";
    }

    void OnThrustMsg(const gz::msgs::Double &msg)
    {
      lastThrustValue = msg.data();
      thrustUpdated = true;
    }

  private:
    gz::transport::Node node;
    gz::transport::Node::Publisher pub_j1;
    gz::transport::Node::Publisher pub_j2;
    std::vector<gz::transport::Node::Publisher> thrustPubs;

    std::string topicJ1, topicJ2;
    std::string modelName;
    gz::sim::Entity entity;

    double angle_j1{0.0};
    double angle_j2{0.0};
    bool directionUpdated{false};

    double lastThrustValue{0.0};
    bool thrustUpdated{false};
  };
}

GZ_ADD_PLUGIN(subpar::SubparPublisherPlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure,
              gz::sim::ISystemPreUpdate)
