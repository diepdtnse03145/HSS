#include "hssengine.h"
#include "Connection/rpc_pr.h"
#include <QtQml>

HSSEngine::HSSEngine(QObject *parent):
    ConnectionBase{parent}
{
    _engine.rootContext()->setContextProperty("ScreenManager", &_scrMng);
    _engine.rootContext()->setContextProperty("Engine", this);
}

void HSSEngine::run()
{
    connectToHost("localhost", 13);

    _engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(&_scrMng,&ScreenManager::currentScreenChanged,[this](QUrl source){
        QMetaObject::invokeMethod(_engine.rootObjects().at(0), "loadScreen",
                                  Q_ARG(QVariant, source));
    });
    _scrMng.run();

}

void HSSEngine::pi_requestLogin(const QString &username, const QString &pwd)
{
    QString msg = QStringLiteral("pi_requestLogin %1 %2\n")
            .arg(stringToMsgArg(username))
            .arg(stringToMsgArg(pwd));
    _sendMsg(msg);
}

void HSSEngine::pi_changePassword(const QString &username, const QString &oldpwd, const QString &newpwd)
{
    QString msg = QStringLiteral("pi_changePassword %1 %2 %3\n")
            .arg(stringToMsgArg(username))
            .arg(stringToMsgArg(oldpwd))
            .arg(stringToMsgArg(newpwd));
    _sendMsg(msg);
}

void HSSEngine::pi_enableDetectMotion(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectMotion %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_enableSystemStatus(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableSystemStatus %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_enableDetectDoor(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectDoor %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_enableDoorBell(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDoorBell %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_requestDoorStatus()
{
    QString msg = QStringLiteral("pi_requestDoorStatus\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestMotionStatus()
{
    QString msg = QStringLiteral("pi_requestMotionStatus\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestBellStatus()
{
    QString msg = QStringLiteral("pi_requestBellStatus\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestCameraInfo()
{
    QString msg = QStringLiteral("pi_requestCameraInfo\n");
    _sendMsg(msg);
}

void HSSEngine::_hss_recvMsg(const QString &msg)
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
        QString and_returnCameraInfo_arg1 = msgArgToString(v.at(1));
        and_returnCameraInfo(and_returnCameraInfo_arg1);
    }

}

void HSSEngine::and_loginResult(bool result)
{
    _scrMng.toMainScr();
}

void HSSEngine::and_changePwResult(bool result)
{
    _scrMng.toLoginScr();
}

void HSSEngine::and_returnDoorStatus(int status)
{

}

void HSSEngine::and_returnMotionStatus(int status)
{

}

void HSSEngine::and_returnBellStatus(int status)
{

}

void HSSEngine::and_returnCameraInfo(const QString &cameraUrl)
{

}

