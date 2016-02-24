#ifndef TCPRPCCLIENT_H
#define TCPRPCCLIENT_H

#include "../RPC_Base/RPCClientBase.h"
#include <string>

class TcpRPCClient: public RPCClientBase
{
public:
    TcpRPCClient(ConnectionLayerBase& cntLayer);

    void MoeFunct(int vl);
};

#endif //TCPRPCCLIENT_H
