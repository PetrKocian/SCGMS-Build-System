#pragma once

#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

// declare source and target paths
extern const fs::path cwd;
extern const fs::path src;
extern const fs::path target;


void removeEmptyDirectories(const fs::path& dir);
bool searchInFile(const fs::path& filePath, const std::string& searchStr);
bool searchInFolder(const fs::path& folderPath, const std::string& searchStr);
void renameFile(const fs::directory_entry file, std::string appendString);
void copyIniFile(const fs::path filePath);
std::string fileNameWithoutExtension(const fs::path& filePath);
std::string modifyDescriptor(fs::directory_entry& file, std::string searchString);
std::string insertIntoFile(const fs::path filePath, std::string appendAfter, std::string appendString);
