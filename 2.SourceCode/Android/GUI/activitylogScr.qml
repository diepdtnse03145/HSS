import QtQuick 2.5

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
            text: qsTr("Activity Log")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }



}

