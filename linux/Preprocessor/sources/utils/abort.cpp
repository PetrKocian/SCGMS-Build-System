#include "abort.h"
#include "file_utils.h"

void abort(std::string error)
{
	std::cout << "Aborting, error: " << error << std::endl;

	std::error_code errorCode;
	if (!fs::remove_all(target, errorCode)) {
		std::cout << "Removing scgms directory: " << errorCode.message() << std::endl;
	}

	exit(0);
}