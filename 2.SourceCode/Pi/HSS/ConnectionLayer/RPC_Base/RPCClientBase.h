#ifndef RPCCLIENTBASE_H
#define RPCCLIENTBASE_H

#include "ConnectionLayerBase.h"

class RPCClientBase
{
public:
    RPCClientBase(ConnectionLayerBase& cntLayer);

protected:
    void _sendMsg(std::string msg);

private:
    ConnectionLayerBase& _cnt;
};

#endif //RPCCLIENTBASE_H
