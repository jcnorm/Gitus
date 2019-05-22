#include "Add.h"
#include <boost/uuid/detail/sha1.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>

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

	boost::filesystem::fstream indexFile(boost::filesystem::current_path() / ".git" / "index");
	std::vector<std::string>* buffer = new std::vector<std::string>();
	size_t indexToModify = -1;

	while (!indexFile.eof()) { 
		getline(indexFile, line);
		buffer->push_back(line);
		if (line.find(pathspec) != std::string::npos) {
			indexToModify = buffer->size() - 1;
		}
	}
	indexFile.close();

	boost::filesystem::ofstream ofs(boost::filesystem::current_path() / ".git" / "index");
	for (int i = 0; i < buffer->size(); i++) {
		if (i == indexToModify) {
			ofs << std::hex << hash[0] << hash[1] << hash[2] << hash[3] << hash[4] << " " + pathspec << std::endl;
		} else {
			ofs << std::string(buffer->at(i)) << std::endl;
		}
	}

	if (indexToModify == -1) {
		ofs << std::hex << hash[0] << hash[1] << hash[2] << hash[3] << hash[4] << " " + pathspec << std::endl;
	}
	ofs.close();
}
