#include <gz/sim/System.hh>
#include <iostream>

namespace subpar
{
  class SubparDronePlugin : public gz::sim::System,
                             public gz::sim::ISystemConfigure
  {
  public:
    void Configure(const gz::sim::Entity &entity,
                   const std::shared_ptr<const sdf::Element> &sdf,
                   gz::sim::EntityComponentManager &ecm,
                   gz::sim::EventManager &eventMgr) override
    {
      std::cout << "[SubparDronePlugin] Drone geladen met entity ID: " << entity << std::endl;
    }
  };
}

GZ_ADD_PLUGIN(subpar::SubparDronePlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure)
