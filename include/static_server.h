#ifndef STATIC_SERVER_H
#define STATIC_SERVER_H

#include <served/served.hpp>

class static_server
{
    served::multiplexer& _mux;
    public:
    static_server(served::multiplexer& mux);
};

#endif
