#include <iostream>
#include <iomanip>            // <<<<<<<<<<<<<<<<<<<<<< voeg dit toe
#include <gz/msgs/imu.pb.h>
#include <gz/transport/Node.hh>

void OnIMUMessage(const gz::msgs::IMU &msg)
{
  double x = msg.angular_velocity().x();
  double y = msg.angular_velocity().y();
  double z = msg.angular_velocity().z();

  // std::fixed dwingt vaste notatie af, setprecision bepaalt aantal decimalen
  std::cout << std::fixed << std::setprecision(6)
            << "Gyro [rad/s] → "
            << "X: " << std::setw(8) << x << "  "
            << "Y: " << std::setw(8) << y << "  "
            << "Z: " << std::setw(8) << z
            << std::endl;
}

int main(int argc, char **argv)
{
  gz::transport::Node node;
  node.Subscribe("/imu", OnIMUMessage);
  gz::transport::waitForShutdown();
  return 0;
}
