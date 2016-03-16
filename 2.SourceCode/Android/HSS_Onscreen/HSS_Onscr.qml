import QtQuick 2.5

Item{
    id: root

    Rectangle{
        id: bgr
        color: "black"
        anchors.centerIn: text
        opacity: 0.5
        width: text.contentWidth + 20
        height: text.contentHeight + 20
        radius: 7
    }

    Text {
        id: text
        text: qsTr("Camera not found")
        color: "white"
        wrapMode: Text.Wrap
        opacity: 1
        anchors.fill: root
        z: root.z + 9
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

}




