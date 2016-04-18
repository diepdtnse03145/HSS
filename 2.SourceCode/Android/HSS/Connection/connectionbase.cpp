#include "connectionbase.h"

ConnectionBase::ConnectionBase(QObject *parent) : QObject(parent)
{
    connect(&_sock, &QIODevice::readyRead, this, &ConnectionBase::_recvMsg);
}

bool ConnectionBase::connectToHost(const QString &hostName, quint16 port)
{
    qDebug()<<"Connecting:"<<hostName<<port;
    _sock.connectToHost(hostName, port);
    return _sock.waitForConnected(-1);
}

void ConnectionBase::_recvMsg()
{
    if(_sock.canReadLine()){
        emit _hss_recvMsg(_sock.readLine());
    }
}

void ConnectionBase::_sendMsg(const QString &msg)
{
    if (_sock.state() != QTcpSocket::ConnectedState) {
        emit _connectToHostResult(connectToHost("192.168.125.50", 1340));
    }
    _hss_sendMsg(msg);
    //TEST
    qDebug() << __FUNCTION__<<msg;
}

void ConnectionBase::_hss_sendMsg(const QString &msg)
{
    if(_sock.state() == QTcpSocket::ConnectedState){
        _sock.write(msg.toUtf8());
        _sock.waitForBytesWritten(-1);
    }
}


