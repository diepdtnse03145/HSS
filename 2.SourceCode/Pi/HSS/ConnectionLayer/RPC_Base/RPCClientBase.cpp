#include "RPCClientBase.h"

RPCClientBase::RPCClientBase(ConnectionLayerBase &cntLayer) :
    _cnt{cntLayer}
{

}

void RPCClientBase::_sendMsg(std::string msg)
{
    std::cout<<__FUNCTION__<<msg<<std::endl;
//    _cnt._sendMsg(msg);
}
