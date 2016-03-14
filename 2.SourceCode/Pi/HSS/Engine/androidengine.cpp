#include "androidengine.h"
#include "../rpc_pr.h"
#include "../hss_global.h"
#include "arduinoengine.h"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <cppformat/format.h>

AndroidEngine::AndroidEngine(Setting &setting, boost::asio::io_service &io) :
    TcpConnection{setting,io}
{

}

void AndroidEngine::pushNoti(const std::string &msg)
{

}

void AndroidEngine::setArduinoEngine(ArduinoEngine *engine)
{
    _ard = engine;
}

void AndroidEngine::and_loginResult(bool result)
{
    std::string msg = fmt::format("and_loginResult {0}", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_changePwResult(bool result)
{
    std::string msg = fmt::format("and_changePwResult {0}", boolToMsgArg(result));
    _sendMsg(msg);
}

void AndroidEngine::and_returnDoorStatus(int status)
{
    std::string msg = fmt::format("and_returnDoorStatus {0}", intToMsgArg(status));
    _sendMsg(msg);
}

void AndroidEngine::and_returnMotionStatus(int status)
{
    std::string msg = fmt::format("and_returnMotionStatus {0}", intToMsgArg(status));
    _sendMsg(msg);
}

void AndroidEngine::and_returnBellStatus(int status)
{
    std::string msg = fmt::format("and_returnBellStatus {0}", intToMsgArg(status));
    _sendMsg(msg);
}


void AndroidEngine::_hss_recvMsg(const std::string &msg)
{
    std::vector<std::string> vec;
    boost::split(vec, msg, boost::is_any_of(" \n"), boost::token_compress_on);

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

    if(vec.at(0) == "pi_enableSystemStatus") {
        bool pi_enableSystemStatus_arg1 = msgArgToBool(vec.at(1));
        pi_enableSystemStatus(pi_enableSystemStatus_arg1);
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
}

void AndroidEngine::pi_requestLogin(const std::string &username,
                                    const std::string &pwd)
{

}

void AndroidEngine::pi_changePassword(const std::string &username,
                                      const std::string &oldpwd,
                                      const std::string &newpwd)
{

}

void AndroidEngine::pi_enableDetectMotion(const bool &enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_DT_MOTION_ENABLE_SETTING, enable);
}

void AndroidEngine::pi_enableSystemStatus(const bool &enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_SYS_STT_ENABLE_SETTING, enable);
}

void AndroidEngine::pi_enableDetectDoor(const bool &enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_DT_DOOR_ENABLE_SETTING, enable);
}

void AndroidEngine::pi_enableDoorBell(const bool &enable)
{
    std::cout<<__FUNCTION__<<std::endl;
    _setOptionsValue(HSS_DOOR_BELL_ENABLE_SETTING, enable);
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
