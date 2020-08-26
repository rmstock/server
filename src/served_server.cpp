/*
 * Copyright (C) 2014 MediaSift Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <served/served.hpp>
#include <served/request_error.hpp>
#include <served/status.hpp>
#include <served/methods.hpp>
#include <iostream>
#include "rest_server.h"
#include "static_server.h"
#include "udp_server.h"

int main(int, char const**)
{
	served::multiplexer mux;

	std::cout << "Try this example with:" << std::endl;
	std::cout << " curl http://localhost:8123/handlers" << std::endl;
	std::cout << " curl http://localhost:8123/handlers/test" << std::endl;
	std::cout << " curl http://localhost:8123/handlers/test/10" << std::endl;
	std::cout << " curl http://localhost:8123/handlers/test/NaN" << std::endl;

	rest_server rest_serv(mux);
	static_server stat_serv(mux);
	served::net::server server("127.0.0.1", "8123", mux);
	server.run(10, false);//10 threads, non-blocking;
	//Next line will be reached if we don't stop it. 

	udp_server udp_serv;
	server.stop();
	return (EXIT_SUCCESS);
}
