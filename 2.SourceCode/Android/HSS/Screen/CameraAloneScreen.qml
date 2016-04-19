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
    }

    Loader{
        id: cameraLoader
        x: 0
        y: 200
        width: root.width
        height: 1660
        source: "qrc:/Component/HSS_CameraView.qml"
    }
}

