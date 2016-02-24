#include "TcpConnectionLayer.h"
#include "RPC_Base/RPCServerBase.h"
#include <boost/bind.hpp>

TcpConnectionLayer::TcpConnectionLayer(RPCServerBase &sv, int port, boost::asio::io_service &io):
    ConnectionLayerBase{sv},
    _tcp_sv{io, boost::asio::ip::tcp::endpoint{boost::asio::ip::tcp::v4(), static_cast<unsigned short>(port)}},
    _sock{io}
{
    _doAccept();
}

void TcpConnectionLayer::_sendMsg(std::string msg)
{
    boost::asio::async_write(_sock, boost::asio::buffer(msg),
                                  boost::bind(TcpConnectionLayer::_handleWrite,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void TcpConnectionLayer::_doAccept()
{
    _tcp_sv.async_accept(_sock, _end, boost::bind(TcpConnectionLayer::_handleAccept,
                                                  this, boost::placeholders::_1));

}

void TcpConnectionLayer::_handleAccept(const boost::system::error_code &ec)
{
    boost::asio::async_read_until(_sock, _buf, "\n",
                                  boost::bind(TcpConnectionLayer::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void TcpConnectionLayer::_handleRead(const boost::system::error_code &ec, std::size_t len)
{
    auto bufs = _buf.data();
    std::string line(
                boost::asio::buffers_begin(bufs),
                boost::asio::buffers_begin(bufs) + len
                );
    _buf.consume(len);
    _receiveMsg(line);

    boost::asio::async_read_until(_sock, _buf, "\n",
                                  boost::bind(TcpConnectionLayer::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void TcpConnectionLayer::_handleWrite(const boost::system::error_code &ec, std::size_t len)
{

}
