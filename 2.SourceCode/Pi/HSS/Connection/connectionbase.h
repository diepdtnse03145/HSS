#ifndef CONNECTIONBASE_H
#define CONNECTIONBASE_H

#include <string>
#include <queue>

class ConnectionBase
{
public:
    ConnectionBase();

protected:
    void _sendMsg(const std::string& msg);
    void _recvMsg(const std::string& msg);

    virtual void _hss_sendMsg() = 0;
    virtual void _hss_recvMsg(const std::string& msg) = 0;
    virtual bool _hss_isSending() = 0;
    std::queue<std::string> _sendQueue;
};

#endif // CONNECTIONBASE_H
