#ifndef CONNECTIONLAYER_H
#define CONNECTIONLAYER_H

#include <QObject>
#include <QtCore>
#include <QtNetwork>

class ConnectionLayer : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionLayer(QObject *parent = 0);
    ~ConnectionLayer();

    void connectToHost(const QString &hostName, quint16 port);

signals:
    void receivedData(QString);

public slots:
    void sendData(QString data);

private slots:
    void receiveData();
private:
    QTcpSocket moeSocket;
};

#endif //CONNECTIONLAYER_H
