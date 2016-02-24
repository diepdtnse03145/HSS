#include "SerialConnectionLayer.h"
#include "RPCServerBase.h"

#include <boost/bind.hpp>

SerialConnectionLayer::SerialConnectionLayer(RPCServerBase &sv, boost::asio::io_service& io):
    _sv{sv},
    _port{io}
{
    _sv._receiveMsg("Accept 1.2");
    _port.open("COM7");
    _port.set_option(boost::asio::serial_port_base::baud_rate(9600));

    boost::asio::async_read_until(_port,_buf,"\n",
                                  boost::bind(SerialConnectionLayer::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );

}

void SerialConnectionLayer::sendMsg(std::string msg)
{
    boost::asio::async_write(_port,boost::asio::buffer(msg),
                                  boost::bind(SerialConnectionLayer::_handleWrite,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );

}

void SerialConnectionLayer::_handleRead(boost::system::error_code er, std::size_t len){
    auto bufs = _buf.data();
    std::string line(
                boost::asio::buffers_begin(bufs),
                boost::asio::buffers_begin(bufs) + len);
    _buf.consume(len);
    std::cout<<line<<std::endl<<std::endl;

    boost::asio::async_read_until(_port,_buf,"\n",
                                  boost::bind(SerialConnectionLayer::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void SerialConnectionLayer::_handleWrite(boost::system::error_code er, std::size_t len)
{

}
