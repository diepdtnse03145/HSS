#include "Engine/androidengine.h"
#include "Engine/arduinoengine.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    Setting setting;
    HSSDatabase db;
    boost::asio::io_service io;
    AndroidEngine android{setting, db, io};
    ArduinoEngine arduino{setting, db, io};

    android.setArduinoEngine(&arduino);
    arduino.setAndroidEngine(&android);

    return io.run();
}
