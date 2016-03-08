#include "rpc_pr.h"
#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>

bool msgArgToBool(const std::string &arg)
{
    return static_cast<bool>(std::stoi(arg));
}

std::string boolToMsgArg(const bool &vl)
{
    return vl ? "1" : "0";
}

std::string msgArgToString(const std::string &arg)
{

}

std::string stringToMsgArg(const std::string &vl)
{

}

int msgArgToInt(const std::string &arg)
{
    return std::stoi(arg);
}

std::string intToMsgArg(const int &vl)
{
    return boost::lexical_cast<std::string>(vl);
}
