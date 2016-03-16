#include "piengine.h"
#include "../rpc_pr.h"

PiEngine::PiEngine(QObject *parent):
    ConnectionBase{parent}
{

}

void PiEngine::pi_requestLogin(const QString &username, const QString &pwd)
{
    QString msg = QStringLiteral("pi_requestLogin %1 %2\n")
            .arg(stringToMsgArg(username))
            .arg(stringToMsgArg(pwd));
    _sendMsg(msg);
}

void PiEngine::pi_changePassword(const QString &username, const QString &oldpwd, const QString &newpwd)
{
    QString msg = QStringLiteral("pi_changePassword %1 %2 %3\n")
            .arg(stringToMsgArg(username))
            .arg(stringToMsgArg(oldpwd))
            .arg(stringToMsgArg(newpwd));
    _sendMsg(msg);
}

void PiEngine::pi_enableDetectMotion(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectMotion %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_enableSystemStatus(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableSystemStatus %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_enableDetectDoor(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectDoor %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_enableDoorBell(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDoorBell %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_requestDoorStatus()
{
    QString msg = QStringLiteral("pi_requestDoorStatus\n");
    _sendMsg(msg);
}

void PiEngine::pi_requestMotionStatus()
{
    QString msg = QStringLiteral("pi_requestMotionStatus\n");
    _sendMsg(msg);
}

void PiEngine::pi_requestBellStatus()
{
    QString msg = QStringLiteral("pi_requestBellStatus\n");
    _sendMsg(msg);
}

void PiEngine::pi_requestCameraInfo()
{
    QString msg = QStringLiteral("pi_requestCameraInfo\n");
    _sendMsg(msg);
}

void PiEngine::_hss_recvMsg(const QString &msg)
{
    auto v = msg.split(QRegExp{R"mm(\s+)mm"}, QString::SkipEmptyParts);

    if (v.at(0) == "and_changePwResult") {
        bool and_changePwResult_arg1 = msgArgToBool(v.at(1));
        and_changePwResult(and_changePwResult_arg1);
    }

    if (v.at(0) == "and_loginResult") {
        bool and_loginResult_arg1 = msgArgToBool(v.at(1));
        and_loginResult(and_loginResult_arg1);
    }

    if (v.at(0) == "and_changePwResult") {
        bool and_changePwResult_arg1 = msgArgToBool(v.at(1));
        and_changePwResult(and_changePwResult_arg1);
    }

    if (v.at(0) == "and_returnDoorStatus") {
        int and_returnDoorStatus_arg1 = msgArgToInt(v.at(1));
        and_returnDoorStatus(and_returnDoorStatus_arg1);
    }

    if (v.at(0) == "and_returnMotionStatus") {
        bool and_returnMotionStatus_arg1 = msgArgToInt(v.at(1));
        and_returnMotionStatus(and_returnMotionStatus_arg1);
    }

    if (v.at(0) == "and_returnBellStatus") {
        bool and_returnBellStatus_arg1 = msgArgToInt(v.at(1));
        and_returnBellStatus(and_returnBellStatus_arg1);
    }

    if (v.at(0) == "and_returnCameraInfo") {
        QString and_returnCameraInfo_arg1 = msgArgToInt(v.at(1));
        and_returnCameraInfo(and_returnCameraInfo_arg1);
    }

}

void PiEngine::and_loginResult(bool result)
{

}

void PiEngine::and_changePwResult(bool result)
{

}

void PiEngine::and_returnDoorStatus(int status)
{

}

void PiEngine::and_returnMotionStatus(int status)
{

}

void PiEngine::and_returnBellStatus(int status)
{

}

void PiEngine::and_returnCameraInfo(const QString &cameraUrl)
{

}

