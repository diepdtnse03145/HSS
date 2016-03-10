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

        Image {
            id: backButton
            x: 25
            y: 25
            width: 150
            height: 150
            source: "qrc:/img/back.png"
        }

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
        id: buttonLogin
        x: 190
        y: 422
        width: 700
        height: 200
        color: "#005fbf"
        anchors.right: parent.right
        anchors.rightMargin: 190

        Text {
            id:textLogin
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

    Rectangle {
        id: buttonLogin1
        x: 190
        y: 689
        width: 700
        height: 200
        color: "#005fbf"
        anchors.rightMargin: 190
        anchors.right: parent.right
        Text {
            id: textLogin1
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
    }

    Rectangle {
        id: buttonLogin2
        x: 190
        y: 956
        width: 700
        height: 200
        color: "#005fbf"
        anchors.rightMargin: 190
        anchors.right: parent.right
        Text {
            id: textLogin2
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
    }

    Rectangle {
        id: buttonLogin3
        x: 190
        y: 1223
        width: 700
        height: 200
        color: "#005fbf"
        anchors.rightMargin: 190
        anchors.right: parent.right
        Text {
            id: textLogin3
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
    }

}

