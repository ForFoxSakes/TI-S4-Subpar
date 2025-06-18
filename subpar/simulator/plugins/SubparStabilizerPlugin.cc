#include <gz/plugin/Register.hh>
#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Entity.hh>
#include <gz/sim/components/Name.hh>

#include <gz/transport/Node.hh>
#include <gz/msgs/double.pb.h>

#include <iostream>
#include <array>
#include <vector>
#include <string>

namespace subpar
{
  /// \brief System plugin for drone stabilization using Ignition PID
  class SubparStabilizerPlugin : public gz::sim::System,
                                 public gz::sim::ISystemConfigure,
                                 public gz::sim::ISystemPreUpdate
  {
    // Called once when the plugin is loaded
    void Configure(const gz::sim::Entity &_entity,
                   const std::shared_ptr<const sdf::Element> & /*_sdf*/,
                   gz::sim::EntityComponentManager &_ecm,
                   gz::sim::EventManager &) override
    {
      this->entity = _entity;
      auto nameComp = _ecm.Component<gz::sim::components::Name>(entity);
      this->modelName = nameComp->Data();
      std::cerr << "[Stabilizer] Loaded on model: " << this->modelName << std::endl;

      // Subscribe to PID output topics
      this->node.Subscribe("/pid/hover/cmd", &SubparStabilizerPlugin::OnHoverCmd, this);
      this->node.Subscribe("/pid/roll/cmd",  &SubparStabilizerPlugin::OnRollCmd,  this);
      this->node.Subscribe("/pid/pitch/cmd", &SubparStabilizerPlugin::OnPitchCmd, this);

      // Advertise thruster topics
      for (int i = 1; i <= 4; ++i)
      {
        std::string topic = "/model/motor_" + std::to_string(i) +
                            "_thruster/joint/motor_module_" + std::to_string(i) +
                            "_joint_4/cmd_thrust";
        this->thrusterPubs.push_back(
          this->node.Advertise<gz::msgs::Double>(topic));
      }
      // Initialize thrust array
      this->latestThrust.fill(0.0);
    }

    // Called each simulation iteration
    void PreUpdate(const gz::sim::UpdateInfo &/*_info*/, 
                   gz::sim::EntityComponentManager &/*_ecm*/) override
    {
      // Publish thruster commands
      for (size_t i = 0; i < this->thrusterPubs.size(); ++i)
      {
        gz::msgs::Double msg;
        msg.set_data(this->latestThrust[i]);
        this->thrusterPubs[i].Publish(msg);
      }
    }

  private:
    /// \brief Handler for hover PID output
    void OnHoverCmd(const gz::msgs::Double &_msg)
    {
      // Distribute equally
      double cmd = _msg.data();
      for (auto &t : this->latestThrust)
        t = cmd / 4.0;
    }

    /// \brief Handler for roll PID output
    void OnRollCmd(const gz::msgs::Double &_msg)
    {
      double cmd = _msg.data();
      // Left motors increase, right motors decrease
      this->latestThrust = { cmd, cmd, -cmd, -cmd };
    }

    /// \brief Handler for pitch PID output
    void OnPitchCmd(const gz::msgs::Double &_msg)
    {
      double cmd = _msg.data();
      // Front motors increase, back motors decrease
      this->latestThrust = { cmd, -cmd, cmd, -cmd };
    }

    // Private data
    gz::sim::Entity entity;
    std::string modelName;
    gz::transport::Node node;
    std::vector<gz::transport::Node::Publisher> thrusterPubs;
    std::array<double, 4> latestThrust;
  };

  // Register the plugin
    }  // namespace subpar

// Register the plugin
GZ_ADD_PLUGIN(
  ::subpar::SubparStabilizerPlugin,
  gz::sim::System,
  gz::sim::ISystemConfigure,
  gz::sim::ISystemPreUpdate)
