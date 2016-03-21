#ifndef HSSENGINE_H
#define HSSENGINE_H

#include "ScreenManager/ScreenManager.h"
#include "Connection/connectionbase.h"
#include <QQmlApplicationEngine>

class HSSEngine : public ConnectionBase
{
public:
    HSSEngine(QObject* parent = 0);
    void run();

public slots:
    void pi_requestLogin(const QString& username,
                         const QString& pwd);
    void pi_changePassword(const QString& username,
                           const QString& oldpwd,
                           const QString& newpwd);
    void pi_enableDetectMotion(const bool& enable);
    void pi_enableSystemStatus(const bool& enable);
    void pi_enableDetectDoor(const bool& enable);
    void pi_enableDoorBell(const bool& enable);

    void pi_requestDoorStatus();
    void pi_requestMotionStatus();
    void pi_requestBellStatus();
    void pi_requestCameraInfo();

private:
    void _hss_recvMsg(const QString &msg) override;

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);
    void and_returnCameraInfo(const QString& cameraUrl);


private:
    QQmlApplicationEngine _engine;
    ScreenManager _scrMng;
};

#endif // HSSENGINE_H
