#pragma once

#include <gz/gui/Plugin.hh>
#include <gz/transport/Node.hh>
#include <gz/msgs/double.pb.h>
#include <QObject>

namespace subpar
{
  class KeyGuiPlugin : public gz::gui::Plugin
  {
    Q_OBJECT

    public: KeyGuiPlugin();

    public: void LoadConfig(const tinyxml2::XMLElement *_pluginElem) override;

    public slots:
      void sendLeft();
      void sendRight();

    private:
      gz::transport::Node node;
      gz::transport::Node::Publisher pub;
  };
}
