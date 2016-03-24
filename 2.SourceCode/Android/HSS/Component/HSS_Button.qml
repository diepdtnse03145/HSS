import QtQuick 2.5

Rectangle {
    id: root
    signal clicked()
    MouseArea {
        anchors.fill: root
        onClicked: {
            root.clicked()
        }
    }
}
