import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
    }

    Label {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            Engine.showOnscreen("Moe")
        }
    }
}
