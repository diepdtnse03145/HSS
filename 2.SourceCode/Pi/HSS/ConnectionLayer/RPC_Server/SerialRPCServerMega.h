#ifndef TCPRPCSERVERMEGA_H
#define TCPRPCSERVERMEGA_H

#include "../RPC_Base/RPCServerBase.h"
#include <string>

class SerialRPCServerMega: public RPCServerBase
{
public:
    void _receiveMsg(std::string msg) override;

private:
    void Accept(std::string s);
    void Accept(double s);
    void Accept(int s);
    void Accept();
};

#endif //TCPRPCSERVERMEGA_H
