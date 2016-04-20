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
    bool connectToHost(const QString &hostName, quint16 port);

public slots:
    void changeIp(const QString& ip);

private slots:
    void _recvMsg();

protected:
    void _sendMsg(const QString& msg);
    virtual void _hss_recvMsg(const QString& msg) = 0;

signals:
    void _connectToHostResult(bool res);
    void _ipChanged(QString ip);

private:
    void _hss_sendMsg(const QString& msg);

    QTcpSocket _sock;
    QString _ip;
};

#endif // CONNECTIONBASE_H
