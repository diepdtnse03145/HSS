#include "androidengine.h"

AndroidEngine::AndroidEngine(int port, boost::asio::io_service &io) :
    TcpConnection{port,io}
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

