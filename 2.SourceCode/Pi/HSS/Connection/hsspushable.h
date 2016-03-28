#ifndef HSSPUSHABLE_H
#define HSSPUSHABLE_H

#include <string>
#include <boost/python.hpp>


class HSSPushable
{
public:
    HSSPushable();
    void pushMessage(std::string msg);

private:
    boost::python::object _namespace;
    static bool firstInit;
};

#endif // HSSPUSHABLE_H
