#include "RPCClient.h"


RPCCLient::RPCCLient(ConnectionLayer &connection):
    RPCClientBase{connection}
{

}

void RPCCLient::clickButton(int app, int index, int command)
{
    qDebug()<<__FUNCTION__<< app<<index<<command;
    QString msg = QStringLiteral("clickButton %1 %2 %3\n").arg(QString::number(app),
                                                               QString::number(index),
                                                               QString::number(command)
                                                               );
    RPCClientBase::_sendMsg(msg);

}
