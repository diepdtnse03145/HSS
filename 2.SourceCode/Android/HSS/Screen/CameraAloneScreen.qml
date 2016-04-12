import QtQuick 2.5
import QtQuick.Controls 1.4

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
                ScreenManager.toCameraExitScr()
                cameraLoader.source = ""
                cameraLoader.visible = false
            }
        }
        
        
        Text {
            id: mainHeadline
            x: 274
            y: 49
            width: 533
            height: 102
            color: "#ffffff"
            text: qsTr("Camera Viewer")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }


        Rectangle {
            id: rectangle2
            x: 0
            y: 1583
            width: 1080
            height: 277
            color: "#ffffff"
        }
    }

    Text {
        id: statusCameraIDText
        x: 29
        y: 1617
        width: 477
        height: 84
        text: qsTr("Camera ID:")
        font.pixelSize: 70

        Text {
            id: statusCameraID
            x: 482
            y: 0
            width: 372
            height: 84
            color: "#e50c0c"
            text: qsTr("1")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 70
        }
    }


    Text {
        id: statusCameraIPText
        x: 29
        y: 1739
        width: 477
        height: 84
        text: qsTr("Connection IP:")
        font.pixelSize: 70

        Text {
            id: statusCameraIP
            x: 482
            y: 0
            width: 508
            height: 84
            color: "#e50c0c"
            text: qsTr("192.168.125.51")
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 70
            verticalAlignment: Text.AlignVCenter
        }
    }


    Loader{
        id: cameraLoader
        x: 0
        y: 200
        width: root.width
        height: 1384
        source: "qrc:/Component/HSS_CameraView.qml"
    }
}

