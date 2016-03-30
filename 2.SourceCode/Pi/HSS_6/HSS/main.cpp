#include "Engine/androidengine.h"
#include "Engine/arduinoengine.h"
#include "Connection/hsspushable.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    Setting setting;
    HSSDatabase db;
    HSSPushable pusherServer;
    boost::asio::io_service io;
    AndroidEngine android{setting, db, pusherServer, io};
    ArduinoEngine arduino{setting, db, pusherServer, io};

    android.setArduinoEngine(&arduino);
    arduino.setAndroidEngine(&android);

    return io.run();
}
