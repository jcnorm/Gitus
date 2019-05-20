#include "Init.h"
#include <boost/filesystem.hpp>

void initialise(const std::string &gitProjectPath) {
	boost::filesystem::path gitFolderPath = gitProjectPath + "/.git";
	boost::filesystem::create_directory(gitFolderPath);
	boost::filesystem::create_directory(gitFolderPath / "refs");
	boost::filesystem::create_directory(gitFolderPath / "refs" / "heads");
	boost::filesystem::create_directory(gitFolderPath / "objects");
	boost::filesystem::ofstream headFile(gitFolderPath / "HEAD");
	headFile << "ref:	refs/heads/master";
	headFile.close();
}