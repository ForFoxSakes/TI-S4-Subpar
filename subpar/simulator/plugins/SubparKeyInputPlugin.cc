#include <gz/plugin/Register.hh>
#include <gz/sim/System.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Entity.hh>
#include <gz/sim/Events.hh>

#include <gz/transport/Node.hh>
#include <gz/msgs/double.pb.h>
#include <thread>
#include <atomic>
#include <iostream>
#include <termios.h>
#include <unistd.h>

namespace subpar
{
class SubparKeyInputPlugin : public gz::sim::System,
                             public gz::sim::ISystemConfigure,
                             public gz::sim::ISystemPreUpdate
{
public:
  void Configure(const gz::sim::Entity &,
                 const std::shared_ptr<const sdf::Element> &,
                 gz::sim::EntityComponentManager &,
                 gz::sim::EventManager &) override
  {
    pub = node.Advertise<gz::msgs::Double>("/topic_name");
    std::cerr << "🎮 Keyboard plugin actief. Gebruik A/D om te draaien.\n";

    running = true;
    keyThread = std::thread([this]() { this->KeyLoop(); });
  }

  void PreUpdate(const gz::sim::UpdateInfo &,
                 gz::sim::EntityComponentManager &) override
  {
    if (pub)
    {
      gz::msgs::Double msg;
      msg.set_data(this->angle.load());
      pub.Publish(msg);
    }
  }

  ~SubparKeyInputPlugin() override
  {
    running = false;
    if (keyThread.joinable())
      keyThread.join();
  }

private:
  void KeyLoop()
  {
    SetTerminalRaw(true);
    while (running)
    {
      char c;
      if (read(STDIN_FILENO, &c, 1) > 0)
      {
        if (c == 'a')
          angle.store(angle.load() - step);

        else if (c == 'd')
          angle.store(angle.load() + step);

        std::cout << "🔁 Nieuwe hoek: " << angle.load() << " rad\n";
      }
    }
    SetTerminalRaw(false);
  }

  void SetTerminalRaw(bool enable)
  {
    static struct termios oldt, newt;
    if (enable)
    {
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    else
    {
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
  }

  gz::transport::Node node;
  gz::transport::Node::Publisher pub;
  std::thread keyThread;
  std::atomic<bool> running{false};
  std::atomic<double> angle{0.0};
  const double step = 0.1;
};
}

GZ_ADD_PLUGIN(subpar::SubparKeyInputPlugin,
              gz::sim::System,
              gz::sim::ISystemConfigure,
              gz::sim::ISystemPreUpdate)
