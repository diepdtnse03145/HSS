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

private:
    ArduinoEngine* _ard;

    void _hss_recvMsg(const std::string &msg) override final;

};

#endif // ANDROIDENGINE_H
