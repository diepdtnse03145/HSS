#ifndef HSSPUSHABLE_H
#define HSSPUSHABLE_H

#include <string>
#include <queue>
#include <mutex>
#include <thread>


class HSSPushable
{
public:
    HSSPushable();
    ~HSSPushable();

    void pushMessage(std::string msg);
    void _setPyRunning(bool vl);

private:
    std::queue<std::string> _msgQueue;
    bool _PyRunning;
    std::mutex _PyRunning_mutex;
    std::mutex _msgQueue_mutex;
    std::thread _t;

    bool _isPyRunning();
    std::string _getMsgFromQueue();
    bool _isHaveWork();

    void _t_work();
};

#endif // HSSPUSHABLE_H
