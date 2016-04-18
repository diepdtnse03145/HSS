#include "hsspushable.h"
#include <cppformat/format.h>
#include <bits/stdc++.h>
#include <boost/python.hpp>

const char _pushCall[] = "import pusher\n"
                         "\n"
                         "pusher_client = pusher.Pusher(\n"
                         "  app_id='187319',\n"
                         "  key='0d2838d583ebb263b04c',\n"
                         "  secret='e18fe4131ada1dcea8f2',\n"
                         "  ssl=True\n"
                         ")\n"
                         "\n"
                         "pusher_client.trigger('test_channel', 'my_event', \"{}\")";


HSSPushable::HSSPushable() :
    _PyRunning{true},
    _t{&HSSPushable::_t_work,this}
{
    //    _t.detach();
}

HSSPushable::~HSSPushable()
{
    _setPyRunning(false);
    if(_t.joinable()) {
        _t.join();
    }
}

void HSSPushable::pushMessage(std::string msg)
{
    std::lock_guard<std::mutex> lock(_msgQueue_mutex);
    _msgQueue.push(msg);
}

bool HSSPushable::_isPyRunning()
{
    std::lock_guard<std::mutex> lock(_PyRunning_mutex);
    return _PyRunning;
}

void HSSPushable::_setPyRunning(bool vl)
{
    std::lock_guard<std::mutex> lock(_PyRunning_mutex);
    _PyRunning = vl;
}

std::string HSSPushable::_getMsgFromQueue()
{
    std::lock_guard<std::mutex> lock(_msgQueue_mutex);
    auto msg = _msgQueue.front();
    _msgQueue.pop();
    return msg;
}

bool HSSPushable::_isHaveWork()
{
    std::lock_guard<std::mutex> lock(_msgQueue_mutex);
    return !_msgQueue.empty();
}

void HSSPushable::_t_work()
{
    std::cout<<"Python init"<<std::endl;
    Py_Initialize();
    std::cout<<"Python import"<<std::endl;

    auto _namespace = boost::python::import("__main__").attr("__dict__");

    while (true) {
        if (_isPyRunning()) {
            std::this_thread::sleep_for(std::chrono::milliseconds{50});
            if (_isHaveWork()) {
                auto msg = _getMsgFromQueue();
                auto _pushCallMsg = fmt::format(std::string{_pushCall}, msg);
                try {
                    boost::python::exec(_pushCallMsg.c_str(), _namespace);
                }
                catch(const boost::python::error_already_set &)
                {
                    using namespace boost::python;

                    PyObject *exc,*val,*tb;
                    PyErr_Fetch(&exc,&val,&tb);
                    boost::python::handle<> hexc(exc), hval(boost::python::allow_null(val)), htb(boost::python::allow_null(tb));
                    boost::python::object traceback(boost::python::import("traceback"));

                    boost::python::object format_exception(traceback.attr("format_exception"));
                    boost::python::object formatted_list = format_exception(hexc, hval, htb);
                    boost::python::object formatted = boost::python::str("\n").join(formatted_list);

                    std::string const Result = extract<std::string>(formatted);
                    std::cout<<Result<<std::endl; //pop out a lot of error messages
                }
            }
        } else {
            return;
        }
    }
}
