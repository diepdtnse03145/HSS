#include <iostream>
#include "ConnectionLayer/TcpConnectionLayer.h"
#include "ConnectionLayer/TcpRPCServer.h"
#include "ConnectionLayer/SerialConnectionLayer.h"

int main(int argc, char *argv[])
{
    TcpRPCServer sv;
    TcpConnectionLayer c{sv};
    boost::asio::io_service io;
    SerialConnectionLayer serial{sv,io};
    serial.sendMsg("ad_ledOn");
    io.run();
    return 0;
}
