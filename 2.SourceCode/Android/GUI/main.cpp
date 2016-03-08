#include "hssengine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    HSSEngine engine;
    engine.run();
    return app.exec();
}

