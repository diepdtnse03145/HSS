import QtQuick 2.5
import QtQuick.Controls 1.3
import "../Component"

Rectangle{
    id:root
    width:1080
    height:1860

    TextInput {
        id: inputIP
        x: 50
        y: 278
        width: 949
        height: 113
        text: qsTr("")
        inputMask: "IP of Server"
        font.family: "Tahoma"
        horizontalAlignment: Text.AlignHCenter
        echoMode: TextInput.Normal
        font.pixelSize: 80
    }

    HSS_Button {
        id: buttonLogin
        x: 359
        y: 458
        width: 363
        height: 100
        color: "#005fbf"

        Text {
            id:textLogin
            anchors.fill: parent
            color: "#ffffff"
            text: "Login"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 40
        }

        onClicked: {
            ScreenManager.toLoginScr()
        }
    }

}

