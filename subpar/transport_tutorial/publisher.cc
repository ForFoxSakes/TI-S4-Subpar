#include <gz/transport/Node.hh>
#include <gz/msgs/twist.pb.h>
#include <chrono>
#include <thread>
#include <iostream>

int main(int argc, char **argv)
{
  // Maak een transport node aan
  gz::transport::Node node;

  // Topic waarop we willen publiceren
  std::string topic = "/subpar/cmd_vel";

  // Maak een Publisher object aan
  auto pub = node.Advertise<gz::msgs::Twist>(topic);
  if (!pub)
  {
    std::cerr << "❌ Kon geen publisher maken voor topic [" << topic << "]" << std::endl;
    return -1;
  }

  std::cout << "✅ Publisher actief op topic: " << topic << std::endl;

  // Maak het bericht
  gz::msgs::Twist msg;
  msg.mutable_linear()->set_x(0.5);   // Voorwaartse snelheid
  msg.mutable_angular()->set_z(0.2);  // Rotatie

  // Verstuur meerdere berichten met tussenpauzes
  for (int i = 0; i < 10; ++i)
  {
    if (!pub.Publish(msg))
    {
      std::cerr << "❌ Fout bij publiceren" << std::endl;
    }
    else
    {
      std::cout << "📤 Bericht " << i+1 << " gepubliceerd" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  return 0;
}
