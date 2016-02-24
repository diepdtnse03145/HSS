#include <boost/bind.hpp>

#include "ConnectionLayerBase.h"
#include "RPCServerBase.h"

ConnectionLayerBase::ConnectionLayerBase(RPCServerBase &sv):
    _rpc_sv{sv}
{

}


void ConnectionLayerBase::_receiveMsg(std::string msg)
{
    _rpc_sv._receiveMsg(msg);
}
