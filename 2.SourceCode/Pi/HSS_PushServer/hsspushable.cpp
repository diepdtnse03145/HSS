#include "hsspushable.h"

const char _pushCall[] = "import pusher\n"
                         "\n"
                         "pusher_client = pusher.Pusher(\n"
                         "  app_id='187319',\n"
                         "  key='0d2838d583ebb263b04c',\n"
                         "  secret='e18fe4131ada1dcea8f2',\n"
                         "  ssl=True\n"
                         ")\n"
                         "\n"
                         "pusher_client.trigger('test_channel', 'my_event', {'message': 'hello world'})";

HSSPushable::HSSPushable()
{
    Py_Initialize();
    _namespace = boost::python::import("__main__").attr("__dict__");
}

void HSSPushable::pushMessage(std::string msg)
{
    boost::python::exec(_pushCall, _namespace);
}

