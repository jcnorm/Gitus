#pragma once

#include <string>
#include <boost/filesystem.hpp>

class Init {
	std::string m_GIT_DIR;
public:
	Init(std::string gitFolderPath);
	~Init();
	void createGitFolder();
	void createHeadsFolder();
	void createTagsFolder();

};

Init::Init(std::string gitFolderPath)
	: m_GIT_DIR(gitFolderPath) {}

Init::~Init(){}

void Init::createGitFolder() {

}

void Init::createHeadsFolder() {

}

void Init::createTagsFolder() {

}