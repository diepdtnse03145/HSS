#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include "connectionbase.h"
#include <boost/asio.hpp>

class SerialConnection : public ConnectionBase
{
public:
    SerialConnection(const std::string& portName, boost::asio::io_service& io);

protected:
    void _hss_sendMsg() override final;
    bool _hss_isSending() override final;
    virtual void _hss_recvMsg(const std::string& msg) = 0;

private:
    boost::asio::serial_port _port;
    boost::asio::streambuf _buf;
    bool _isSending;

    void _handleRead(const boost::system::error_code& ec, std::size_t len);
    void _handleWrite(const boost::system::error_code& ec, std::size_t len);
};

#endif // SERIALCONNECTION_H
