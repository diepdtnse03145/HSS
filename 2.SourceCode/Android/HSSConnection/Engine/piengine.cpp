#include "piengine.h"
#include "../rpc_pr.h"

PiEngine::PiEngine(QObject *parent):
    ConnectionBase{parent}
{

}

void PiEngine::pi_changePassword(const QString &oldpwd, const QString &newpwd)
{
    QString msg = QStringLiteral("pi_changePassword %1\n")
            .arg(stringToMsgArg(oldpwd))
            .arg(stringToMsgArg(newpwd));
    _sendMsg(msg);
}

void PiEngine::pi_enableDetectMotion(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectMotion %1\n").arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_enableSystemStatus(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableSystemStatus %1\n").arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_enableDetectDoor(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectDoor %1\n").arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::pi_enableDoorBell(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDoorBell %1\n").arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void PiEngine::_hss_recvMsg(const QString &msg)
{
    auto v = msg.split(QRegExp{R"mm(\s+)mm"}, QString::SkipEmptyParts);

    if (v.at(0) == "and_changePwResult") {
        bool and_changePwResult_arg1 = msgArgToBool(v.at(1));
        and_changePwResult(and_changePwResult_arg1);
    }

}

void PiEngine::and_changePwResult(bool result)
{

}
