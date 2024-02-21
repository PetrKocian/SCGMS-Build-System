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

#include "persistent_chain_configuration.h"
#include "configuration_link.h"
#include "filters.h"

#include <scgms/generated/combined_descriptors.h>

#include <scgms/rtl/FilterLib.h>
#include <scgms/rtl/manufactory.h>
#include <scgms/rtl/rattime.h>
#include <scgms/lang/dstrings.h>
#include <scgms/utils/string_utils.h>
#include <scgms/utils/SimpleIni.h>

#include <exception>

CPersistent_Chain_Configuration::CPersistent_Chain_Configuration() {
	//
}

CPersistent_Chain_Configuration::~CPersistent_Chain_Configuration() noexcept {
	//
}


HRESULT IfaceCalling CPersistent_Chain_Configuration::Load_From_Memory(const char* memory, const size_t len, refcnt::wstr_list* error_description) noexcept {
	CSimpleIniW mIni;

	refcnt::Swstr_list shared_error_description = refcnt::make_shared_reference_ext<refcnt::Swstr_list, refcnt::wstr_list>(error_description, true);

	if (mIni.LoadData(memory, len) != SI_Error::SI_OK) {
		shared_error_description.push(L"Could not load INI file from memory");
		return E_FAIL;
	}

	bool loaded_all_filters = true;
	bool encountered_E_NOT_SET = false;

	std::list<CSimpleIniW::Entry> section_names;
	mIni.GetAllSections(section_names);

	// sort by section names - the name would contain zero-padded number, so it is possible to sort it as strings
	section_names.sort([](auto& a, auto& b) {
		return std::wstring(a.pItem).compare(b.pItem) < 0;
		});

	for (auto& section_name : section_names) {
		std::wstring name_str{ section_name.pItem };
		const std::wstring prefix{ rsFilter_Section_Prefix };
		auto res = std::mismatch(prefix.begin(), prefix.end(), name_str.begin());
		if (res.first == prefix.end()) {

			auto uspos = name_str.find(rsFilter_Section_Separator, prefix.size() + 1);
			if (uspos == std::wstring::npos)
				uspos = prefix.size();

			//OK, this is filter section - extract the guid
			const std::wstring section_id_str { name_str.begin() + uspos + 1, name_str.end() };
			bool section_id_ok;
			const GUID id = WString_To_GUID(section_id_str, section_id_ok);
			//and get the filter descriptor to load the parameters

			scgms::TFilter_Descriptor desc = scgms::Null_Filter_Descriptor;

				

			if (section_id_ok && scgms::get_filter_descriptor_by_id(id, desc)) {
				refcnt::SReferenced<scgms::IFilter_Configuration_Link> filter_config{ new CFilter_Configuration_Link{id} };

				//so.. now, try to load the filter parameters - aka filter_config
				if (filter_config) {
					for (size_t i = 0; i < desc.parameters_count; i++) {

						//does the value exists?
						const wchar_t* str_value = mIni.GetValue(section_name.pItem, desc.config_parameter_name[i]);
						if (str_value) {

							std::unique_ptr<CFilter_Parameter> raw_filter_parameter = std::make_unique<CFilter_Parameter>(desc.parameter_type[i], desc.config_parameter_name[i]);
							const HRESULT valid_rc = raw_filter_parameter->from_string(desc.parameter_type[i], str_value);							

							if (Succeeded(valid_rc) || (valid_rc == E_NOT_SET)) {
								scgms::IFilter_Parameter* raw_param = static_cast<scgms::IFilter_Parameter*>(raw_filter_parameter.get());								

								if (Succeeded(filter_config->add(&raw_param, &raw_param + 1)))
									raw_filter_parameter.release();

								if (valid_rc == E_NOT_SET) {
									encountered_E_NOT_SET = true;
									std::wstring error_desc = dsVar_Not_Set_Filter_Parameter_Value;
									error_desc.append(desc.description);
									error_desc.append(L" (2)");
									error_desc.append(desc.ui_parameter_name[i]);
									error_desc.append(L" (3)");
									error_desc.append(str_value);
									shared_error_description.push(error_desc.c_str());
								}
							}
							else {
								std::wstring error_desc = dsMalformed_Filter_Parameter_Value;
								error_desc.append(desc.description);
								error_desc.append(L" (2)");
								error_desc.append(desc.ui_parameter_name[i]);
								error_desc.append(L" (3)");
								error_desc.append(str_value);
								shared_error_description.push(error_desc.c_str());
							}

						}
						else if (desc.parameter_type[i] != scgms::NParameter_Type::ptNull) {
							//this parameter is not configured, warn about it
							std::wstring error_desc = dsFilter_Parameter_Not_Configured;
							error_desc.append(desc.description);
							error_desc.append(L" (2)");
							error_desc.append(desc.ui_parameter_name[i]);
							shared_error_description.push(error_desc.c_str());
						}
					}


					//and finally, add the new link into the filter chain
					{
						auto raw_filter_config = filter_config.get();
						add(&raw_filter_config, &raw_filter_config + 1);
					}
				}
				else {
					//memory failure
					shared_error_description.push(rsFailed_to_allocate_memory);
					return E_FAIL;
				}
			}
			else {					
				loaded_all_filters = false;
				std::wstring error_desc = dsCannot_Resolve_Filter_Descriptor + section_id_str;
				shared_error_description.push(error_desc.c_str());
			}
		}
		else {
			std::wstring error_desc = dsInvalid_Section_Name + name_str;
			shared_error_description.push(error_desc.c_str());
		}

	}

	if (!loaded_all_filters)
		describe_loaded_filters(shared_error_description);

	return (loaded_all_filters || encountered_E_NOT_SET) ? S_OK : S_FALSE;
}


HRESULT IfaceCalling CPersistent_Chain_Configuration::add(scgms::IFilter_Configuration_Link** begin, scgms::IFilter_Configuration_Link** end) noexcept {
	HRESULT rc = refcnt::internal::CVector_Container<scgms::IFilter_Configuration_Link*>::add(begin, end);

	return rc;	
}



HRESULT IfaceCalling CPersistent_Chain_Configuration::Set_Variable(const wchar_t* name, const wchar_t* value) noexcept {
	if (!name || (*name == 0)) return E_INVALIDARG;
	if (name == CFilter_Parameter::mUnused_Variable_Name) return TYPE_E_AMBIGUOUSNAME;

	HRESULT rc = refcnt::internal::CVector_Container<scgms::IFilter_Configuration_Link*>::empty();
	if (rc == S_FALSE) {
		for (scgms::IFilter_Configuration_Link* link : mData) {
			if (!Succeeded(link->Set_Variable(name, value)))
				rc = E_UNEXPECTED;
		}
	}

	return rc;
}

HRESULT IfaceCalling create_persistent_filter_chain_configuration(scgms::IPersistent_Filter_Chain_Configuration** configuration) noexcept {
	return Manufacture_Object<CPersistent_Chain_Configuration, scgms::IPersistent_Filter_Chain_Configuration>(configuration);
}
