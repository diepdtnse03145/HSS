#include "arduinoengine.h"

#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <bits/stdc++.h>

ArduinoEngine::ArduinoEngine(Setting &setting, boost::asio::io_service &io) :
    SerialConnection{setting, io},
    _sensorTimer{io}
{
//    _requestSensorValue();
}

void ArduinoEngine::setAndroidEngine(AndroidEngine *engine)
{
    _andr = engine;
}

int ArduinoEngine::pirValue() const
{
    return _pirValue;
}

int ArduinoEngine::bellValue() const
{
    return _bellValue;
}

int ArduinoEngine::switchValue() const
{
    return _switchValue;
}

void ArduinoEngine::setBellValue(int bellValue)
{
    _bellValue = bellValue;
}

void ArduinoEngine::setPirValue(int pirValue)
{
    _pirValue = pirValue;
}

void ArduinoEngine::setSwitchValue(int switchValue)
{
    _switchValue = switchValue;
}

void ArduinoEngine::ad_requestPirVal()
{
    std::string msg = "ad_requestPirVal\n";
    _sendMsg(msg);
}

void ArduinoEngine::ad_requestBellVal()
{
    std::string msg = "ad_requestBellVal\n";
    _sendMsg(msg);
}

void ArduinoEngine::ad_requestSwitchVal()
{
    std::string msg = "ad_requestSwitchVal\n";
    _sendMsg(msg);
}

void ArduinoEngine::pi_returnPirValue(int vl)
{
    //do some thing with vl
    std::cout<<__FUNCTION__<<":"<<vl<<std::endl;
    setPirValue(vl);
}

void ArduinoEngine::pi_returnBellValue(int vl)
{
    std::cout<<__FUNCTION__<<":"<<vl<<std::endl;
    setBellValue(vl);
}

void ArduinoEngine::pi_returnSwitchValue(int vl)
{
    std::cout<<__FUNCTION__<<":"<<vl<<std::endl;
    setSwitchValue(vl);
}

void ArduinoEngine::_requestSensorValue(const boost::system::error_code &ec)
{
    if (ec == boost::system::errc::success) {
        ad_requestPirVal();
        ad_requestBellVal();
        ad_requestSwitchVal();

        _sensorTimer.cancel();
        _sensorTimer.expires_from_now(std::chrono::seconds{5});
        _sensorTimer.async_wait(boost::bind(
                                    &ArduinoEngine::_requestSensorValue,
                                    this, boost::asio::placeholders::error)
                                );
    }
}

void ArduinoEngine::_hss_recvMsg(const std::string &msg)
{
    std::vector<std::string> vec;
    boost::split(vec, msg, boost::is_any_of(" \n"), boost::token_compress_on);

    if(vec.at(0) == "pi_returnPirValue") {
        int pi_returnPirValue_arg1 = std::stoi(vec.at(1));
        pi_returnPirValue(pi_returnPirValue_arg1);
    }

    if(vec.at(0) == "pi_returnBellValue") {
        int pi_returnBellValue_arg1 = std::stoi(vec.at(1));
        pi_returnPirValue(pi_returnBellValue_arg1);
    }

    if(vec.at(0) == "pi_returnSwitchValue") {
        int pi_returnSwitchValue_arg1 = std::stoi(vec.at(1));
        pi_returnPirValue(pi_returnSwitchValue_arg1);
    }
}
