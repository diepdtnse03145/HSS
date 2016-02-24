#include "SerialRPCServerMega.h"
#include <iostream>


void SerialRPCServerMega::Accept(std::string s)
{
    std::cout<<"string"<<std::endl;
}

void SerialRPCServerMega::Accept(double s)
{
    std::cout<<"double"<<std::endl;

}

void SerialRPCServerMega::Accept(int s)
{
    std::cout<<"int"<<std::endl;

}

void SerialRPCServerMega::Accept()
{
    std::cout<<"none"<<std::endl;
}


