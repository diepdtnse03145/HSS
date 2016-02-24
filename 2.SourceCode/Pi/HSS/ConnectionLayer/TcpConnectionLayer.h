#ifndef TCPCONNECTIONLAYER_H
#define TCPCONNECTIONLAYER_H

#include <boost/asio.hpp>
#include <bits/stdc++.h>

class RPCServerBase;

class TcpConnectionLayer
{
public:
    TcpConnectionLayer(RPCServerBase& sv);

private:
    RPCServerBase& rpc_sv;
};

#endif //TCPCONNECTIONLAYER_H
