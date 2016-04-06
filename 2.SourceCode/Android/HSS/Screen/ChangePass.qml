import QtQuick 2.5
import QtQuick.Controls 1.4
import "../Component"

ScreenBase{
    id:root

    onBackKeyCaptured: {
        backButton.clicked()
    }

    Rectangle {
        id: title
        x: 0
        y: 0
        width: 1080
        height: 200
        color: "#005fbf"

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
                ScreenManager.toSettingScr();
            }
        }

        Text {
            id: textHeadlineChangePassword
            x: 285
            y: 49
            width: 510
            height: 102
            color: "#ffffff"
            text: qsTr("Change Password")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 80
        }
    }


    Text {
        id: textOldPwd
        x: 92
        y: 227
        width: 691
        height: 98
        text: qsTr("Enter Old Password:")
        wrapMode: Text.NoWrap
        font.pixelSize: 80

        TextField {
            id: inputOldPwd
            x: 0
            y: 121
            width: 906
            height: 113
            text: qsTr("")
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            echoMode: TextInput.Password
            font.pixelSize: 80
        }
    }


    Text {
        id: textNewPwd
        x: 92
        y: 501
        width: 691
        height: 98
        text: qsTr("Enter New Password:")
        wrapMode: Text.NoWrap
        font.pixelSize: 80

        TextField {
            id: inputNewPwd
            x: 0
            y: 121
            width: 906
            height: 113
            text: qsTr("")
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            echoMode: TextInput.Password
            font.pixelSize: 80
        }
    }

    Text {
        id: textConfirmPwd
        x: 92
        y: 772
        width: 691
        height: 98
        text: qsTr("Confirm New Password:")
        wrapMode: Text.NoWrap
        font.pixelSize: 80

        TextField {
            id: inputConfirmPwd
            x: 0
            y: 121
            width: 906
            height: 113
            text: qsTr("")
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            echoMode: TextInput.Password
            font.pixelSize: 80
        }
    }

    HSS_Button {
        id: buttonChangePwd
        x: 240
        y: 1067
        width: 600
        height: 150
        color: "#005fbf"
        anchors.right: parent.right
        anchors.rightMargin: 240

        Text {
            id:textChangePwd
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Change"
            font.pointSize: 25
        }

        onClicked: {
            Engine.pi_changePassword(Engine.username, textOldPwd.text, inputConfirmPwd.text)
        }
    }
}

