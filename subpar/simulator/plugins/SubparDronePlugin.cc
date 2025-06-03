#include <gz/plugin/Register.hh>
#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Entity.hh>
#include <gz/sim/Events.hh>

#include <gz/transport/Node.hh>
#include <gz/msgs/double.pb.h>

#include <iostream>
#include <chrono>
#include <cmath>

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
      pub_j1 = node.Advertise<gz::msgs::Double>("/topic_name");
      pub_j2 = node.Advertise<gz::msgs::Double>("/topic_j2");

      if (!pub_j1 || !pub_j2)
      {
        std::cerr << "❌ Kon niet adverteren op één of beide topics\n";
      }
      else
      {
        std::cerr << "✅ Publishers actief op /topic_name en /topic_j2\n";
      }

      lastPublishTime = std::chrono::steady_clock::now();
    }

    void PreUpdate(const gz::sim::UpdateInfo &,
                   gz::sim::EntityComponentManager &) override
    {
      auto now = std::chrono::steady_clock::now();
      auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastPublishTime);

      if (elapsed.count() >= 2)
      {
        gz::msgs::Double msg;
        if (currentState == 0)
        {
          angle_j1 += M_PI_2;
          if (angle_j1 >= 2 * M_PI) angle_j1 -= 2 * M_PI;
          msg.set_data(angle_j1);
          pub_j1.Publish(msg);
          std::cout << "📤 j1 -> " << angle_j1 << " rad gepubliceerd\n";
          currentState = 1;
        }
        else
        {
          angle_j2 += M_PI_2;
          if (angle_j2 >= 2 * M_PI) angle_j2 -= 2 * M_PI;
          msg.set_data(angle_j2);
          pub_j2.Publish(msg);
          std::cout << "📤 j2 -> " << angle_j2 << " rad gepubliceerd\n";
          currentState = 0;
        }

        lastPublishTime = now;
      }
    }

  private:
    gz::transport::Node node;
    gz::transport::Node::Publisher pub_j1;
    gz::transport::Node::Publisher pub_j2;
    std::chrono::steady_clock::time_point lastPublishTime;
    int currentState{0};         // 0: j1, 1: j2
    double angle_j1{0.0};
    double angle_j2{0.0};
  };
}

GZ_ADD_PLUGIN(subpar::SubparPublisherPlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure,
              gz::sim::ISystemPreUpdate)
