#include "setting.h"
#include <bits/stdc++.h>

Setting::Setting()
{
    inputFromFile(HSS_SETTING_F);
}

void Setting::inputFromFile(const std::string &filePath)
{
    std::ifstream i{filePath};
    i >> _setting;
}

void Setting::outputToFile(const std::string &filePath)
{
    std::ofstream o{filePath, std::ios::trunc};
    o << std::setw(4) << _setting << std::endl;
}

