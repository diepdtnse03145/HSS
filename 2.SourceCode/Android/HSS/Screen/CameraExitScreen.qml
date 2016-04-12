import QtQuick 2.5
import "../Component"

ScreenBase{
    id:root

    color: "transparent"

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
                ScreenManager.toCameraScr()
            }
        }
    }
    Component.onCompleted: {
        ScreenManager.toCameraScr()
    }
}

