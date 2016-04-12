#ifndef ANDROIDENGINE_H
#define ANDROIDENGINE_H

#include "../Connection/tcpconnection.h"

class ArduinoEngine;
class HSSPushable;

class AndroidEngine : public TcpConnection
{
public:
    AndroidEngine(Setting& setting,
                  HSSDatabase& db,
                  HSSPushable& pushsv,
                  boost::asio::io_service& io);

    void setArduinoEngine(ArduinoEngine* engine);

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_enableDetectMotionResult(bool result);
    void and_enableDetectDoorResult(bool result, bool isDoorClosed);
    void and_enableDoorBellResult(bool result);

    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);
    void and_returnCameraInfo(const std::string& cameraInfo);
    void and_returnActivityLog(const std::string& log);
    void and_deleteActitvityLogResult(bool result);
    void and_returnCallAdd(const std::string &address);
    void and_returnSettingStt(bool dtMotion, bool dtDoor, bool bell);

private:
    ArduinoEngine* _ard;
    HSSPushable& _pushsv;
    void pushMessage(std::string msg);

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
    void pi_requestActivityLog();
    void pi_deleteActitvityLog();
    void pi_requestCallAdd();
    void pi_requestSettingStt();

};

#endif // ANDROIDENGINE_H
