#pragma once

#include <string>
#include <boost/filesystem.hpp>

class Init {
	boost::filesystem::path m_project_dir;
	boost::filesystem::path m_git_dir;
public:
	Init(std::string gitFolderPath);
	~Init();
	void createGitFolder();
	void createFolder(std::string extension);
	void createHeadFile();
};