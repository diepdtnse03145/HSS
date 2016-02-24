#ifndef TCPRPCSERVER_H
#define TCPRPCSERVER_H

#include "../RPC_Base/RPCServerBase.h"
#include <string>

class SerialRPCServerUno: public RPCServerBase
{
public:
    void _receiveMsg(std::string msg) override;

private:
    void Accept(std::string s);
    void Accept(double s);
    void Accept(int s);
    void Accept();
};

#endif //TCPRPCSERVER_H
