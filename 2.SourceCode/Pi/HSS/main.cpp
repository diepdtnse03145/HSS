#include <iostream>
#include "ConnectionLayer/TcpConnectionLayer.h"
#include "ConnectionLayer/RPC_Server/TcpRPCServer.h"
#include "ConnectionLayer/SerialConnectionLayer.h"
#include "ConnectionLayer/RPC_Client/TcpRPCClient.h"

int main(int argc, char *argv[])
{
    boost::asio::io_service io;
    TcpRPCServer sv;
    TcpConnectionLayer c{sv, 13, io};
    TcpRPCClient cl{c};
    cl.MoeFunct(33);

//    SerialConnectionLayer serial{sv,"COM7" ,io};
//    serial.sendMsg("ad_ledOn");
    io.run();
    return 0;
}
