#include <gz/gui/Application.hh>
#include <gz/gui/MainWindow.hh>
#include <gz/gui/Plugin.hh>
#include <gz/gui/GuiIface.hh>
#include <gz/transport/Node.hh>
#include <gz/msgs/double.pb.h>
#include <QObject>

namespace gz {
namespace gui {
namespace plugins {

class GuiPlugin : public Plugin,
                              public QObject
{
  Q_OBJECT
  // Register as a GUI plugin
  GZ_ADD_PLUGIN(GuiPlugin,
                Plugin)
  GZ_CLONABLE_PLUGIN(GuiPlugin)

public:
  GuiPlugin() : Plugin(), transportNode(), pitch(0), yaw(0), thrust(0) {}

  void LoadConfig(const tinyxml2::XMLElement * /*_pluginElem*/) override
  {
    // No config needed
  }

  void PreRender() override
  {
    // Update GUI labels each frame
    this->pitchLabel->setText(QString::asprintf("Pitch: %.1f°", this->pitch));
    this->yawLabel->setText(QString::asprintf("Yaw: %.1f°", this->yaw));
    this->thrustLabel->setText(QString::asprintf("Thrust: %.2f", this->thrust));
  }

  void OnClicked()
  {
    gz::gui::App()->findChild<MainWindow *>()->SetFullScreen(!this->isFullscreen);
    this->isFullscreen = !this->isFullscreen;
  }

  void SubscribeTopics()
  {
    // Subscribe to joint topics
    for (int i = 1; i <= 4; ++i)
    {
      std::string topicJ1 = "motor_module_" + std::to_string(i) + "_joint_1";
      this->transportNode.Subscribe(topicJ1,
        &GuiPlugin::OnJoint1, this);
      std::string topicJ2 = "motor_module_" + std::to_string(i) + "_joint_2";
      this->transportNode.Subscribe(topicJ2,
        &GuiPlugin::OnJoint2, this);
    }
    // Subscribe to thrust
    this->transportNode.Subscribe("/thrust_input",
      &GuiPlugin::OnThrust, this);
  }

protected:
  void Initialize() override
  {
    // Create UI elements
    this->pitchLabel = new QLabel("Pitch: 0°",
      this->Widget());
    this->yawLabel = new QLabel("Yaw: 0°",
      this->Widget());
    this->thrustLabel = new QLabel("Thrust: 0.00",
      this->Widget());

    auto *layout = new QVBoxLayout(this->Widget());
    layout->addWidget(this->pitchLabel);
    layout->addWidget(this->yawLabel);
    layout->addWidget(this->thrustLabel);

    this->Widget()->setLayout(layout);

    // Subscribe to topics
    this->SubscribeTopics();
  }

private:
  void OnJoint1(const gz::msgs::Double &_msg)
  {
    // Convert radian to deg
    this->pitch = _msg.data() * 180.0 / M_PI;
  }

  void OnJoint2(const gz::msgs::Double &_msg)
  {
    this->yaw = _msg.data() * 180.0 / M_PI;
  }

  void OnThrust(const gz::msgs::Double &_msg)
  {
    this->thrust = _msg.data();
  }

  transport::Node transportNode;
  QLabel *pitchLabel;
  QLabel *yawLabel;
  QLabel *thrustLabel;
  double pitch;
  double yaw;
  double thrust;
  bool isFullscreen{false};
};

}  // namespace plugins
}  // namespace gui
}  // namespace gz

#include "GuiPlugin.moc"
