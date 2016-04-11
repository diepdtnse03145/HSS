import QtQuick 2.5
import "../Component"

ScreenBase{
    id:root

    onBackKeyCaptured: {
        Engine.toHome()
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 1080
        height: 200
        color: "#005fbf"

        Text {
            id: mainHeadline
            x: 285
            y: 49
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("HSS")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }

    HSS_Button {
        id: buttonActivityLog
        x: 190
        y: 420
        width: 700
        height: 200
        color: "#005fbf"
        antialiasing: false
        transformOrigin: Item.Center
        anchors.right: parent.right
        anchors.rightMargin: 190

        Text {
            id:textActivityLog
            width: 352
            height: 127
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Activity Log"
            font.family: "Arial"
            style: Text.Normal
            wrapMode: Text.NoWrap
            font.pixelSize: 76
            verticalAlignment: Text.AlignVCenter
            textFormat: Text.AutoText
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
        }

        onClicked: {
            ActivityModel.clear()
            Engine.pi_requestActivityLog()
            ScreenManager.toActivityLogScr();
        }
    }

    HSS_Button {
        id: buttonCamera
        x: 190
        y: 689
        width: 700
        height: 200
        color: "#005fbf"
        antialiasing: false
        transformOrigin: Item.Center

        Text {
            id:textCamera
            width: 352
            height: 127
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Camera"
            font.family: "Arial"
            style: Text.Normal
            wrapMode: Text.NoWrap
            font.pixelSize: 76
            verticalAlignment: Text.AlignVCenter
            textFormat: Text.AutoText
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
        }

        onClicked: {
            CameraModel.clear()
            Engine.pi_requestCameraInfo();
            ScreenManager.toCameraScr();
        }
    }

    HSS_Button {
        id: button_DoorBell
        x: 190
        y: 960
        width: 700
        height: 200
        color: "#005fbf"
        antialiasing: false
        transformOrigin: Item.Center

        Text {
            id:textDoorBell
            width: 352
            height: 127
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Door Bell"
            font.family: "Arial"
            style: Text.Normal
            wrapMode: Text.NoWrap
            font.pixelSize: 76
            verticalAlignment: Text.AlignVCenter
            textFormat: Text.AutoText
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
        }

        onClicked: {
            ScreenManager.toDoorBellScr();
        }
    }

    HSS_Button {
        id: buttonSetting
        x: 190
        y: 1230
        width: 700
        height: 200
        color: "#005fbf"
        antialiasing: false
        transformOrigin: Item.Center

        Text {
            id:textSetting
            width: 352
            height: 127
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Setting"
            font.family: "Arial"
            style: Text.Normal
            wrapMode: Text.NoWrap
            font.pixelSize: 76
            verticalAlignment: Text.AlignVCenter
            textFormat: Text.AutoText
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
        }

        onClicked: {
            Engine.pi_requestSettingStt()
            ScreenManager.toSettingScr();
        }
    }

}

