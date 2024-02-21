#include "combined_descriptors.h"
#include <scgms/utils/descriptor_utils.h>

using FilterDescriptorFunction = HRESULT(*)(scgms::TFilter_Descriptor**, scgms::TFilter_Descriptor**);

CLoaded_Filters loaded_filters{};

CLoaded_Filters::CLoaded_Filters()
{
	load_descriptors();
}

void CLoaded_Filters::load_descriptors()
{
    auto get_descriptors = [&](FilterDescriptorFunction get_filter_descriptors)
	{
		scgms::TFilter_Descriptor *desc_begin, *desc_end;
		bool result = get_filter_descriptors(&desc_begin, &desc_end) == S_OK;
		if (result)
		{
			std::copy(desc_begin, desc_end, std::back_inserter(mFilter_Descriptors));
		}
	};
		get_descriptors(do_get_filter_descriptors_modify_filter);
	get_descriptors(do_get_filter_descriptors_data_filter);
	get_descriptors(do_get_filter_descriptors_print_filter);
}

HRESULT CLoaded_Filters::get_filter_descriptors_body(scgms::TFilter_Descriptor **begin, scgms::TFilter_Descriptor **end)
{
	return do_get_descriptors<scgms::TFilter_Descriptor>(mFilter_Descriptors, begin, end);
}

HRESULT get_all_descriptors(scgms::TFilter_Descriptor **begin, scgms::TFilter_Descriptor **end)
{
	return loaded_filters.get_filter_descriptors_body(begin, end);
}

scgms::SFilter create_filter_body(const GUID &id, scgms::IFilter *next_filter)
{
	scgms::SFilter result;
	scgms::IFilter *filter;

	if (do_create_filter_modify_filter(&id, next_filter, &filter) == S_OK)
	{
		result = refcnt::make_shared_reference_ext<scgms::SFilter, scgms::IFilter>(filter, false);
		return result;
	}
	if (do_create_filter_data_filter(&id, next_filter, &filter) == S_OK)
	{
		result = refcnt::make_shared_reference_ext<scgms::SFilter, scgms::IFilter>(filter, false);
		return result;
	}
	if (do_create_filter_print_filter(&id, next_filter, &filter) == S_OK)
	{
		result = refcnt::make_shared_reference_ext<scgms::SFilter, scgms::IFilter>(filter, false);
		return result;
	}

	return result;
}

void describe_loaded_filters(refcnt::Swstr_list error_description) {
}

void* resolve_generated_symbol(const char *symbol_name) noexcept
{
    if (strcmp(symbol_name, "get_filter_descriptors") == 0) 
    {
        return reinterpret_cast<void*>(get_all_descriptors);
    }

    return nullptr;
}
