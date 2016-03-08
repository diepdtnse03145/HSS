#include "ConnectionLayer.h"

ConnectionLayer::ConnectionLayer(QObject *parent)
    : QObject(parent)
{
    connect(&moeSocket,&QIODevice::readyRead, this, &ConnectionLayer::receiveData);
}

ConnectionLayer::~ConnectionLayer()
{

}

void ConnectionLayer::connectToHost(const QString &hostName, quint16 port)
{
    qDebug()<<"Connecting:"<<hostName<<port;
    moeSocket.connectToHost(hostName, port);
    qDebug()<<"Connected:"<<moeSocket.waitForConnected(-1);
    qDebug()<<moeSocket.errorString();
}

void ConnectionLayer::sendData(QString data)
{
//    data.append("\n");
    if(moeSocket.isValid()){
        moeSocket.write(data.toUtf8());
    }
}

void ConnectionLayer::receiveData()
{
    if(moeSocket.canReadLine()){
        emit receivedData(moeSocket.readLine());
    }
}
