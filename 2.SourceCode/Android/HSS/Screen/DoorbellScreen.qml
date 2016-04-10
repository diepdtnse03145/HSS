import QtQuick 2.5
import "../Component"

ScreenBase{
    id:root
    onBackKeyCaptured: {
        backButton.clicked()
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 1080
        height: 200
        color: "#005fbf"

        HSS_Button{
            id: backButton
            color: "transparent"
            x: 25
            y: 25
            width: 150
            height: 150
            Image {
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


    HSS_Button {
        id: callButton
        x: 326
        y: 1468
        width: 428
        height: 127
        visible: true
        color: "#4ae263"

        Text {
            id: callText
            x: 74
            y: 22
            color: "#ffffff"
            text: qsTr("Start Call")
            font.pixelSize: 70
        }
        onClicked: {
            Engine.pi_requestCallAdd()
            callButton.visible = false
            endButton.visible = true
        }
    }


    HSS_Button {
        id: endButton
        x: 326
        y: 1468
        width: 428
        height: 127
        visible: false
        color: "#e65959"
        Text {
            id: endText
            x: 89
            y: 22
            color: "#ffffff"
            text: qsTr("End Call")
            font.pixelSize: 70
        }
        onClicked: {
            Engine.endCall()
            callButton.visible = true
            endButton.visible = false
        }
    }

    HSS_Button {
        id: speakerButton
        x: 326
        y: 561
        width: 428
        height: 127
        color: "#4ae263"

        Text {
            id: speakerText
            anchors.centerIn: parent
            color: "#ffffff"
            text: qsTr("Speaker")
            font.pixelSize: 70
        }
    }
}

