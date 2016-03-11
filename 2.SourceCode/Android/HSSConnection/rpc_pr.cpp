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
    return arg.toLatin1().toHex();
}

QString stringToMsgArg(const QString &vl)
{
    return QByteArray::fromHex(vl.toLatin1());
}

int msgArgToInt(const QString &arg)
{
    return arg.toInt();
}

QString intToMsgArg(const int &vl)
{
    return QString::number(vl);
}
