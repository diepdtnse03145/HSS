#include "SerialRPCServerUno.h"
#include <iostream>


void SerialRPCServerUno::Accept(std::string s)
{
    std::cout<<"string"<<std::endl;
}

void SerialRPCServerUno::Accept(double s)
{
    std::cout<<"double"<<std::endl;

}

void SerialRPCServerUno::Accept(int s)
{
    std::cout<<"int"<<std::endl;

}

void SerialRPCServerUno::Accept()
{
    std::cout<<"none"<<std::endl;
}


