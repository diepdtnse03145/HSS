#include "TcpRPCServer.h"
#include <iostream>


void TcpRPCServer::Accept(std::string s)
{
    std::cout<<"string"<<std::endl;
}

void TcpRPCServer::Accept(double s)
{
    std::cout<<"double"<<std::endl;

}

void TcpRPCServer::Accept(int s)
{
    std::cout<<"int"<<std::endl;

}

void TcpRPCServer::Accept()
{
    std::cout<<"none"<<std::endl;
}


