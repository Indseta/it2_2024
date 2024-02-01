#include <program/console.hpp>

#include <cam/avec.hpp>
#include <cam/fvec.hpp>

#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace py {
	template<typename... Args>
	void run(const std::string &src_fp, Args... args) {
		std::string command = "python -u ../src/" + src_fp;

		auto add_arg = [&command](const auto &arg) {
			std::stringstream ss;
			ss << arg;
			command += ' ' + std::regex_replace(ss.str(), std::regex(" "), "\\\\s");
		};

		(add_arg(args), ...);

		system(command.c_str());
	}
}

int main() {
	cmd::clear();
	
	py::run("py/app.py");

	return EXIT_SUCCESS;
}