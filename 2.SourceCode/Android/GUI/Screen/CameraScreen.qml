import QtQuick 2.5

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

        HSS_Button {
            id: backButton
            x: 25
            y: 25
            width: 150
            height: 150
            source: "qrc:/img/back.png"
			
			onClicked: {
            ScreenManager.cameraToMainScr()
			}
        }

        Text {
            id: mainHeadline
            x: 285
            y: 49
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("Camera")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }


}

