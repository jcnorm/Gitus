#include "Add.h"
#include <boost/uuid/detail/sha1.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

void add(const std::string& pathspec){
	boost::filesystem::ifstream fileToHash(boost::filesystem::current_path() / pathspec);
	std::string contentToHash = "";
	std::string line;
	while (!fileToHash.eof()) {
		getline(fileToHash, line);
		contentToHash += line;
		contentToHash += "\n";
	}
	fileToHash.close();

	boost::uuids::detail::sha1 sha1;
	sha1.process_bytes(contentToHash.data(), contentToHash.size());
	unsigned hash[5] = { 0 };
	sha1.get_digest(hash);


	boost::filesystem::ofstream indexFile;
	indexFile.open(boost::filesystem::current_path() / ".git" / "index", boost::filesystem::ofstream::app);
	indexFile << pathspec + "\t" << std::hex << hash[0] << hash[1] << hash[2] << hash[3] << hash[4] << std::endl;
	indexFile.close();
}
