import QtQuick 2.5

Rectangle{
    width: 1080
    height: 1920
    color: "#fafafc"
    border.color: "#00000000"


    
    Text {
        id: text1
        x: 280
        y: 558
        width: 584
        height: 134
        color: "#3551dc"
        text: qsTr("Home Security System")
        horizontalAlignment: Text.AlignHCenter
        font.bold: false
        font.family: "Times New Roman"
        verticalAlignment: Text.AlignVCenter
        opacity: 1
        font.pixelSize: 50
    }

    Image {
        id: image2
        x: 360
        y: 224
        width: 360
        height: 318
        source: "../../Desktop/New folder/images.jpg"
    }

    TextEdit {
        id: textEdit1
        x: 351
        y: 874
        width: 442
        height: 92
        text: qsTr("Text Edit")
        font.pixelSize: 12

        Item {
            id: item1
            anchors.fill: parent
            opacity: 0
        }
    }
    TextEdit {
        id: textEdit2
        x: 351
        y: 978
        width: 442
        height: 92
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    Image {
        id: image1
        x: 192
        y: 870
        width: 100
        height: 100
        opacity: 0
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Image {
        id: image4
        x: 192
        y: 1022
        width: 100
        height: 100
        opacity: 0
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Text {
        id: text2
        x: 446
        y: 1083
        text: qsTr("Text")
        font.pixelSize: 12
        opacity: 0
    }
    states: [
        State {
            name: "State3"

            PropertyChanges {
                target: image1
                source: "../../Desktop/New folder/images.png"
                opacity: 1
            }

            PropertyChanges {
                target: textEdit2
                x: 351
                y: 1026
                selectionColor: "#0d0df7"
            }

            PropertyChanges {
                target: image4
                source: "../../Desktop/New folder/tải xuống.jpg"
                opacity: 1
            }

            PropertyChanges {
                target: textEdit1
                selectionColor: "#0e09f6"
            }

            PropertyChanges {
                target: item1
                width: 155
                height: 62
                anchors.rightMargin: 101
                anchors.bottomMargin: -253
                anchors.leftMargin: 101
                anchors.topMargin: 284
                opacity: 1
            }

            PropertyChanges {
                target: text2
                x: 528
                y: 1177
                width: 84
                height: 29
                text: qsTr("Log in")
                opacity: 1
            }
        },
        State {
            name: "State1"
        },
        State {
            name: "State2"
        },
        State {
            name: "State4"
        }
    ]
    
}

