#include "SubparKeyGuiPlugin.hpp"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <gz/gui/Application.hh>
#include <gz/gui/GuiEvents.hh>
#include <gz/plugin/Register.hh>

using namespace subpar;

/////////////////////////////////////////////////
KeyGuiPlugin::KeyGuiPlugin()
{
  this->pub = this->node.Advertise<gz::msgs::Double>("/topic_name");
}

/////////////////////////////////////////////////
void KeyGuiPlugin::LoadConfig(const tinyxml2::XMLElement * /*_pluginElem*/)
{
  // Geen LoadQml of setHasGUI aanroepen
}

/////////////////////////////////////////////////
void KeyGuiPlugin::sendLeft()
{
  gz::msgs::Double msg;
  msg.set_data(-1.0);
  this->pub.Publish(msg);
  std::cout << "⬅️  Left published\n";
}

/////////////////////////////////////////////////
void KeyGuiPlugin::sendRight()
{
  gz::msgs::Double msg;
  msg.set_data(1.0);
  this->pub.Publish(msg);
  std::cout << "➡️  Right published\n";
}

// ❗ Buiten de namespace!
GZ_ADD_PLUGIN(subpar::KeyGuiPlugin, gz::gui::Plugin)
