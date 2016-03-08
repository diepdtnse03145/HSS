import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0

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

        Image {
            id: backButton
            x: 25
            y: 25
            width: 150
            height: 150
            source: "../../../../../../Downloads/back.png"
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
    }

    Column {
        id:switchButton
        x: 604
        y: 256
        width: 387
        height: 171
        transformOrigin: Item.TopLeft
        Switch { id: switchtch; x: 0; y: 15; width: 57; height: 26; z: 0; rotation: 0; enabled: true; smooth: true; opacity: 1; clip: false; visible: true; antialiasing: false; scale: 8; transformOrigin: Item.TopLeft; activeFocusOnPress: false; checked: true }
    }

    Rectangle {
        id: endButton
        x: 550
        y: 1688
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
        x: 605
        y: 495
        width: 387
        height: 171
        Switch {
            id: switchtch1
            x: 0
            y: 15
            width: 57
            height: 26
            smooth: true
            antialiasing: false
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
        transformOrigin: Item.TopLeft
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
        Switch {
            id: switchtch2
            x: 0
            y: 15
            width: 57
            height: 26
            smooth: true
            z: 0
            antialiasing: false
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
        transformOrigin: Item.TopLeft
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
        Switch {
            id: switchtch3
            x: 0
            y: 15
            width: 57
            height: 26
            smooth: true
            antialiasing: false
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
        transformOrigin: Item.TopLeft
    }

    Rectangle {
        id: endButton1
        x: 36
        y: 1688
        width: 492
        height: 127
        color: "#e65959"
        Text {
            id: endText1
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

