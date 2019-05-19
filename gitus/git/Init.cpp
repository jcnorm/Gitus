#include <string>
#include <boost/filesystem.hpp>
#include <iostream>

#include "Init.h"

Init::Init(std::string gitFolderPath)
	: m_project_dir(gitFolderPath)
{
	m_git_dir = m_project_dir / ".git";
	Init::createGitFolder();
}

Init::~Init() {}

void Init::createGitFolder() {
	if (!exists(m_git_dir))
		boost::filesystem::create_directory(m_git_dir);
	Init::createFolder("refs/heads");
	Init::createFolder("refs/tags");
	Init::createFolder("objects");
	Init::createHeadFile();
}

void Init::createFolder(std::string extension) {
	if (!exists(m_git_dir / extension))
		boost::filesystem::create_directory(m_git_dir / extension);
}

void Init::createHeadFile() {
	if (!exists(m_git_dir / "HEAD")) {
		boost::filesystem::ofstream headFile(m_git_dir / "HEAD");
		headFile << "ref:	refs/heads/master";
		headFile.close();
	}
}