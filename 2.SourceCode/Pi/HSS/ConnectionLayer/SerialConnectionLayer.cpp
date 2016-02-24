#include "SerialConnectionLayer.h"
#include "RPC_Base/RPCServerBase.h"

#include <boost/bind.hpp>

SerialConnectionLayer::SerialConnectionLayer(RPCServerBase &sv, std::string portName,
                                             boost::asio::io_service& io):
    ConnectionLayerBase{sv},
    _port{io}
{
    _port.open(portName);
    _port.set_option(boost::asio::serial_port_base::baud_rate(9600));

    boost::asio::async_read_until(_port, _buf, "\n",
                                  boost::bind(SerialConnectionLayer::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void SerialConnectionLayer::_sendMsg(std::string msg)
{
    boost::asio::async_write(_port, boost::asio::buffer(msg),
                                  boost::bind(SerialConnectionLayer::_handleWrite,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void SerialConnectionLayer::_handleRead(const boost::system::error_code &ec, std::size_t len)
{
    auto bufs = _buf.data();
    std::string line(
                boost::asio::buffers_begin(bufs),
                boost::asio::buffers_begin(bufs) + len
                );
    _buf.consume(len);
    _receiveMsg(line);

    boost::asio::async_read_until(_port, _buf, "\n",
                                  boost::bind(SerialConnectionLayer::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void SerialConnectionLayer::_handleWrite(const boost::system::error_code &ec, std::size_t len)
{

}
