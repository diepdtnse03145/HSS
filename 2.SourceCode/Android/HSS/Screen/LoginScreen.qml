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
        y: 608
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
        y: 736
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
        x: 279
        y: 95
        width: 521
        height: 447
        fillMode: Image.Stretch
        source: "qrc:/img/logo.png"
    }

    Image {
        id: image_User
        x: 75
        y: 608
        width: 113
        height: 113
        source: "qrc:/img/user.png"
    }

    Image {
        id: image_Pass
        x: 88
        y: 736
        width: 92
        height: 113
        source: "qrc:/img/pass.png"
    }

    HSS_Button {
        id: buttonLogin
        x: 270
        y: 897
        width: 600
        height: 150
        color: "#005fbf"

        Text {
            id:textLogin
            anchors.fill: parent
            color: "#ffffff"
            text: "Login"
            anchors.rightMargin: 0
            anchors.bottomMargin: -8
            anchors.leftMargin: 0
            anchors.topMargin: 8
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 30
        }

        onClicked: {
            Engine.pi_requestLogin(input_user.text, input_pass.text)
        }
    }
}

