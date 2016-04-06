#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QtAndroidExtras>

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(QObject *parent = 0);

signals:

public slots:
    void MoeMoe();

private:
    QAndroidJniObject _javaMainAct;
    bool _calling;
};

#endif // ENGINE_H
