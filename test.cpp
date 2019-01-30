#include <iostream>
#include "cxxopts.hpp"

int main(int argc, char** argv)
{
	cxxopts::Options options("cxxopts_test");
	try {
		std::string file;

		options.add_options()
			("file", "File name", cxxopts::value<std::string>(file))
			("output", "output file", cxxopts::value<std::string>())
			("d,debug", "Enable debugging")
			("h,help", "Print help")
			;
		options.parse_positional({ "file", "output" });

		auto result = options.parse(argc, argv);

		if (result.count("help"))
		{
			std::cout << options.help({}) << std::endl;
			return 0;
		}

		std::cout << file << std::endl;
		std::string output = result["output"].as<std::string>();
		std::cout << output << std::endl;
	}
	catch (cxxopts::OptionException &e) {
		std::cout << options.usage() << std::endl;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}