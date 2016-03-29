import QtQuick 2.5
import "../Component"

ScreenBase{
    id:root

    onBackKeyCaptured: {
        backButton.clicked()
    }

    Rectangle {
        id: rectangle1
        height: 200
        color: "#005fbf"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.left: parent.left

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
            text: qsTr("Activity Log")
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
                    anchors.fill: parent
                    text: qsTr("text")
                }
            }
        }
        model: ActivityModel
    }

    //    Rectangle {
    //        id: deleteActivityLogButton
    //        x: 0
    //        y: 1505
    //        width: 1080
    //        height: 200
    //        color: "#d0150a"

    //        Text {
    //            id: deleteActivityLogText
    //            x: 285
    //            y: 54
    //            width: 510
    //            height: 102
    //            color: "#ffffff"
    //            text: qsTr("Delete Activity Log")
    //            horizontalAlignment: Text.AlignHCenter
    //            font.pixelSize: 80
    //            verticalAlignment: Text.AlignVCenter
    //        }
    //    }
}

