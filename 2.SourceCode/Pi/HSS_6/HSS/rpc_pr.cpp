#include "rpc_pr.h"
#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/hex.hpp>

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
    std::string res;
    boost::algorithm::unhex(arg, std::back_inserter(res));
    return res;
}

std::string stringToMsgArg(const std::string &vl)
{
    std::string res;
    boost::algorithm::hex(vl, std::back_inserter(res));
    return res;
}

int msgArgToInt(const std::string &arg)
{
    return std::stoi(arg);
}

std::string intToMsgArg(const int &vl)
{
    return boost::lexical_cast<std::string>(vl);
}
