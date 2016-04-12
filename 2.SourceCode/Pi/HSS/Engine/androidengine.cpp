#include "androidengine.h"
#include "../rpc_pr.h"
#include "../hss_global.h"
#include "arduinoengine.h"
#include "../Connection/hsspushable.h"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <cppformat/format.h>

AndroidEngine::AndroidEngine(Setting &setting,
                             HSSDatabase &db,
                             HSSPushable &pushsv,
                             boost::asio::io_service &io) :
    TcpConnection{setting, db, io},
    _pushsv{pushsv}
{

}

void AndroidEngine::setArduinoEngine(ArduinoEngine *engine)
{
    _ard = engine;
}

void AndroidEngine::and_loginResult(bool result)
{
    std::string msg = fmt::format("and_loginResult {0}\n", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_changePwResult(bool result)
{
    std::string msg = fmt::format("and_changePwResult {0}\n", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_enableDetectMotionResult(bool result)
{
    std::string msg = fmt::format("and_enableDetectMotionResult {0}\n", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_enableDetectDoorResult(bool result, bool isDoorClosed)
{
    std::string msg = fmt::format("and_enableDetectDoorResult {0} {1}\n",
                                  boolToMsgArg(result),
                                  boolToMsgArg(isDoorClosed)
                                  );
    _sendMsg(msg);
}

void AndroidEngine::and_enableDoorBellResult(bool result)
{
    std::string msg = fmt::format("and_enableDoorBellResult {0}\n", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_returnDoorStatus(int status)
{
    std::string msg = fmt::format("and_returnDoorStatus {0}\n", intToMsgArg(status));
    _sendMsg(msg);
}

void AndroidEngine::and_returnMotionStatus(int status)
{
    std::string msg = fmt::format("and_returnMotionStatus {0}\n", intToMsgArg(status));
    _sendMsg(msg);
}

void AndroidEngine::and_returnBellStatus(int status)
{
    std::string msg = fmt::format("and_returnBellStatus {0}\n", intToMsgArg(status));
    _sendMsg(msg);
}

void AndroidEngine::and_returnCameraInfo(const std::string &cameraInfo)
{
    std::string msg = fmt::format("and_returnCameraInfo {0}\n",
                                  stringToMsgArg(cameraInfo));
    _sendMsg(msg);
}

void AndroidEngine::and_returnActivityLog(const std::string &log)
{
    std::string msg = fmt::format("and_returnActivityLog {0}\n",
                                  stringToMsgArg(log));
    _sendMsg(msg);
}

void AndroidEngine::and_deleteActitvityLogResult(bool result)
{
    std::string msg = fmt::format("and_deleteActitvityLogResult {0}\n", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_returnCallAdd(const std::string &address)
{
    std::string msg = fmt::format("and_returnCallAdd {0}\n", stringToMsgArg(address));
    _sendMsg(msg);
}

void AndroidEngine::and_returnSettingStt(bool dtMotion, bool dtDoor, bool bell)
{
    std::string msg = fmt::format("and_returnSettingStt {0} {1} {2}\n",
                                  boolToMsgArg(dtMotion),
                                  boolToMsgArg(dtDoor),
                                  boolToMsgArg(bell)
                                  );
    _sendMsg(msg);
}

void AndroidEngine::pushMessage(std::string msg)
{
    _pushsv.pushMessage(msg);
}

void AndroidEngine::_hss_recvMsg(const std::string &msg)
{
    std::vector<std::string> vec;
    boost::split(vec, msg, boost::is_any_of(" \r\n"), boost::token_compress_on);

    if(vec.at(0) == "pi_requestLogin") {
        std::string pi_requestLogin_arg1 = msgArgToString(vec.at(1));
        std::string pi_requestLogin_arg2 = msgArgToString(vec.at(2));

        pi_requestLogin(pi_requestLogin_arg1,
                          pi_requestLogin_arg2);
    }

    if(vec.at(0) == "pi_changePassword") {
        std::string pi_changePassword_arg1 = msgArgToString(vec.at(1));
        std::string pi_changePassword_arg2 = msgArgToString(vec.at(2));
        std::string pi_changePassword_arg3 = msgArgToString(vec.at(3));

        pi_changePassword(pi_changePassword_arg1,
                          pi_changePassword_arg2,
                          pi_changePassword_arg3);
    }

    if(vec.at(0) == "pi_enableDetectMotion") {
        bool pi_enableDetectMotion_arg1 = msgArgToBool(vec.at(1));
        pi_enableDetectMotion(pi_enableDetectMotion_arg1);
    }

    if(vec.at(0) == "pi_enableDetectDoor") {
        bool pi_enableDetectDoor_arg1 = msgArgToBool(vec.at(1));
        pi_enableDetectDoor(pi_enableDetectDoor_arg1);
    }

    if(vec.at(0) == "pi_enableDoorBell") {
        bool pi_enableDoorBell_arg1 = msgArgToBool(vec.at(1));
        pi_enableDoorBell(pi_enableDoorBell_arg1);
    }

    if(vec.at(0) == "pi_requestDoorStatus") {
        pi_requestDoorStatus();
    }

    if(vec.at(0) == "pi_requestMotionStatus") {
        pi_requestMotionStatus();
    }

    if(vec.at(0) == "pi_requestBellStatus") {
        pi_requestBellStatus();
    }

    if(vec.at(0) == "pi_requestCameraInfo") {
        pi_requestCameraInfo();
    }

    if(vec.at(0) == "pi_requestActivityLog") {
        pi_requestActivityLog();
    }

    if(vec.at(0) == "pi_deleteActitvityLog") {
        pi_deleteActitvityLog();
    }

    if(vec.at(0) == "pi_requestCallAdd") {
        pi_requestCallAdd();
    }

    if(vec.at(0) == "pi_requestSettingStt") {
        pi_requestSettingStt();
    }
}

void AndroidEngine::pi_requestLogin(const std::string &username,
                                    const std::string &pwd)
{
    auto loginRes = _db.isUsernamePWDCorrect(username, pwd);
    std::cout<<__FUNCTION__<<" : "<<username<<" : "<<pwd<<" : "<<loginRes<<std::endl;
    and_loginResult(loginRes);
}

void AndroidEngine::pi_changePassword(const std::string &username,
                                      const std::string &oldpwd,
                                      const std::string &newpwd)
{
    auto changePwdRes = _db.changePWD(username, oldpwd, newpwd);
    and_changePwResult(changePwdRes);
}

void AndroidEngine::pi_enableDetectMotion(bool enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_DT_MOTION_ENABLE_SETTING, enable);
    and_enableDetectMotionResult(enable);
}

void AndroidEngine::pi_enableDetectDoor(bool enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_DT_DOOR_ENABLE_SETTING, enable);
    and_enableDetectDoorResult(enable, !!_ard->switchValue());
}

void AndroidEngine::pi_enableDoorBell(bool enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_DOOR_BELL_ENABLE_SETTING, enable);
    and_enableDoorBellResult(enable);
}

void AndroidEngine::pi_requestDoorStatus()
{
    and_returnDoorStatus(_ard->switchValue());
}

void AndroidEngine::pi_requestMotionStatus()
{
    and_returnMotionStatus(_ard->pirValue());
}

void AndroidEngine::pi_requestBellStatus()
{
    and_returnBellStatus(_ard->bellValue());
}

void AndroidEngine::pi_requestCameraInfo()
{
    and_returnCameraInfo(_db.getAllCameraInfo());
}

void AndroidEngine::pi_requestActivityLog()
{
    and_returnActivityLog(_db.getActivityLog());
}

void AndroidEngine::pi_deleteActitvityLog()
{
    and_deleteActitvityLogResult(_db.deleteAllActivityLog());
}

void AndroidEngine::pi_requestCallAdd()
{
    and_returnCallAdd(_getOptionsValue<std::string>(HSS_VOIP_ADRESS));
}

void AndroidEngine::pi_requestSettingStt()
{
    and_returnSettingStt(_getOptionsValue<bool>(HSS_DT_MOTION_ENABLE_SETTING),
                         _getOptionsValue<bool>(HSS_DT_DOOR_ENABLE_SETTING),
                         _getOptionsValue<bool>(HSS_DOOR_BELL_ENABLE_SETTING)
                         );
}
