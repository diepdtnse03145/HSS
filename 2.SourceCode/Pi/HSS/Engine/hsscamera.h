#ifndef HSSCAMERA_H
#define HSSCAMERA_H

#include <string>
#include <mutex>
#include <thread>

class HSSCamera
{
public:
    HSSCamera();
    ~HSSCamera();

    void capture();

private:
    bool _running;
    bool _haveWork;
    std::mutex _running_mutex;
    std::mutex _havework_mutex;
    std::thread _t;

    bool _isRunning();
    bool _isHaveWork();
    void _setRunning(bool vl);
    void _setHaveWork(bool vl);

    void _t_work();
};

#endif // HSSCAMERA_H
