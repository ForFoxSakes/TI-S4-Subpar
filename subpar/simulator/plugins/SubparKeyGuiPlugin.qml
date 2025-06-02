import QtQuick 2.15
import QtQuick.Controls 2.15
import GzGui 1.0

Item {
  Rectangle {
    width: 200
    height: 100
    color: "#444"

    Row {
      spacing: 10
      anchors.centerIn: parent

      Button {
        text: "⬅️"
        onClicked: gz.gui.plugins["subpar::KeyGuiPlugin"].sendLeft()
      }
      Button {
        text: "➡️"
        onClicked: gz.gui.plugins["subpar::KeyGuiPlugin"].sendRight()
      }
    }
  }
}
