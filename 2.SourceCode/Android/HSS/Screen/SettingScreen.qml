import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
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
            text: qsTr("Settings")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }

    Rectangle {
        id: deleteActivityLogButton
        x: 0
        y: 1200
        width: 1080
        height: 200
        color: "#d0150a"

        Text {
            id: deleteActivityLogText
            x: 285
            y: 54
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("Delete Activity Log")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
            verticalAlignment: Text.AlignVCenter
        }
    }


    HSS_Button {
        id: buttonLogout
        x: 550
        y: 1500
        width: 492
        height: 127
        color: "#e65959"

        Text {
            id: endText
            x: 121
            y: 22
            width: 251
            height: 84
            color: "#ffffff"
            text: qsTr("Logout")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 70
        }

        onClicked: {
            ScreenManager.toLoginScr();
        }
    }

    Text {
        id: statusConnection1
        x: 60
        y: 348
        width: 426
        height: 71
        text: qsTr("Detect Motion")
        font.pixelSize: 70
    }

    Switch {
        id: motionSwitch
        x: 773
        y: 348
        width: 240
        height: 80
        onClicked: {
            Engine.pi_enableDetectMotion(checked)
        }
    }

    Text {
        id: statusConnection2
        x: 60
        y: 558
        width: 426
        height: 71
        text: qsTr("Detect Door")
        font.pixelSize: 70
    }


    Switch {
        id: doorSwitch
        x: 773
        y: 558
        width: 240
        height: 80
        scale: 1
        onClicked: {
            Engine.pi_enableDetectDoor(checked)
        }
    }

    Text {
        id: statusConnection3
        x: 60
        y: 780
        width: 426
        height: 71
        text: qsTr("Doorbell")
        font.pixelSize: 70
    }
    Switch {
        id: bellSwitch
        x: 773
        y: 780
        width: 240
        height: 80
        scale: 1
        onClicked: {
            Engine.pi_enableDoorBell(checked)
        }
    }

    HSS_Button {
        id: buttonChangePassword
        x: 36
        y: 1500
        width: 492
        height: 127
        color: "#e65959"

        Text {
            id: textChangePassword
            x: 121
            y: 22
            width: 251
            height: 84
            color: "#ffffff"
            text: qsTr("Change Pwd")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 70
        }

        onClicked: {
            ScreenManager.toChangePassScr();
        }
    }
}

