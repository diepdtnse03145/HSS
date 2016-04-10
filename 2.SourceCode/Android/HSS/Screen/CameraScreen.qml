import QtQuick 2.5
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
            text: qsTr("Camera IP List")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
        
    }
    

    ListView {
        id: listView1
        x: 0
        y: 200
        width: 1080
        height: 1660
        clip: true
        delegate: Item {
            width: 1080
            height: 150
            Rectangle {
                anchors.fill: parent
                color: "steelblue"
            }
            Rectangle{
                anchors.fill: parent
                anchors.bottomMargin: 1
                Text {
                    x: 20
                    y: 0
                    width: 1080
                    height: 150
                    text: name
                    font.pointSize: 22
                    color: "darkblue"
                    verticalAlignment: Text.AlignVCenter
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Engine.cameraUrl = url
                    console.debug(Engine.cameraUrl)
                    ScreenManager.toCameraViewScr()
                }
            }
        }
        model: CameraModel
    }
}

