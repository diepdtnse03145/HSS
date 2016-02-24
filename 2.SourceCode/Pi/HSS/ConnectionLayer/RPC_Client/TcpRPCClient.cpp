#include "TcpRPCClient.h"
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <bits/stdc++.h>

TcpRPCClient::TcpRPCClient(ConnectionLayerBase &cntLayer) :
    RPCClientBase{cntLayer}
{

}

void TcpRPCClient::MoeFunct(int vl)
{
    auto fmter = boost::format{"%1% %2%\n"} % "MoeFunct" % std::to_string(vl);
    _sendMsg(fmter.str());
}
