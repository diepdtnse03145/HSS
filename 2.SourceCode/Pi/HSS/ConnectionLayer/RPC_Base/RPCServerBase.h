#ifndef RPCSERVERBASE_H
#define RPCSERVERBASE_H
#include <string>

class RPCServerBase
{
public:
    virtual void _receiveMsg(std::string msg) = 0;

private:

};

#endif //RPCSERVERBASE_H
