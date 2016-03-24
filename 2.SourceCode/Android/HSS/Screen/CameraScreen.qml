import QtQuick 2.5
import "../Component"

Rectangle{
    id:root
    width:1080
    height:1860

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
            text: qsTr("Camera IP List")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
        
    }
    
    Rectangle {
        id: addCameraButton
        x: 0
        y: 1505
        width: 1080
        height: 200
        color: "#005fbf"

        Text {
            id: addCameraText
            x: 285
            y: 54
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("Add Camera")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
            verticalAlignment: Text.AlignVCenter
        }


    }


}

