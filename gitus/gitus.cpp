#include <iostream>
#include "git/Init.h"
#include "git/Add.h"

int main(int argc, const char* argv[]) {
	if (argc == 2 && std::string(argv[1]) == "-help") {
		std::cout << "usage: gitus <command>[<args>]" << std::endl;
		std::cout << "These are common gitus commands used in various situations :" << std::endl;
		std::cout << "init\tCreate an empty Git repository or reinitialize an existing one" << std::endl;
		std::cout << "add\tAdd file contents to the index" << std::endl;
		std::cout << "commit\tRecord changes to the repository" << std::endl;
	} else if (argc == 3 && std::string(argv[2]) == "-help") {
		if (std::string(argv[1]) == "init") {
			std::cout << "usage: gitus init" << std::endl;
		}
		else if (std::string(argv[1]) == "add") {
			std::cout << "usage: gitus add <pathspec>" << std::endl;
		}
		else if (std::string(argv[1]) == "commit") {
			std::cout << "usage: gitus commit <msg> <author> <email>" << std::endl;
		}
	} else if (argc == 2 && std::string(argv[1]) == "init") {
		initialise();
	} else if (argc == 3 && std::string(argv[1]) == "add") {
		add(std::string(argv[2]));
	}

	return 0;
}