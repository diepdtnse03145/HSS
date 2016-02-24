#include "TcpRPCServer.h"
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>

void TcpRPCServer::_receiveMsg(std::string msg)
{
    std::vector<std::string> v;
    boost::split(v, msg, boost::is_any_of(" \n"), boost::token_compress_on);
    std::cout << msg <<std::endl;
    std::cout<<v.at(0)<<std::endl;
    if(v.at(0) == "Accept"){
        std::string arg1 = v.at(1);
        Accept(arg1);
    }

    if(v.at(0) == "Accept"){
        int arg1 = std::stoi(v.at(1));
        Accept(arg1);
    }

    if(v.at(0) == "Accept"){
        double arg1 = std::stod(v.at(1));
        Accept(arg1);
    }
}

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


