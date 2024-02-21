/**
 * SmartCGMS - continuous glucose monitoring and controlling framework
 * https://diabetes.zcu.cz/
 *
 * Copyright (c) since 2018 University of West Bohemia.
 *
 * Contact:
 * diabetes@mail.kiv.zcu.cz
 * Medical Informatics, Department of Computer Science and Engineering
 * Faculty of Applied Sciences, University of West Bohemia
 * Univerzitni 8, 301 00 Pilsen
 * Czech Republic
 *
 *
 * Purpose of this software:
 * This software is intended to demonstrate work of the diabetes.zcu.cz research
 * group to other scientists, to complement our published papers. It is strictly
 * prohibited to use this software for diagnosis or treatment of any medical condition,
 * without obtaining all required approvals from respective regulatory bodies.
 *
 * Especially, a diabetic patient is warned that unauthorized use of this software
 * may result into severe injure, including death.
 *
 *
 * Licensing terms:
 * Unless required by applicable law or agreed to in writing, software
 * distributed under these license terms is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 * a) This file is available under the Apache License, Version 2.0.
 * b) When publishing any derivative work or results obtained using this software, you agree to cite the following paper:
 *    Tomas Koutny and Martin Ubl, "SmartCGMS as a Testbed for a Blood-Glucose Level Prediction and/or
 *    Control Challenge with (an FDA-Accepted) Diabetic Patient Simulation", Procedia Computer Science,
 *    Volume 177, pp. 354-362, 2020
 */

#include "FilterLib.h"
#include "../utils/string_utils.h"
#include <scgms/src/persistent_chain_configuration.h>
#include <scgms/src/filter_configuration_executor.h>
#include <scgms/src/filter_parameter.h>
#include <scgms/src/configuration_link.h>
#include <scgms/rtl/scgmsLib.h>

#include <wchar.h>
#include "manufactory.h"


namespace scgms
{

	namespace imported
	{
		// all these vars have _external suffix not to confuse linker when building the libraries
		scgms::TGet_Filter_Descriptors get_filter_descriptors_external = scgms::factory::resolve_symbol<scgms::TGet_Filter_Descriptors>("get_filter_descriptors");
	}

	SFilter::SFilter() : refcnt::SReferenced<IFilter>() {}

	SFilter::SFilter(IFilter *filter) : refcnt::SReferenced<IFilter>(filter) {}

	HRESULT SFilter::Send(scgms::UDevice_Event &event)
	{
		if (!event)
			return E_INVALIDARG;

		scgms::IDevice_Event *raw_event = event.get();
		event.release();
		return get()->Execute(raw_event);
	}

	NParameter_Type SFilter_Parameter::type()
	{
		NParameter_Type result = NParameter_Type::ptInvalid;
		get()->Get_Type(&result);
		return result;
	}

	const wchar_t *SFilter_Parameter::configuration_name()
	{
		wchar_t *result = nullptr;
		get()->Get_Config_Name(&result);
		return result;
	}

	std::wstring SFilter_Parameter::as_wstring(HRESULT &rc, bool read_interpreted)
	{
		std::wstring result;

		refcnt::wstr_container *wstr;
		rc = get()->Get_WChar_Container(&wstr, read_interpreted);
		if ((rc == S_OK) || ((rc == E_NOT_SET) && !read_interpreted))
		{
			// if the WChar_Container_To_WString should fail, e.g. on bad alloc, the wstr could leak
			// if not guarded with RAII
			refcnt::Swstr_container mem_guard = refcnt::make_shared_reference_ext<refcnt::Swstr_container, refcnt::wstr_container>(wstr, true);
			wstr->Release();

			result = refcnt::WChar_Container_To_WString(mem_guard.get());
		}

		return result;
	}

	HRESULT SFilter_Parameter::set_wstring(const std::wstring &str)
	{
		return set_wstring(str.c_str());
	}

	HRESULT SFilter_Parameter::set_wstring(const wchar_t *str)
	{
		std::shared_ptr<refcnt::wstr_container> wstr = refcnt::WString_To_WChar_Container_shared(str);
		return get()->Set_WChar_Container(wstr.get());
	}

	int64_t SFilter_Parameter::as_int(HRESULT &rc)
	{
		int64_t result = 0;
		rc = get()->Get_Int64(&result); // if fails, it returns 0
		return result;
	}

	double SFilter_Parameter::as_double(HRESULT &rc)
	{
		double result = std::numeric_limits<double>::quiet_NaN();
		rc = get()->Get_Double(&result); // if fails, it returns nan
		return result;
	}

	HRESULT SFilter_Parameter::set_double_array(const std::vector<double> &values)
	{
		auto parameters = refcnt::Create_Container_shared<double>(const_cast<double *>(values.data()), const_cast<double *>(values.data() + values.size()));
		return get()->Set_Model_Parameters(parameters.get());
	}

	std::vector<double> SFilter_Parameter::as_double_array(HRESULT &rc)
	{
		std::vector<double> result;
		scgms::IModel_Parameter_Vector *container;
		rc = get()->Get_Model_Parameters(&container);
		if (rc == S_OK)
		{
			result = refcnt::Container_To_Vector<double>(container);
			container->Release();
		}

		return result;
	}

	bool SFilter_Parameter::as_bool(HRESULT &rc)
	{
		bool result = false;
		BOOL uint8;
		rc = get()->Get_Bool(&uint8);
		if (rc == S_OK)
			result = uint8 != FALSE;

		return result;
	}

	HRESULT SFilter_Parameter::set_bool(const bool value)
	{
		return get()->Set_Bool(value ? TRUE : FALSE);
	}

	std::vector<int64_t> SFilter_Parameter::as_int_array(HRESULT &rc)
	{
		std::vector<int64_t> result;

		scgms::time_segment_id_container *container;
		rc = get()->Get_Time_Segment_Id_Container(&container);
		if (rc == S_OK)
		{
			result = refcnt::Container_To_Vector<int64_t>(container);
			container->Release();
		}

		return result;
	}

	HRESULT SFilter_Parameter::set_int_array(const std::vector<int64_t> &values)
	{
		int64_t *casted_data = const_cast<int64_t *>(values.data());
		refcnt::SVector_Container<int64_t> container = refcnt::Create_Container_shared<int64_t>(casted_data, casted_data + values.size());
		if (container)
			return get()->Set_Time_Segment_Id_Container(container.get());
		else
			return E_FAIL;
	}

	GUID SFilter_Parameter::as_guid(HRESULT &rc)
	{
		GUID result;
		rc = get()->Get_GUID(&result);
		return result;
	}

	HRESULT SFilter_Parameter::set_GUID(const GUID &guid)
	{
		return get()->Set_GUID(&guid);
	}

	bool get_filter_descriptor_by_id(const GUID &id, TFilter_Descriptor &desc)
	{
		TFilter_Descriptor *desc_begin, *desc_end;

		bool result = imported::get_filter_descriptors_external(&desc_begin, &desc_end) == S_OK;
		if (result)
		{
			printf("RESULT OK\n");
			result = false; // we have to find the filter yet
			for (auto iter = desc_begin; iter != desc_end; iter++)
				if (iter->id == id)
				{
					// desc = *iter;							assign const won't work with const members and custom operator= will result into undefined behavior as it has const members (so it does not have to be const itself)
					memcpy(&desc, iter, sizeof(decltype(desc))); //=> memcpy https://stackoverflow.com/questions/9218454/struct-with-const-member
					result = true;
					break;
				}
		}

		return result;
	}

	TFilter_Descriptor SFilter_Configuration_Link::descriptor()
	{
		scgms::TFilter_Descriptor filter_desc = scgms::Null_Filter_Descriptor;

		GUID filter_id;
		if (operator bool())
			if (get()->Get_Filter_Id(&filter_id) == S_OK)
				scgms::get_filter_descriptor_by_id(filter_id, filter_desc);

		return filter_desc;
	}

	SFilter_Parameter SFilter_Configuration_Link::Add_Parameter(const scgms::NParameter_Type type, const wchar_t *conf_name)
	{
		SFilter_Parameter result;
		scgms::IFilter_Parameter *parameter;
		if (create_filter_parameter(type, conf_name, &parameter) == S_OK)
		{
			if (get()->add(&parameter, &parameter + 1) == S_OK)
				result = refcnt::make_shared_reference_ext<SFilter_Parameter, IFilter_Parameter>(parameter, false);
		}

		return result;
	}

	scgms::SFilter_Parameter scgms::internal::Create_Filter_Parameter(const scgms::NParameter_Type type, const wchar_t *config_name)
	{
		scgms::SFilter_Parameter result;
		scgms::IFilter_Parameter *new_parameter;
		if (create_filter_parameter(type, config_name, &new_parameter) == S_OK)
			result = refcnt::make_shared_reference_ext<scgms::SFilter_Parameter, scgms::IFilter_Parameter>(new_parameter, false);
		return result;
	}

	scgms::SFilter_Configuration_Link internal::Create_Configuration_Link(const GUID &id)
	{
		scgms::SFilter_Configuration_Link result;
		scgms::IFilter_Configuration_Link *link;
		if (create_filter_configuration_link(&id, &link) == S_OK)
		{
			result = refcnt::make_shared_reference_ext<scgms::SFilter_Configuration_Link, scgms::IFilter_Configuration_Link>(link, false);
		}

		return result;
	}

	SPersistent_Filter_Chain_Configuration::SPersistent_Filter_Chain_Configuration()
	{
		IPersistent_Filter_Chain_Configuration *configuration;
		if (create_persistent_filter_chain_configuration(&configuration) == S_OK)
			reset(configuration, [](IPersistent_Filter_Chain_Configuration *obj_to_release)
				  { if (obj_to_release != nullptr) obj_to_release->Release(); });
	}

	SPersistent_Filter_Chain_Configuration::operator SFilter_Chain_Configuration()
	{
		SFilter_Chain_Configuration result;

		if (operator bool())
		{
			scgms::IFilter_Chain_Configuration *raw = get();
			result.reset(raw, [](IFilter_Chain_Configuration *obj_to_release)
						 { if (obj_to_release != nullptr) obj_to_release->Release(); });
			raw->AddRef();
		}

		return result;
	}

	SFilter_Executor::SFilter_Executor(refcnt::SReferenced<scgms::IFilter_Chain_Configuration> configuration, scgms::TOn_Filter_Created on_filter_created, const void *on_filter_created_data, refcnt::Swstr_list error_description, scgms::IFilter *output)
	{
		scgms::IFilter_Executor *executor;
		if (Succeeded(execute_filter_configuration(configuration.get(), on_filter_created, on_filter_created_data, output, &executor, error_description.get())))
			reset(executor, [](scgms::IFilter_Executor *obj_to_release)
				  { if (obj_to_release != nullptr) obj_to_release->Release(); });
	}

	HRESULT SFilter_Executor::Execute(scgms::UDevice_Event &&event)
	{
		scgms::IDevice_Event *raw_event = event.get();
		event.release();
		return get()->Execute(raw_event);
	}

	CBase_Filter::CBase_Filter(scgms::IFilter *output, const GUID &device_id) noexcept : mOutput(output), mDevice_ID(device_id)
	{
		// ctor must be non-throwing to allow real-time and/or embedded development! Hence, we'll detect the error during the configuration.
		// if (!mOutput)
		//	throw std::runtime_error{ "Attempted to construct a filter without valid output!" };
	}

	CBase_Filter::~CBase_Filter() noexcept
	{
		//
	}

	HRESULT CBase_Filter::Emit_Info(const scgms::NDevice_Event_Code code, const wchar_t *msg, const uint64_t segment_id) noexcept
	{
		scgms::UDevice_Event event{code};
		if (event)
		{
			event.device_id() = mDevice_ID;
			event.info.set(msg);
			event.segment_id() = segment_id;
			return mOutput.Send(event);
		}
		else
			return E_OUTOFMEMORY;
	}

	HRESULT CBase_Filter::Emit_Info(const scgms::NDevice_Event_Code code, const std::wstring &msg, const uint64_t segment_id) noexcept
	{
		return Emit_Info(code, msg.c_str(), segment_id);
	}

	HRESULT CBase_Filter::Emit_Marker(const scgms::NDevice_Event_Code code, const double event_time, const uint64_t segment_id) noexcept
	{
		scgms::UDevice_Event event{code};
		if (event)
		{
			event.device_id() = mDevice_ID;
			event.device_time() = event_time;
			event.segment_id() = segment_id;
			return mOutput.Send(event);
		}
		else
			return E_OUTOFMEMORY;
	}

	HRESULT IfaceCalling CBase_Filter::Configure(IFilter_Configuration *configuration, refcnt::wstr_list *error_description) noexcept
	{
		refcnt::Swstr_list shared_error_description = refcnt::make_shared_reference_ext<refcnt::Swstr_list, refcnt::wstr_list>(error_description, true);
		if (mOutput)
		{
			SFilter_Configuration shared_configuration = refcnt::make_shared_reference_ext<SFilter_Configuration, IFilter_Configuration>(configuration, true);
			return Do_Configure(shared_configuration, shared_error_description);
		}
		else
		{
			shared_error_description.push(L"Attempted to construct a filter without valid output!");
			return E_HANDLE;
		}
	}

	HRESULT IfaceCalling CBase_Filter::Execute(scgms::IDevice_Event *event) noexcept
	{
		if (!event)
			return E_INVALIDARG;
		return Do_Execute(scgms::UDevice_Event{event});
	}

	std::tuple<bool, std::wstring> Is_Variable_Name(const std::wstring &str)
	{
		std::wstring trimmed{str};
		trimmed = trim(trimmed);

		bool is_var = false;
		std::wstring var_name;
		if (trimmed.size() > 3)
		{
			if ((trimmed[0] == '$') && (trimmed[1] == L'(') && (trimmed[trimmed.size() - 1] == L')'))
			{
				var_name = trimmed.substr(2, trimmed.size() - 3);
				is_var = true;
			}
		}

		return std::tuple<bool, std::wstring>{is_var, var_name};
	}

}
