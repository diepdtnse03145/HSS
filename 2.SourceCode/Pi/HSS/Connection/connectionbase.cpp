#include "connectionbase.h"
#include <iostream>

ConnectionBase::ConnectionBase()
{

}

void ConnectionBase::_sendMsg(const std::string &msg)
{
    std::cout<<__FUNCTION__<<": "<<msg<<std::endl;
    _sendQueue.push(msg);
    _hss_sendMsg();
}

void ConnectionBase::_recvMsg(const std::string &msg)
{
    _hss_recvMsg(msg);
}
