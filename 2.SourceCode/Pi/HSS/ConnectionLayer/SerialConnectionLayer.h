#ifndef SERIALCONNECTIONLAYER_H
#define SERIALCONNECTIONLAYER_H

#include "RPC_Base/ConnectionLayerBase.h"
#include <boost/asio.hpp>
#include <bits/stdc++.h>

class RPCServerBase;

class SerialConnectionLayer: public ConnectionLayerBase
{
public:
    SerialConnectionLayer(RPCServerBase& sv, std::string portName, boost::asio::io_service& io);
    void _sendMsg(std::string msg) override;

private:
    boost::asio::serial_port _port;
    boost::asio::streambuf _buf;

    void _handleRead(const boost::system::error_code& ec, std::size_t len);
    void _handleWrite(const boost::system::error_code& ec, std::size_t len);
};

#endif //SERIALCONNECTIONLAYER_H
