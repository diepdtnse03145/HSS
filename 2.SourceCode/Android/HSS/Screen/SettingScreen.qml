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

    Text {
        id: statusConnection
        x: 59
        y: 312
        width: 426
        height: 71
        text: qsTr("System Status:")
        font.pixelSize: 70
        font.family: "Arial"
        style: Text.Normal
        wrapMode: Text.NoWrap
        textFormat: Text.AutoText
    }


        Switch {
            id: switchtch
            x: 773
            y: 312
            width: 240
            height: 80

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
        y: 551
        width: 426
        height: 71
        text: qsTr("Detect Motion")
        font.pixelSize: 70
    }


        Switch {
            id: switchtch1
            x: 773
            y: 551
            width: 240
            height: 80

        }



    Text {
        id: statusConnection2
        x: 60
        y: 791
        width: 426
        height: 71
        text: qsTr("Detect Door")
        font.pixelSize: 70
    }


        Switch {
            id: switchtch2
            x: 773
            y: 791
            width: 240
            height: 80
            scale: 1

        }



    Text {
        id: statusConnection3
        x: 60
        y: 1041
        width: 426
        height: 71
        text: qsTr("Doorbell")
        font.pixelSize: 70
    }
    Switch {
        id: switchtch3
        x: 773
        y: 1041
        width: 240
        height: 80
        scale: 1

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
            ScreenManager.toChangePassScr()
        }
    }




}

