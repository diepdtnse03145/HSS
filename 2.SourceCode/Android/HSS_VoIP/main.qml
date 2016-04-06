import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Label {
        id: t
        text: qsTr("Hello World")
//        anchors.centerIn: parent
        x: 300
        y: 0
    }

    NumberAnimation {
        loops: Animation.Infinite
        running: true
        target: t
        property: "y"
        duration: 2000
        easing.type: Easing.InOutQuad
        from: 0
        to: 400
    }


    MouseArea {
        anchors.fill: parent
        onClicked: {
            engine.MoeMoe()
        }
    }
}
