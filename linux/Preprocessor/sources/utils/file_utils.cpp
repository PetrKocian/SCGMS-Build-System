#include "file_utils.h"
#include "abort.h"
#include <sstream>

// define source and target paths
const fs::path cwd = fs::current_path();
const fs::path src = cwd / "input";
const fs::path target = cwd / "output";

void removeEmptyDirectories(const fs::path& dir) {
	if (!fs::exists(dir) || !fs::is_directory(dir)) {
		std::cerr << "Invalid directory: " << dir << std::endl;
		return;
	}

	for (const auto& entry : fs::directory_iterator(dir)) {
		if (fs::is_directory(entry)) {
			removeEmptyDirectories(entry.path());
		}
	}

	// Check if the current directory is empty and remove it
	if (fs::is_empty(dir)) {
		fs::remove(dir);
	}
}

bool searchInFile(const fs::path& filePath, const std::string& searchStr) {
	bool found = false;

	if (fs::is_directory(filePath))
	{
		return found;
	}

	std::ifstream file(filePath);


	if (!file.is_open()) {
		std::cerr << "Error opening the file: " << filePath.string() << std::endl;
		return found;
	}

	std::string line;
	int lineNumber = 0;

	while (std::getline(file, line)) {
		lineNumber++;

		if (line.find(searchStr) != std::string::npos) {
			found = true;
		}
	}

	file.close();
	return found;
}

std::string fileNameWithoutExtension(const fs::path& filePath)
{
	fs::path filePathNonConst = filePath;
	filePathNonConst.replace_extension();
	return filePathNonConst.string();
}

void renameFile(const fs::directory_entry file, std::string appendString)
{
	const std::string fileExtension = file.path().extension().string();
	std::string newPath = fileNameWithoutExtension(file.path()) + appendString + fileExtension;
	fs::rename(file.path(), newPath);
}

std::string insertIntoFile(const fs::path filePath, std::string appendAfter, std::string appendString)
{
	std::string functionDeclaration;
	// open original descriptor file
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error opening the file: " << filePath.string() << std::endl;
		return "";
	}

	// open the new file for writing (add a '_' suffix to avoid name conflict)
	std::string newPath = filePath.string() + "_";
	std::ofstream newFile(newPath);


	// copy old file into new file, line by line
	std::string line;
	bool inserted = false;
	while (std::getline(file, line)) {
		auto pos = line.find(appendAfter);
		if (pos != std::string::npos && !inserted) {
			// append the string
			line.insert(pos + appendAfter.length(), appendString);
			// if modifying descriptor file, the line is declaration which then needs to go into the header
			functionDeclaration = line;
			inserted = true;
		}
		newFile << line << std::endl;
	}

	file.close();
	fs::remove(filePath);
	newFile.close();
	fs::rename(newPath, filePath);

	// "void function(){" remove the curly bracket if it is present and append ';'
	auto pos = functionDeclaration.find("{");
	if (pos != std::string::npos) {
		functionDeclaration.erase(pos, 1);
	}
	functionDeclaration.append(";");
	return functionDeclaration;
}

// copies .ini file and writes it as a const char* config_data in a new file
void copyIniFile(const fs::path filePath)
{
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error opening .ini file: " << filePath.string() << std::endl;
		return;
	}

	// create config.h where the configuration.ini will be located as a string
	std::ofstream iniFile(target / "filters/config.h");
	iniFile << "#pragma once" << std::endl;
	iniFile << "const char* config_data =" << std::endl;

	// write the .ini file to the string, remove comments (lines beginning with ;)
	std::string line;
	while (std::getline(file, line)) {
		if (line[0] == ';')
		{
			continue;
		}
		iniFile << '"' << line << "\\r\\n" << '"' << std::endl;
	}

	iniFile << ';';

	iniFile.close();
	file.close();
}

// modifies the descriptor file, searchString is name of the function to which the name of folder will be appended
std::string modifyDescriptor(fs::directory_entry& file, std::string searchString)
{
	std::string folderName = "";
	fs::path parentPath = file.path().parent_path();
	fs::path currentDirPath = file.path();
	// find root filter folder, it is then appended to the function names
	while (parentPath.filename().string() != "filters")
	{
		currentDirPath = parentPath;
		parentPath = parentPath.parent_path();
	}
	if (fs::is_directory(currentDirPath))
	{
		// add '_' prefix to folder name and abort if it contains characters which are not allowed as identifiers in C++
		folderName = "_" + currentDirPath.filename().string();
		for (char c : folderName)
		{
			if (!(std::isalnum(c) || c == '_'))
			{
				std::string s(1, c);
				abort("Folder name contains non-allowed character '" + s + "' , please change it:\r\n" + currentDirPath.string());
			}
		}
		/*
		folderName.erase(std::remove_if(folderName.begin(), folderName.end(),
			[](unsigned char c) { return !(std::isalnum(c) || c =='_'); }),
			folderName.end());*/

		// change the name of the function in the descriptor (do_create_filter/get_filter_descriptors) 
		std::string declaration = insertIntoFile(file, searchString, folderName);

		// write the declaration of the function into associated header
		fs::path headerPath(fileNameWithoutExtension(file.path()) + ".h");
		if (fs::exists(headerPath))
		{
			// necessary include
			if (!searchInFile(headerPath, "rtl/FilterLib.h"))
			{
				insertIntoFile(headerPath, "", "\r\n#include <rtl/FilterLib.h> // GENERATED\r\n");
			}
			// function declaration
			std::ofstream header(headerPath, std::ios::app);
			if (header.is_open())
			{
				header << std::endl << declaration;
			}
		}
		else
		{
			abort("Could not find descriptor header file for:\r\n" + file.path().string());
		}
	}
	return folderName;
}


bool searchInFolder(const fs::path & folderPath, const std::string & searchStr) {
	bool found = false;
	for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
		if (fs::is_regular_file(entry.path())) {
			if (searchInFile(entry.path(), searchStr))
			{
				found = true;
			}
		}
	}
	return found;
}