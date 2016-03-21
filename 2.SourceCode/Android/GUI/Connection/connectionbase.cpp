#include "connectionbase.h"

ConnectionBase::ConnectionBase(QObject *parent) : QObject(parent)
{
    connect(&_sock, &QIODevice::readyRead, this, &ConnectionBase::_recvMsg);
}

void ConnectionBase::connectToHost(const QString &hostName, quint16 port)
{
    qDebug()<<"Connecting:"<<hostName<<port;
    _sock.connectToHost(hostName, port);
    qDebug()<<"Connected:"<<_sock.waitForConnected(-1);
    qDebug()<<_sock.errorString();

}

void ConnectionBase::_recvMsg()
{
    if(_sock.canReadLine()){
        emit _hss_recvMsg(_sock.readLine());
    }
}

void ConnectionBase::_sendMsg(const QString &msg)
{
    _hss_sendMsg(msg);
}

void ConnectionBase::_hss_sendMsg(const QString &msg)
{
    if(_sock.isValid()){
        _sock.write(msg.toUtf8());
        _sock.waitForBytesWritten(-1);
    }
}


