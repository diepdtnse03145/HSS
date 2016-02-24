#ifndef TCPCONNECTIONLAYER_H
#define TCPCONNECTIONLAYER_H

#include "RPC_Base/ConnectionLayerBase.h"
#include <boost/asio.hpp>
#include <bits/stdc++.h>

class RPCServerBase;

class TcpConnectionLayer: public ConnectionLayerBase
{
public:
    TcpConnectionLayer(RPCServerBase& sv, int port, boost::asio::io_service& io);
    void _sendMsg(std::string msg) override;

private:
    boost::asio::ip::tcp::acceptor _tcp_sv;
    boost::asio::ip::tcp::socket _sock;
    boost::asio::ip::tcp::endpoint _end;    
    boost::asio::streambuf _buf;

    void _doAccept();
    void _handleAccept(const boost::system::error_code& ec);
    void _handleRead(const boost::system::error_code& ec, std::size_t len);
    void _handleWrite(const boost::system::error_code& ec, std::size_t len);
};

#endif //TCPCONNECTIONLAYER_H
