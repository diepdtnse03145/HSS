import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
//            notificationClient.notification = "moe moe"
        }
    }
}