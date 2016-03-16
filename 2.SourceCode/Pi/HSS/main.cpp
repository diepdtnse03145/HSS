#include "Engine/androidengine.h"
#include "Engine/arduinoengine.h"
#include "Setting/setting.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    Setting setting;
    boost::asio::io_service io;
    AndroidEngine android{setting, io};
    ArduinoEngine arduino{setting, io};

    android.setArduinoEngine(&arduino);
    arduino.setAndroidEngine(&android);

    return io.run();
}
