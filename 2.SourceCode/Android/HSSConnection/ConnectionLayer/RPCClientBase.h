#ifndef RPCCLIENTBASE_H
#define RPCCLIENTBASE_H

#include "ConnectionLayer.h"

class RPCClientBase
{
public:
    RPCClientBase(ConnectionLayer& connection);

protected:
    void _sendMsg(QString msg);

private:
    ConnectionLayer& cnt;

};

#endif //RPCCLIENTBASE_H
