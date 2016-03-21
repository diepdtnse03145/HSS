#ifndef RPC_PR_H
#define RPC_PR_H

class QString;

bool msgArgToBool(const QString& arg);
QString boolToMsgArg(const bool& vl);

QString msgArgToString(const QString& arg);
QString stringToMsgArg(const QString& vl);

int msgArgToInt(const QString& arg);
QString intToMsgArg(const int& vl);

#endif // RPC_PR_H
