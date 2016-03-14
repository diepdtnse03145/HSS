#ifndef ANDROIDENGINE_H
#define ANDROIDENGINE_H

#include "../Connection/tcpconnection.h"

class ArduinoEngine;

class AndroidEngine : public TcpConnection
{
public:
    AndroidEngine(Setting& setting, boost::asio::io_service& io);
    void pushNoti(const std::string& msg);    
    void setArduinoEngine(ArduinoEngine* engine);

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);

private:
    ArduinoEngine* _ard;

    void _hss_recvMsg(const std::string &msg) override final;

    void pi_requestLogin(const std::string& username,
                         const std::string& pwd);
    void pi_changePassword(const std::string& username,
                           const std::string& oldpwd,
                           const std::string& newpwd);
    void pi_enableDetectMotion(const bool& enable);
    void pi_enableSystemStatus(const bool& enable);
    void pi_enableDetectDoor(const bool& enable);
    void pi_enableDoorBell(const bool& enable);
    void pi_requestDoorStatus();
    void pi_requestMotionStatus();
    void pi_requestBellStatus();

};

#endif // ANDROIDENGINE_H
