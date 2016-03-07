#include "androidengine.h"

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

void AndroidEngine::_hss_recvMsg(const std::string &msg)
{

}

