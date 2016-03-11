import QtQuick 2.5

Rectangle{
    id:root
    width:1080
    height:1860

    Rectangle {
        id: title
        x: 0
        y: 0
        width: 1080
        height: 200
        color: "#005fbf"

        HSS_Button {
            id: backButton
            x: 25
            y: 25
            width: 150
            height: 150
            source: "qrc:/img/back.png"
			
			onClicked: {
            ScreenManager.changePassToSetiingScr()
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

    Image {
        id: imageUser
        x: 75
        y: 307
        width: 113
        height: 113
        source: "qrc:/img/user.png"
    }

    TextInput {
        id: input_user
        x: 261
        y: 307
        width: 737
        height: 113
        text: qsTr("Username")
        inputMask: "Username"
        font.family: "Tahoma"
        horizontalAlignment: Text.AlignLeft
        echoMode: TextInput.Normal
        font.pixelSize: 80
    }

    Text {
        id: textOldPwd
        x: 92
        y: 524
        width: 691
        height: 98
        text: qsTr("Enter Old Password:")
        wrapMode: Text.NoWrap
        font.pixelSize: 80

        TextInput {
            id: inputOldPwd

            x: 0
            y: 121
            width: 906
            height: 113
            text: qsTr("")
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            echoMode: TextInput.Password
            inputMask: "Password"
            font.pixelSize: 80
        }
    }


    Text {
        id: textNewPwd
        x: 92
        y: 792
        width: 691
        height: 98
        text: qsTr("Enter New Password:")
        wrapMode: Text.NoWrap
        font.pixelSize: 80

        TextInput {
            id: inputNewPwd
            x: 0
            y: 121
            width: 906
            height: 113
            text: qsTr("")
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            echoMode: TextInput.Password
            inputMask: "Password"
            font.pixelSize: 80
        }
    }

    Text {
        id: textConfirmPwd
        x: 92
        y: 1075
        width: 691
        height: 98
        text: qsTr("Confirm New Password:")
        wrapMode: Text.NoWrap
        font.pixelSize: 80

        TextInput {
            id: inputConfirmPwd
            x: 0
            y: 121
            width: 906
            height: 113
            text: qsTr("")
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            echoMode: TextInput.Password
            inputMask: "Password"
            font.pixelSize: 80
        }
    }

    HSS_Button {
        id: buttonChangePwd
        x: 358
        y: 1743
        width: 363
        height: 100
        color: "#005fbf"
        anchors.right: parent.right
        anchors.rightMargin: 359

        Text {
            id:textChangePwd
            width: 148
            height: 65
            color: "#ffffff"
            anchors.centerIn: parent
            text: "Change"
            font.pointSize: 40
        }
    }

}

