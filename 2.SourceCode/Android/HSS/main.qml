import QtQuick 2.5
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id:root
    width:1080
    height:1860
    visible: true

    function loadScreen(screenSource) {
        prev.source = next.source
        next.source = screenSource
        startChangeScreen()
    }

    function startChangeScreen() {
        screenChange.restart()
    }

    function backKeyCaptured() {
        if (ScreenManager.isLogin) {
            next.item.backKeyCaptured()
            return
        }
        loginLoader.item.backKeyCaptured()
    }

    Loader{
        id: prev
    }

    Loader{
        id: next
    }

    Loader{
        id: loginLoader
        source: ScreenManager.isLogin ? "" : "qrc:/Screen/LoginScreen.qml"
    }

    ParallelAnimation {
        id: screenChange
        running: false

        PropertyAnimation {
            id: prevAni
            target: prev
            property: "x"
            from: 0
            to: - root.width
            easing.type: Easing.InCubic
            duration: 500
        }

        PropertyAnimation {
            id: nexAni
            target: next
            property: "x"
            from: root.width
            to: 0
            easing.type: Easing.InCubic
            duration: 500
        }
    }
}
