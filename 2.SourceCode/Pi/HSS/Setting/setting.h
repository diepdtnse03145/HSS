#ifndef SETTING_H
#define SETTING_H

#include <boost/any.hpp>
#include <map>

class Setting
{
public:
    Setting();

    const boost::any& operator[](const std::string& name);

private:
    std::map<std::string, boost::any> _value_map;
};

#endif // SETTING_H
