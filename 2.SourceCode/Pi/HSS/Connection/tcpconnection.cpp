#include "tcpconnection.h"
#include <boost/bind.hpp>
#include <iostream>
TcpConnection::TcpConnection(Setting &setting, boost::asio::io_service &io) :
    ConnectionBase{setting},
    _tcp_sv{io, boost::asio::ip::tcp::endpoint{boost::asio::ip::tcp::v4(), _getOptionsValue<unsigned short>("tcp_sv_port")}},
    _sock{io},
    _isSending{false}
{
    _doAccept();
}

void TcpConnection::_hss_sendMsg()
{
    if (!_hss_isSending()) {
        boost::asio::async_write(_sock, boost::asio::buffer(_sendQueue.front()),
                                 boost::bind(&TcpConnection::_handleWrite,
                                             this, boost::placeholders::_1, boost::placeholders::_2
                                             )
                                 );
        _isSending = true;
    } else {
        std::cout<<"Serial connection is sending msg, your msg will be sent later"<<std::endl;
    }
}

bool TcpConnection::_hss_isSending()
{
    return _isSending;
}

void TcpConnection::_doAccept()
{
    _tcp_sv.async_accept(_sock, _end, boost::bind(&TcpConnection::_handleAccept,
                                                  this, boost::placeholders::_1));
}

void TcpConnection::_handleAccept(const boost::system::error_code &ec)
{
    boost::asio::async_read_until(_sock, _buf, "\n",
                                  boost::bind(&TcpConnection::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void TcpConnection::_handleRead(const boost::system::error_code &ec, std::size_t len)
{
    auto bufs = _buf.data();
    std::string line(
                boost::asio::buffers_begin(bufs),
                boost::asio::buffers_begin(bufs) + len
                );
    _buf.consume(len);
    _recvMsg(line);

    boost::asio::async_read_until(_sock, _buf, "\n",
                                  boost::bind(&TcpConnection::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void TcpConnection::_handleWrite(const boost::system::error_code &ec, std::size_t len)
{
    _isSending = false;
    _sendQueue.pop();

    if (!_sendQueue.empty()) {
        _hss_sendMsg();
    }
}
