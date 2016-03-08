#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include "../RPCClientBase.h"

class RPCCLient: public RPCClientBase
{
public:
    RPCCLient(ConnectionLayer& connection);
    void clickButton(int app, int index, int command);

};

#endif //RPCCLIENT_H
