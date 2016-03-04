#include <iostream>
#include "Engine/androidengine.h"
#include "Engine/arduinoengine.h"

int main(int argc, char *argv[])
{
    boost::asio::io_service io;
    AndroidEngine android{13, io};
    ArduinoEngine arduino{"COM3", io};

    android.setArduinoEngine(&arduino);
    arduino.setAndroidEngine(&android);

    return io.run();
}
