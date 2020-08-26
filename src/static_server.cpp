#include "static_server.h"
#include <fstream>
#include <filesystem>
#include "tools.h"

#include <string>

static_server::static_server(served::multiplexer& mux): _mux(mux)
{
	_mux.handle("/www/")
		.get([&](served::response & res, const served::request & req) {
			std::string path = req.url().path();
			if (!path.empty() && path.back() == '/') { path += "index.html"; }
			path.erase(0, 1);
			//TODO check for bad paths, such as root, empty, or ".."
			//TODO cache file calls, assume static files don't change while server is running.
			std::ifstream ifs(path);
			if (!ifs.good())
			{
				printf("File: %s not found.\n", path.c_str());
			}
			res.set_body(std::string(
				(std::istreambuf_iterator<char>(ifs) ),
				(std::istreambuf_iterator<char>()    )
			));
			//res.set_header("content-type", "image/png");
			res.set_header("content-type", mime_type(std::filesystem::path(path).extension()));
		});
}
