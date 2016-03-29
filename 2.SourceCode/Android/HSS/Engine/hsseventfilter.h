#ifndef HSSEVENTFILTER_H
#define HSSEVENTFILTER_H

#include <QObject>

class HSSEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit HSSEventFilter(QObject *parent = 0);

signals:
    void backKeyCaptured();
    void applicationActivateCaptured();

public slots:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // HSSEVENTFILTER_H
