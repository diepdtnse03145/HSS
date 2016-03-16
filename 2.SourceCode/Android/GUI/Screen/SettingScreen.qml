import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
import "../Component"

Rectangle{
    id:root
    width:1080
    height:1920

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

    Column {
        id: switchButton
        x: 600
        y: 250
        width: 387
        height: 171
        smooth: true
        visible: true
        clip: false
        transformOrigin: Item.Center
        Switch {
            id: switchtch
            x: 180
            y: 0
            width: 50
            height: 30
            smooth: true
            antialiasing: false
            z: 0
            activeFocusOnPress: false
            transformOrigin: Item.Top
            clip: false
            opacity: 1
            enabled: true
            rotation: 0
            checked: true
            scale: 8
            visible: true
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
        y: 551
        width: 426
        height: 71
        text: qsTr("Detect Motion")
        font.pixelSize: 70
    }

    Column {
        id: switchButton1
        x: 600
        y: 495
        width: 387
        height: 171
        smooth: true
        visible: true
        clip: false
        transformOrigin: Item.Center
        Switch {
            id: switchtch1
            x: 100
            width: 50
            height: 30
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            smooth: true
            antialiasing: true
            z: 0
            activeFocusOnPress: false
            transformOrigin: Item.TopLeft
            clip: false
            opacity: 1
            enabled: true
            rotation: 0
            checked: true
            scale: 8
            visible: true
        }

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

    Column {
        id: switchButton2
        x: 605
        y: 735
        width: 387
        height: 171
        transformOrigin: Item.Center
        smooth: true
        clip: false
        Switch {
            id: switchtch2
            width: 50
            height: 30
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            smooth: true
            z: 0
            antialiasing: true
            activeFocusOnPress: false
            transformOrigin: Item.TopLeft
            opacity: 1
            clip: false
            enabled: true
            rotation: 0
            checked: true
            visible: true
            scale: 8
        }

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

    Column {
        id: switchButton3
        x: 605
        y: 985
        width: 387
        height: 171
        transformOrigin: Item.Center
        smooth: true
        clip: false
        Switch {
            id: switchtch3
            x: 0
            y: 15
            width: 50
            height: 30
            smooth: false
            antialiasing: true
            z: 0
            activeFocusOnPress: false
            transformOrigin: Item.TopLeft
            clip: false
            opacity: 1
            enabled: true
            rotation: 0
            checked: true
            scale: 8
            visible: true
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
    }
}

