#ifndef SETTING_H
#define SETTING_H

#include "../hss_global.h"
#include <json.hpp>

class Setting
{
public:
    Setting();

    template <typename T>
    T value(const std::string& name)
    {
        return _setting[name];
    }

    template <typename T>
    void setValue(const std::string& name, const T& value)
    {
        _setting[name] = value;
        outputToFile(HSS_SETTING_FILE);
    }

    void inputFromFile(const std::string& filePath);
    void outputToFile(const std::string& filePath);

private:
    nlohmann::json _setting;
};

#endif // SETTING_H
