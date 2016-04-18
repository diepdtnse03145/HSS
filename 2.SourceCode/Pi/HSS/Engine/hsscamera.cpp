#include "hsscamera.h"

HSSCamera::HSSCamera() :
    _running{true},
    _haveWork{false},
    _t{&HSSCamera::_t_work,this}
{

}

HSSCamera::~HSSCamera()
{
    _setRunning(false);
    if(_t.joinable()) {
        _t.join();
    }
}

void HSSCamera::capture()
{
    _setHaveWork(true);
}

bool HSSCamera::_isRunning()
{
    std::lock_guard<std::mutex> lock(_running_mutex);
    return _running;
}


bool HSSCamera::_isHaveWork()
{
    std::lock_guard<std::mutex> lock(_running_mutex);
    return _haveWork;
}

void HSSCamera::_t_work()
{
    while (true) {
        if (_isRunning()) {
            std::this_thread::sleep_for(std::chrono::milliseconds{50});
            if (_isHaveWork()) {
                std::system("fswebcam -r 640x480 --no-banner /var/www/html/door.jpg -S 2");
                _setHaveWork(false);
            }
        } else {
            return;
        }
    }
}

void HSSCamera::_setRunning(bool vl)
{
    std::lock_guard<std::mutex> lock(_running_mutex);
    _running = vl;
}

void HSSCamera::_setHaveWork(bool vl)
{
    std::lock_guard<std::mutex> lock(_havework_mutex);
    _haveWork = vl;
}


