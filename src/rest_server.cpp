#include <served/served.hpp>
#include "rest_server.h"

rest_server::rest_server(served::multiplexer& mux):_mux(mux)
{

    _mux.handle("/handlers/{id}/{number:[0-9]+}")
        .get([](served::response & res, const served::request & req) {
            res << "id: ";
            res << req.params["id"];
            res << ", number: ";
            res << req.params["number"];
        })
        .post([](served::response & res, const served::request & req) {
            res << "id: ";
            res << req.params["id"];
            res << ", number: ";
            res << req.params["number"];

            std::cout << "POST: " << req.body() << std::endl;
        })
        .method(served::method::PATCH, [](served::response & res, const served::request & req) {
            res << "id: ";
            res << req.params["id"];
            res << ", number: ";
            res << req.params["number"];

            std::cout << "PATCH: " << req.body() << std::endl;
        });

    // GET /handlers/{id}
    _mux.handle("/handlers/{id}")
        .get([](served::response & res, const served::request & req) {
            res << "id: ";
            res << req.params["id"];
        });

    // GET /handlers
    _mux.handle("/handlers")
        .get([](served::response & res, const served::request &) {
            res << "You got served";
        });
}
