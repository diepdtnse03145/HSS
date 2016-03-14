#ifndef CONNECTIONBASE_H
#define CONNECTIONBASE_H

#include "../Setting/setting.h"

#include <string>
#include <queue>

class ConnectionBase
{
public:
    ConnectionBase(Setting& setting);

protected:
    void _sendMsg(const std::string& msg);
    void _recvMsg(const std::string& msg);

    virtual void _hss_sendMsg() = 0;
    virtual void _hss_recvMsg(const std::string& msg) = 0;
    virtual bool _hss_isSending() = 0;
    std::queue<std::string> _sendQueue;

    template<typename T>
    T _getOptionsValue(const std::string& name)
    {
        return _setting.value<T>(name);
    }

    template <typename T>
    void _setOptionsValue(const std::string& name, const T& value)
    {
        _setting.setValue(name, value);
    }

private:
    Setting& _setting;
};

#endif // CONNECTIONBASE_H
