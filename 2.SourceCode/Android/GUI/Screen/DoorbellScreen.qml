import QtQuick 2.5
import "../Component"

Rectangle{
    id:root
    width:1080
    height:1860

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 1080
        height: 200
        color: "#005fbf"

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
                ScreenManager.toMainScr()
            }
        }

        Text {
            id: mainHeadline
            x: 285
            y: 49
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("Door Bell")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }

    Text {
        id: statusConnection
        x: 73
        y: 413
        width: 583
        height: 84
        text: qsTr("Connection Status:")
        font.pixelSize: 70
    }

    HSS_Button {
        id: callButton
        x: 71
        y: 636
        width: 428
        height: 127
        color: "#4ae263"

        Text {
            id: callText
            x: 74
            y: 22
            color: "#ffffff"
            text: qsTr("Start Call")
            font.pixelSize: 70
        }
    }

    HSS_Button {
        id: endButton
        x: 556
        y: 636
        width: 428
        height: 127
        color: "#e65959"
        Text {
            id: endText
            x: 89
            y: 22
            color: "#ffffff"
            text: qsTr("End Call")
            font.pixelSize: 70
        }
    }

    Text {
        id: statusConnection1
        x: 675
        y: 413
        width: 372
        height: 84
        color: "#e50c0c"
        text: qsTr("Idle")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 70
    }


}

