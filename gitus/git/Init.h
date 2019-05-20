#pragma once

#include <string>

void initialise(const std::string& gitProjectPath);
void createFolder(const std::string& extension, const std::string& gitFolderPath);
void createHeadFile(const std::string& gitFolderPath);