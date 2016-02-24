#ifndef CONNECTIONLAYERBASE_H
#define CONNECTIONLAYERBASE_H

#include <boost/asio.hpp>
#include <bits/stdc++.h>

class RPCServerBase;

class ConnectionLayerBase
{
public:
    ConnectionLayerBase(RPCServerBase& sv);
    void _receiveMsg(std::string msg);

    virtual void _sendMsg(std::string msg) = 0;

private:
    RPCServerBase& _rpc_sv;
};

#endif //CONNECTIONLAYERBASE_H
