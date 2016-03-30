#ifndef ARDUINOENGINE_H
#define ARDUINOENGINE_H

#include "../Connection/serialconnection.h"
#include <boost/asio/steady_timer.hpp>
#include <boost/system/error_code.hpp>

class AndroidEngine;
class HSSPushable;

class ArduinoEngine : public SerialConnection
{
public:
    ArduinoEngine(Setting& setting,
                  HSSDatabase& db,
                  HSSPushable& pushsv,
                  boost::asio::io_service& io);

    void setAndroidEngine(AndroidEngine* engine);
    void _requestSensorValue(const boost::system::error_code& ec = boost::system::error_code{});

    int pirValue() const;
    int bellValue() const;
    int switchValue() const;

private:
    AndroidEngine* _andr;
    HSSPushable& _pushsv;
    boost::asio::steady_timer _sensorTimer;
    int _pirValue;
    int _bellValue;
    int _switchValue;

    void pushMessage(std::string msg);
    void _hss_recvMsg(const std::string &msg) override final;

    void setPirValue(int pirValue);
    void setBellValue(int bellValue);
    void setSwitchValue(int switchValue);

    void ad_requestPirVal();
    void ad_requestBellVal();
    void ad_requestSwitchVal();

    void pi_returnPirValue(int vl);
    void pi_returnBellValue(int vl);
    void pi_returnSwitchValue(int vl);

    void ad_init();
};

#endif // ARDUINOENGINE_H
