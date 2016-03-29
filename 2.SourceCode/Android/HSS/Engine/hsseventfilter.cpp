#include "hsseventfilter.h"
#include <QtCore>
#include <QtWidgets>

HSSEventFilter::HSSEventFilter(QObject *parent) : QObject(parent)
{

}

bool HSSEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::ApplicationActivate) {
        emit applicationActivateCaptured();
        return true;
    }

    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Back) {
            emit backKeyCaptured();
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}
