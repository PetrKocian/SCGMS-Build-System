#include <scgms/rtl/FilterLib.h>
#include <scgms/rtl/referencedImpl.h>
#include <scgms/utils/winapi_mapping.h>
#include <scgms/utils/string_utils.h>
#include <filters/generated/combined_descriptors.h>
#include <filters/config.h>
#include "scgms.h"

#if defined(FREERTOS)
#include <print.h>
#endif

#if defined(WASM) || defined (ESP32)
void print(const char * str)
{
	printf("%s\r\n", str);
}
#endif

scgms::SFilter_Executor Global_Filter_Executor;

void create_level_event(int level_input)
{
	scgms::UDevice_Event event{ scgms::NDevice_Event_Code::Level };
	event.level() = level_input;
	if(Global_Filter_Executor)
	{
		Global_Filter_Executor.Execute(std::move(event));
	}
}

int build_filter_chain(const char*  configuration_input)
{
	const char* config;
	if(configuration_input == NULL)
	{
		config = config_data;
		print("Creating SCGMS filter chain from config.h");	
	}
	else
	{
		print("Creating SCGMS filter chain from input");	
	}
	print("------------------------------------------");
	print("Configuration:");
	print("------------------------------------------");
	refcnt::Swstr_list errors = refcnt::Swstr_list{};
	errors.get();
	scgms::SPersistent_Filter_Chain_Configuration configuration{};
	if (configuration == NULL)
	{
		print("Failed to construct SPersistent_Filter_Chain_Configuration");
		return -1;
	}

	print(config_data);
	print("------------------------------------------");

	print("Config errors:");
	configuration->Load_From_Memory(config_data, strlen(config_data), errors.get());
	print("------------------------------------------");

	print("Filter executor errors:");
	Global_Filter_Executor = scgms::SFilter_Executor{ configuration.get(), nullptr, nullptr, errors };
	errors.for_each([](auto str) {auto newstr = Narrow_WString(str);print(newstr.c_str());});
	print("------------------------------------------");

	if(Global_Filter_Executor)
	{
		print("Filter chain is ready to execute:");
		print("------------------------------------------");
	}
	else
	{
		print("Error constructing filter chain");
		print("------------------------------------------");
		return -1;
	}

	return 0;
}