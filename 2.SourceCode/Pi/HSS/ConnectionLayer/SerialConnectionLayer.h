#ifndef SERIALCONNECTIONLAYER_H
#define SERIALCONNECTIONLAYER_H

#include <boost/asio.hpp>
#include <bits/stdc++.h>

class RPCServerBase;

class SerialConnectionLayer
{
public:
    SerialConnectionLayer(RPCServerBase& sv, boost::asio::io_service& io);
    void sendMsg(std::string msg);

private:
    RPCServerBase& _sv;
    boost::asio::serial_port _port;
    boost::asio::streambuf _buf;

    void _handleRead(boost::system::error_code er, std::size_t len);
    void _handleWrite(boost::system::error_code er, std::size_t len);
};

#endif //SERIALCONNECTIONLAYER_H
