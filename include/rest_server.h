#ifndef REST_SERVER_H
#define REST_SERVER_H

#include <served/served.hpp>

class rest_server
{
    served::multiplexer& _mux;
    public:
    rest_server(served::multiplexer& mux);
};

#endif
