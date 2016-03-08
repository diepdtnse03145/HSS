#include <QCoreApplication>
#include "Engine/piengine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    PiEngine engine;
    engine.connectToHost("localhost", 13);
    engine.pi_enableDetectDoor(false);
    return a.exec();
}
