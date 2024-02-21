#include "utils/file_utils.h"
#include "utils/abort.h"
#include "utils/file_templates.h"

#include <sstream>
#include <vector>



int main(int argc, char** argv) {

	// check if input directory exists
	if (!fs::exists(src) || fs::is_empty(src))
	{
		fs::create_directory(src);
		abort("Provide filter and configuration files in input folder");
	}

	// clean scgms directory
	std::error_code errorCode;
	if (!fs::remove_all(target, errorCode)) {
		std::cout << "Removing " + target.filename().string() + " directory: " << errorCode.message() << std::endl;
	}

	// copy all filter files to filters directory
	try {
		fs::create_directories(target / "filters");
		fs::copy(src, target / "filters", fs::copy_options::recursive);
	}
	catch (const std::exception & exc) {
		abort("Failed to copy filter files:");
		std::cerr << exc.what();
	}
	// copy .ini file contents to string
	bool foundIni = false;
	for (auto file : fs::directory_iterator(src))
	{
		const std::string fileExtension = file.path().extension().string();
		if (fileExtension == ".ini")
		{
			copyIniFile(file.path());
			foundIni = true;
			break;
		}
	}
	if (!foundIni)
	{
		std::cout << "Warning: .ini configuration file not provided" << std::endl;
	}

	// delete any non .cpp .c .h files as they won't be recognized by build tools for embedded targets
	for (auto file : fs::recursive_directory_iterator(target))
	{
		const std::string fileExtension = file.path().extension().string();
		if (!(fileExtension == ".cpp" || fileExtension == ".h") && !fs::is_directory(file))
		{
			if (!fs::remove(file.path()))
			{
				std::cout << errorCode.message() << std::endl;
			}
		}
	}

	// delete DllMain files
	for (auto file : fs::recursive_directory_iterator(target))
	{
		if (searchInFile(file.path(), "DllMain"))
		{
			if (!fs::remove(file.path()))
			{
				std::cout << errorCode.message() << std::endl;
			}
		}
	}

	// remove empty directories
	removeEmptyDirectories(target);

	// holds new function names 
	std::vector<std::string> docreateFunctionNames;
	std::vector<std::string> getdescriptorsFunctionNames;
	std::vector<fs::path> descriptorFileNames;

	// modify descriptor source files of filters and save new function names
	std::string folderName = "";
	for (auto file : fs::recursive_directory_iterator(target))
	{
		std::string folderName = "";
		const std::string fileExtension = file.path().extension().string();
		if (searchInFile(file, "do_create_filter") && fileExtension == ".cpp")
		{
			folderName = modifyDescriptor(file, "do_create_filter");
			docreateFunctionNames.push_back("do_create_filter" + folderName);

		}
		if (searchInFile(file, "do_get_filter_descriptors") && fileExtension == ".cpp")
		{
			folderName = modifyDescriptor(file, "do_get_filter_descriptors");
			getdescriptorsFunctionNames.push_back("do_get_filter_descriptors" + folderName);
		}
		if (folderName != "")
		{
			descriptorFileNames.push_back(file.path());
			renameFile(file, folderName);
		}
	}

	// generate combined descriptors header file
	fs::create_directories(target / "filters/generated");
	std::ofstream comb_desc_h(target / "filters/generated/combined_descriptors.h");
	if (!comb_desc_h.is_open())
	{
		abort("Could not open " + target.string() + "/filters/generated/combined_descriptors.h for writing");
	}
	comb_desc_h << "#pragma once" << std::endl;

	// add includes
	for (auto sourceFile : descriptorFileNames)
	{
		sourceFile.replace_extension(".h");
		std::string include = "#include <" + sourceFile.lexically_relative(target).string() + ">";
		comb_desc_h << include << std::endl;
	}

	// add function definitions
	std::string line;
	std::istringstream file_template(combined_descriptors_h_template);
	comb_desc_h << combined_descriptors_h_template;
	comb_desc_h.close();


	// generate combined descriptors source file
	std::ofstream comb_desc_c(target / "filters/generated/combined_descriptors.cpp");
	if (!comb_desc_c.is_open())
	{
		abort("Could not open " + target.string() + "/filters/generated/combined_descriptors.c for writing");
	}

	// top of source file
	comb_desc_c << comb_desc_c_top;

	// get descriptors
	for (auto functionName : getdescriptorsFunctionNames) {
		comb_desc_c << "	get_descriptors(" << functionName << ");" << std::endl;
	}

	// middle of file
	comb_desc_c << comb_desc_c_middle;

	// create filter body
	for (auto functionName : docreateFunctionNames) {
		comb_desc_c << functionName;

		if (functionName != docreateFunctionNames.back()) {
			comb_desc_c << between_do_create_filter; // there is another do create filter coming
		}
		else {
			comb_desc_c << comb_desc_c_bottom; // last one, finish the file
		}
	}

	std::cout << "Files generated successfully" << std::endl;
	return 0;
}