#ifndef ANDROIDENGINE_H
#define ANDROIDENGINE_H

#include "../Connection/tcpconnection.h"
#include "../Connection/hsspushable.h"

class ArduinoEngine;

class AndroidEngine : public TcpConnection, public HSSPushable
{
public:
    AndroidEngine(Setting& setting,
                  HSSDatabase& db,
                  boost::asio::io_service& io);

    void setArduinoEngine(ArduinoEngine* engine);

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_enableDetectMotionResult(bool result);
    void and_enableDetectDoorResult(bool result);
    void and_enableDoorBellResult(bool result);

    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);
    void and_appendCameraInfo(const std::string& cameraName, const std::string& cameraUrl);

private:
    ArduinoEngine* _ard;

    void _hss_recvMsg(const std::string &msg) override final;

    void pi_requestLogin(const std::string& username,
                         const std::string& pwd);
    void pi_changePassword(const std::string& username,
                           const std::string& oldpwd,
                           const std::string& newpwd);
    void pi_enableDetectMotion(bool enable);
    void pi_enableDetectDoor(bool enable);
    void pi_enableDoorBell(bool enable);
    void pi_requestDoorStatus();
    void pi_requestMotionStatus();
    void pi_requestBellStatus();
    void pi_requestCameraInfo();
};

#endif // ANDROIDENGINE_H
