#ifndef RPC_PR_H
#define RPC_PR_H

#include <string>

bool msgArgToBool(const std::string& arg);
std::string boolToMsgArg(const bool& vl);

std::string msgArgToString(const std::string& arg);
std::string stringToMsgArg(const std::string& vl);

int msgArgToInt(const std::string& arg);
std::string intToMsgArg(const int& vl);

#endif // RPC_PR_H
