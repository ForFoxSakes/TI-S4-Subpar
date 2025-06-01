#include <gz/transport/Node.hh>
#include <gz/msgs/twist.pb.h>
#include <iostream>

void OnVelMsg(const gz::msgs::Twist &msg)
{
  std::cout << "[Subscriber] Ontvangen velocity:\n";
  std::cout << "  Linear:  x=" << msg.linear().x()
            << " y=" << msg.linear().y()
            << " z=" << msg.linear().z() << std::endl;
  std::cout << "  Angular: x=" << msg.angular().x()
            << " y=" << msg.angular().y()
            << " z=" << msg.angular().z() << std::endl;
}

int main(int argc, char **argv)
{
  gz::transport::Node node;

  std::string topic = "/subpar/cmd_vel";

  if (!node.Subscribe(topic, &OnVelMsg))
  {
    std::cerr << "❌ Kon niet subscriben op topic [" << topic << "]" << std::endl;
    return -1;
  }

  std::cout << "[Subscriber] ✅ Luistert op: " << topic << std::endl;

  gz::transport::waitForShutdown();
  return 0;
}
