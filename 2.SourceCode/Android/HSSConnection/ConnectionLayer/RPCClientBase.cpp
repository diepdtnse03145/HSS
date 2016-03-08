#include "RPCClientBase.h"

RPCClientBase::RPCClientBase(ConnectionLayer &connection):
    cnt(connection)
{

}

void RPCClientBase::_sendMsg(QString msg)
{
    cnt.sendData(msg);
}
