#include "serialconnection.h"
#include "../hss_global.h"
#include <boost/bind.hpp>
#include <iostream>

SerialConnection::SerialConnection(Setting &setting, boost::asio::io_service& io) :
    ConnectionBase{setting},
    _port{io},
    _isSending{false}
{
    _port.open(_getOptionsValue<std::string>(HSS_ARDUINO_PORT_SETTING));
    _port.set_option(boost::asio::serial_port_base::baud_rate(9600));

    boost::asio::async_read_until(_port, _buf, "\n",
                                  boost::bind(&SerialConnection::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void SerialConnection::_hss_sendMsg()
{
    if (!_hss_isSending()) {
        std::cout<<__FUNCTION__<<": "<<_sendQueue.front()<<std::endl;
        boost::asio::async_write(_port, boost::asio::buffer(_sendQueue.front()),
                                      boost::bind(&SerialConnection::_handleWrite,
                                                  this, boost::placeholders::_1, boost::placeholders::_2
                                                  )
                                      );
        _isSending = true;
    } else {
        std::cout<<"Serial connection is sending msg, your msg will be sent later"<<std::endl;
    }
}

bool SerialConnection::_hss_isSending()
{
    return _isSending;
}

void SerialConnection::_handleRead(const boost::system::error_code &ec, std::size_t len)
{
    auto bufs = _buf.data();
    std::string line(
                boost::asio::buffers_begin(bufs),
                boost::asio::buffers_begin(bufs) + len
                );
    _buf.consume(len);
    _recvMsg(line);
    std::cout<<__FUNCTION__<<": "<<line<<std::endl;
    boost::asio::async_read_until(_port, _buf, "\n",
                                  boost::bind(&SerialConnection::_handleRead,
                                              this, boost::placeholders::_1, boost::placeholders::_2
                                              )
                                  );
}

void SerialConnection::_handleWrite(const boost::system::error_code &ec, std::size_t len)
{
    _isSending = false;
    _sendQueue.pop();

    if (!_sendQueue.empty()) {
        _hss_sendMsg();
    }
}
