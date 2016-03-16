import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: root
    visible: true
    width:1080
    height:1860
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        color: "blue"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                onscrAnimation.running = true
            }
        }
    }

    HSS_Onscr{
        id: hss_onscr
        width: 930
        height: 100
        x: 75
        y: 1250
    }

    ParallelAnimation{
        id: onscrAnimation
        running: false

        NumberAnimation {
            target: hss_onscr
            property: "y"
            from: root.height / 4 * 5
            to: 1250
            duration: 200
            easing.type: Easing.InOutQuad
        }
    }
}
