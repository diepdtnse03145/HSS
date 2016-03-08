#include "rpc_pr.h"
#include <QtCore>


bool msgArgToBool(const QString &arg)
{
    return static_cast<bool>(arg.toInt());
}

QString boolToMsgArg(const bool &vl)
{
    return vl ? "1" : "0";
}

QString msgArgToString(const QString &arg)
{

}

QString stringToMsgArg(const QString &vl)
{

}
