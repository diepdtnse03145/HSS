#include "TcpConnectionLayer.h"
#include "RPCServerBase.h"

TcpConnectionLayer::TcpConnectionLayer(RPCServerBase &sv):
    rpc_sv{sv}
{
    rpc_sv._receiveMsg("Accept 1.2");

}
