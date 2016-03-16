#ifndef PIENGINE_H
#define PIENGINE_H

#include "../Connection/connectionbase.h"

class PiEngine : public ConnectionBase
{
public:
    PiEngine(QObject* parent = 0);

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
};

#endif // PIENGINE_H
