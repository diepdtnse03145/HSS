#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h>

#include "../TcpRPCServer.h"

void TcpRPCServer::_receiveMsg(std::string msg)
{
    std::vector<std::string> v;
    boost::split(v,msg,boost::is_any_of(" "));
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


