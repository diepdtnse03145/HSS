#include "setting.h"
#include <boost/program_options.hpp>
#include <bits/stdc++.h>

Setting::Setting()
{
    boost::program_options::options_description desc{"Setting"};
    desc.add_options()
            ("arduino_port", boost::program_options::value<std::string>(), "Adruino Port")
            ("tcp_sv_port", boost::program_options::value<unsigned short>(), "TCP Server port");
    boost::program_options::variables_map vm;
    std::filebuf fb;
    if (fb.open ("setting.ini",std::ios::in))
    {
        std::istream config_file(&fb);
        boost::program_options::store(boost::program_options::parse_config_file(config_file, desc), vm);
        _value_map["arduino_port"] = vm["arduino_port"].as<std::string>();
        _value_map["tcp_sv_port"] = vm["tcp_sv_port"].as<unsigned short>();
    }
}

const boost::any &Setting::operator[](const std::string &name)
{
    return _value_map[name];
}
