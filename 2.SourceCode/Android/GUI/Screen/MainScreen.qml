import QtQuick 2.5
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
        y: 422
        width: 700
        height: 200
        color: "#005fbf"
        anchors.right: parent.right
        anchors.rightMargin: 190

        Text {
            id:textActivityLog
            width: 352
            height: 127
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Activity Log"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
            font.pointSize: 62
        }

        onClicked: {
            ScreenManager.mainToActivityLogScr()
        }
    }

    HSS_Button {
        id: buttonCamera
        x: 190
        y: 689
        width: 700
        height: 200
        color: "#005fbf"
        anchors.rightMargin: 190
        anchors.right: parent.right
		
        Text {
            id: textCamera
            width: 352
            height: 127
            color: "#ffffff"
            text: "Camera"
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 62
        }
		
		onClicked: {
            ScreenManager.mainToCameraScr()
        }
    }

    HSS_Button {
        id: button_DoorBell
        x: 190
        y: 956
        width: 700
        height: 200
        color: "#005fbf"
        anchors.rightMargin: 190
        anchors.right: parent.right
		
        Text {
            id: textDoorBell
            width: 352
            height: 127
            color: "#ffffff"
            text: "Door Bell"
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 62
        }
		
		onClicked: {
            ScreenManager.mainToDoorBellScr()
        }
    }

    HSS_Button {
        id: buttonSetting
        x: 190
        y: 1223
        width: 700
        height: 200
        color: "#005fbf"
        anchors.rightMargin: 190
        anchors.right: parent.right
		
        Text {
            id: textSetting
            width: 352
            height: 127
            color: "#ffffff"
            text: "Setting"
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 62
        }
		
		onClicked: {
            ScreenManager.mainToSettingScr()
        }
    }

}

