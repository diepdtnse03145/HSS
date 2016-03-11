#include "androidengine.h"
#include "../rpc_pr.h"
#include "../hss_global.h"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

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

void AndroidEngine::and_changePwResult(bool result)
{
//    std::string msg = "and_changePwResult"
}

void AndroidEngine::pi_changePassword(const std::string &oldpwd, const std::string &newpwd)
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

void AndroidEngine::_hss_recvMsg(const std::string &msg)
{

    std::vector<std::string> vec;
    boost::split(vec, msg, boost::is_any_of(" \n"), boost::token_compress_on);

    if(vec.at(0) == "pi_changePassword") {
/////////////////////////////////////////////////////
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
}
