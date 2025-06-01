#include <gz/sim/System.hh>
#include <gz/plugin/Register.hh>
#include <gz/transport/Node.hh>
#include <gz/msgs/twist.pb.h>
#include <gz/sim/components/LinearVelocity.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/Util.hh>
#include <iostream>

namespace subpar
{
  class SubparDronePlugin : public gz::sim::System,
                            public gz::sim::ISystemConfigure,
                            public gz::sim::ISystemPreUpdate
  {
  public:
    void Configure(const gz::sim::Entity &entity,
                   const std::shared_ptr<const sdf::Element> &,
                   gz::sim::EntityComponentManager &ecm,
                   gz::sim::EventManager &) override
    {
      std::cerr << "[SubparDronePlugin] Configure() aangeroepen voor entity: " << entity << std::endl;
      this->entity = entity;

      if (!node.Subscribe("/cmd_vel", &SubparDronePlugin::OnCmdVel, this))
      {
        std::cerr << "[SubparDronePlugin] Kon niet abonneren op /cmd_vel" << std::endl;
      }
      else
      {
        std::cerr << "[SubparDronePlugin] Abonnement op /cmd_vel succesvol" << std::endl;
      }
    }

    void PreUpdate(const gz::sim::UpdateInfo &_info,
               gz::sim::EntityComponentManager &ecm) override

    {
      if (!this->lastCmdVel)
        return;

      auto model = gz::sim::Model(this->entity);
      auto link = model.LinkByName(ecm, "body");

      if (link != gz::sim::kNullEntity)
      {
        const gz::math::Vector3d vel(this->lastCmdVel->linear().x(),
                                     this->lastCmdVel->linear().y(),
                                     this->lastCmdVel->linear().z());

        if (vel != this->lastAppliedVel)
        {
          auto velComp = ecm.Component<gz::sim::components::LinearVelocity>(link);
          if (velComp)
          {
            *velComp = gz::sim::components::LinearVelocity(vel);
          }
          else
          {
            ecm.CreateComponent(link, gz::sim::components::LinearVelocity(vel));
          }

          this->lastAppliedVel = vel;
          std::cerr << "[SubparDronePlugin] Velocity toegepast: "
                    << vel.X() << ", " << vel.Y() << ", " << vel.Z() << std::endl;
        }
      }
    }

  private:
    void OnCmdVel(const gz::msgs::Twist &msg)
    {
      this->lastCmdVel = msg;
      std::cerr << "[SubparDronePlugin] Ontvangen cmd_vel: "
                << msg.linear().x() << ", "
                << msg.linear().y() << ", "
                << msg.linear().z() << std::endl;
    }

    gz::transport::Node node;
    gz::sim::Entity entity;
    std::optional<gz::msgs::Twist> lastCmdVel;
    gz::math::Vector3d lastAppliedVel{0, 0, 0};
  };
}

GZ_ADD_PLUGIN(subpar::SubparDronePlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure,
              gz::sim::ISystemPreUpdate)
