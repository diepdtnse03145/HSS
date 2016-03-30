#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "connectionbase.h"
#include <boost/asio.hpp>

class TcpConnection : public ConnectionBase
{
public:
    TcpConnection(Setting& setting,
                  HSSDatabase& db,
                  boost::asio::io_service& io);

protected:
    void _hss_sendMsg() override final;
    bool _hss_isSending() override final;
    virtual void _hss_recvMsg(const std::string& msg) = 0;

private:
    boost::asio::ip::tcp::acceptor _tcp_sv;
    boost::asio::ip::tcp::socket _sock;
    boost::asio::ip::tcp::endpoint _end;
    boost::asio::streambuf _buf;
    bool _isSending;

    void _doAccept();
    void _handleAccept(const boost::system::error_code& ec);
    void _handleRead(const boost::system::error_code& ec, std::size_t len);
    void _handleWrite(const boost::system::error_code& ec, std::size_t len);

};

#endif // TCPCONNECTION_H
