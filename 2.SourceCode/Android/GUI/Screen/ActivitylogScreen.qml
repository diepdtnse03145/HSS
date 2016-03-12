import QtQuick 2.5
import "../Component"

Rectangle{
    id:root
    width:1080
    height:1860

    Rectangle {
        id: rectangle1
        height: 200
        color: "#005fbf"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.left: parent.left

        HSS_Button{
            color: "transparent"
            x: 25
            y: 25
            width: 150
            height: 150
            Image {
                id: backButton
                anchors.fill: parent
                source: "qrc:/img/back.png"
            }

            onClicked: {
            ScreenManager.activitylogToMainScr()
			}
        }

        Text {
            id: mainHeadline
            x: 285
            y: 49
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("Activity Log")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }
}

