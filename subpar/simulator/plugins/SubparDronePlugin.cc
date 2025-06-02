#include <gz/plugin/Register.hh>
#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Entity.hh>
#include <gz/sim/Events.hh>

#include <gz/transport/Node.hh>
#include <gz/msgs/double.pb.h>

#include <iostream>

namespace subpar
{
  class SubparPublisherPlugin : public gz::sim::System,
                                public gz::sim::ISystemConfigure,
                                public gz::sim::ISystemPreUpdate
  {
  public:
    void Configure(const gz::sim::Entity &,
                   const std::shared_ptr<const sdf::Element> &,
                   gz::sim::EntityComponentManager &,
                   gz::sim::EventManager &) override
    {
      // Maak publisher op het topic dat jouw controller plugin luistert
      this->pub = this->node.Advertise<gz::msgs::Double>("/topic_name");

      if (!this->pub)
        std::cerr << "❌ Kan niet publiceren naar /topic_name\n";
      else
        std::cerr << "✅ Publisher actief op /topic_name\n";

      this->published = false;
    }

    void PreUpdate(const gz::sim::UpdateInfo &,
                   gz::sim::EntityComponentManager &) override
    {
      // Eenmalig publiceren van gewenste hoek
      if (!published && this->pub)
      {
        gz::msgs::Double msg;
        msg.set_data(1.0);  // Bijvoorbeeld: 1 radiaan
        this->pub.Publish(msg);
        std::cout << "📤 Doelpositie gepubliceerd: " << msg.data() << " rad\n";
        this->published = true;
      }
    }

  private:
    gz::transport::Node node;
    gz::transport::Node::Publisher pub;
    bool published{false};
  };
}

GZ_ADD_PLUGIN(subpar::SubparPublisherPlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure,
              gz::sim::ISystemPreUpdate)
