import QtQuick 2.5
import QtQuick.Controls 1.3
import "../Component"

Rectangle{
    id:root
    width:1080
    height:1860

    TextInput {
        id: input_user
        x: 261
        y: 978
        width: 737
        height: 113
        text: qsTr("Username")
        inputMask: "Username"
        font.family: "Tahoma"
        horizontalAlignment: Text.AlignLeft
        echoMode: TextInput.Normal
        font.pixelSize: 80
    }

    TextInput {
        id: input_pass
        x: 261
        y: 1106
        width: 737
        height: 113
        text: qsTr("")
        horizontalAlignment: Text.AlignLeft
        font.family: "Tahoma"
        echoMode: TextInput.Password
        inputMask: "Password"
        font.pixelSize: 80
    }

    Image {
        id: image_Logo
        x: 217
        y: 286
        width: 646
        height: 536
        fillMode: Image.Stretch
        source: "qrc:/img/logo.png"
    }

    Image {
        id: image_User
        x: 75
        y: 978
        width: 113
        height: 113
        source: "qrc:/img/user.png"
    }

    Image {
        id: image_Pass
        x: 88
        y: 1106
        width: 92
        height: 113
        source: "qrc:/img/pass.png"
    }

    HSS_Button {
        id: buttonLogin
        x: 358
        y: 1310
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
            ScreenManager.loginToMainScr()
        }
    }

}
