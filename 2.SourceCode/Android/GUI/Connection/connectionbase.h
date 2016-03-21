#ifndef CONNECTIONBASE_H
#define CONNECTIONBASE_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <queue>

class ConnectionBase : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionBase(QObject *parent = 0);
    void connectToHost(const QString &hostName, quint16 port);

private slots:
    void _recvMsg();

protected:
    void _sendMsg(const QString& msg);
    virtual void _hss_recvMsg(const QString& msg) = 0;

private:
    void _hss_sendMsg(const QString& msg);

    QTcpSocket _sock;
};

#endif // CONNECTIONBASE_H
