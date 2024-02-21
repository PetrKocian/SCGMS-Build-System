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

#include "filter_parameter.h"
#include "filters.h"

#include <scgms/rtl/manufactory.h>
#include <scgms/utils/string_utils.h>
#include <scgms/rtl/rattime.h>
#include <scgms/lang/dstrings.h>

const std::wstring CFilter_Parameter::mUnused_Variable_Name = rsUnused_Variable_Name;

double str_2_rat_dbl(const std::wstring& str, bool& converted_ok) {
	double value = str_2_dbl(str.c_str(), converted_ok);
	if (!converted_ok)
		value = Default_Str_To_Rat_Time(str.c_str(), converted_ok);
	return value;
}

HRESULT create_filter_parameter(const scgms::NParameter_Type type, const wchar_t* config_name, scgms::IFilter_Parameter** parameter) {
	return Manufacture_Object<CFilter_Parameter, scgms::IFilter_Parameter>(parameter, type, config_name);
}


CFilter_Parameter::CFilter_Parameter(const scgms::NParameter_Type type, const wchar_t *config_name) : mType(type), mConfig_Name(config_name) {
	//
}

HRESULT IfaceCalling CFilter_Parameter::Get_Type(scgms::NParameter_Type *type) {
	*type = mType;
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_Config_Name(wchar_t **config_name) {
	(*config_name) = const_cast<wchar_t*>(mConfig_Name.c_str());
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_WChar_Container(refcnt::wstr_container **wstr, BOOL read_interpreted) {
	auto [rc, converted] = to_string(read_interpreted == TRUE);

	if ((rc == S_OK) || ((rc == E_NOT_SET) && (read_interpreted == FALSE)))
		*wstr = refcnt::WString_To_WChar_Container(converted.c_str());
	return rc;	
}

HRESULT IfaceCalling CFilter_Parameter::Set_WChar_Container(refcnt::wstr_container *wstr) {
	std::wstring tmp = WChar_Container_To_WString(wstr);
	if (Succeeded(from_string(mType, tmp.c_str()))) {
		mWChar_Container = refcnt::make_shared_reference_ext<decltype(mWChar_Container), refcnt::wstr_container>(wstr, true);
		return S_OK;
	}
	else
		return E_INVALIDARG;
}


HRESULT IfaceCalling CFilter_Parameter::Get_Time_Segment_Id_Container(scgms::time_segment_id_container **ids) {
	return Get_Container_With_All_Level_Vars_Evaluated<scgms::time_segment_id_container, int64_t>(mTime_Segment_ID, ids, str_2_int);
}

HRESULT IfaceCalling CFilter_Parameter::Set_Time_Segment_Id_Container(scgms::time_segment_id_container *ids) {
	//by setting this to max, we effectively discard any nested variable and do not need to perform any additinal action
	mFirst_Array_Var_idx = std::numeric_limits<size_t>::max();
	mVariable_Name.clear();

	mTime_Segment_ID = refcnt::make_shared_reference_ext<decltype(mTime_Segment_ID), scgms::time_segment_id_container>(ids, true);
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_Double(double *value) {
	return Get_Value<double>(value, [this]() {return mData.dbl; }, [](const std::wstring& var_val, bool& ok) {
			return str_2_rat_dbl(var_val, ok);
		},
		std::numeric_limits<double>::quiet_NaN());
}

HRESULT IfaceCalling CFilter_Parameter::Set_Double(const double value) {
	mVariable_Name.clear();
	mData.dbl = value;
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_Int64(int64_t *value) {
	return Get_Value<int64_t>(value, [this]() {return mData.int64; }, [](const std::wstring& var_val, bool& ok) {
		return str_2_int(var_val.c_str(), ok);		
	}, std::numeric_limits<int64_t>::max());
}

HRESULT IfaceCalling CFilter_Parameter::Set_Int64(const int64_t value) {
	mVariable_Name.clear();
	mData.int64 = value;
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_Bool(BOOL *boolean) {
	return Get_Value<BOOL>(boolean, [this]() {return mData.boolean ? TRUE : FALSE; }, [](const std::wstring& var_val, bool& ok) {
		const bool val = str_2_bool(var_val, ok);
		return val ? TRUE : FALSE;
	}, false);
}

HRESULT IfaceCalling CFilter_Parameter::Set_Bool(const BOOL boolean) {
	mVariable_Name.clear();
	mData.boolean = boolean != FALSE;
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_GUID(GUID *id) {
	return Get_Value<GUID>(id, [this]() {return mData.guid; }, [](const std::wstring& var_val, bool& ok) {
		return WString_To_GUID(var_val, ok);
	}, Invalid_GUID);
}

HRESULT IfaceCalling CFilter_Parameter::Set_GUID(const GUID *id) {
	mVariable_Name.clear();
	mData.guid = *id;
	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Get_Model_Parameters(scgms::IModel_Parameter_Vector **parameters) {
	return Get_Container_With_All_Level_Vars_Evaluated<scgms::IModel_Parameter_Vector, double>(mModel_Parameters, parameters, str_2_rat_dbl);
}

HRESULT IfaceCalling CFilter_Parameter::Set_Model_Parameters(scgms::IModel_Parameter_Vector *parameters) {
	//by setting this to max, we effectively discard any nested variable and do not need to perform any additinal action
	mFirst_Array_Var_idx = std::numeric_limits<size_t>::max();
	mVariable_Name.clear();
	mArray_Vars.clear();

	mModel_Parameters = refcnt::make_shared_reference_ext<decltype(mModel_Parameters), scgms::IModel_Parameter_Vector>(parameters, true);
	return S_OK;
}


HRESULT IfaceCalling CFilter_Parameter::Clone(scgms::IFilter_Parameter **deep_copy) {
	std::unique_ptr<CFilter_Parameter> clone = std::make_unique<CFilter_Parameter>(mType, mConfig_Name.c_str());
	clone->mVariable_Name = mVariable_Name;
	clone->mWChar_Container = refcnt::Copy_Container_shared<wchar_t, decltype(mWChar_Container)>(mWChar_Container.get());
	clone->mArray_Vars = mArray_Vars;
	clone->mFirst_Array_Var_idx = mFirst_Array_Var_idx;
	clone->mTime_Segment_ID = refcnt::Copy_Container_shared<int64_t, decltype(mTime_Segment_ID)>(mTime_Segment_ID.get());
	clone->mModel_Parameters = refcnt::Copy_Container_shared<double, decltype(mModel_Parameters)>(mModel_Parameters.get());
	clone->mData = mData;
	clone->mNon_OS_Variables = mNon_OS_Variables;

	clone->mDeferred_Path_Or_Var = mDeferred_Path_Or_Var;

	(*deep_copy) = static_cast<scgms::IFilter_Parameter*>(clone.get());
	(*deep_copy)->AddRef();
	clone.release();

	return S_OK;
}

HRESULT IfaceCalling CFilter_Parameter::Set_Variable(const wchar_t* name, const wchar_t* value) {
	if (name == CFilter_Parameter::mUnused_Variable_Name) return TYPE_E_AMBIGUOUSNAME;
	mNon_OS_Variables[name] = value;
	return S_OK;
}

std::tuple<HRESULT, std::wstring> CFilter_Parameter::Evaluate_Variable(const std::wstring& var_name) {

	if (var_name == CFilter_Parameter::mUnused_Variable_Name)
		return { S_FALSE, std::wstring{} };	//valid text for an unused option


	//try our variables as they may hide the OS ones to actually customize them
	{
		auto iter = mNon_OS_Variables.find(var_name);
		if (iter != mNon_OS_Variables.end())
			return std::tuple<bool, std::wstring>{S_OK, iter->second};
	}

	//try OS variables
	{
		std::string ansi = Narrow_WString(var_name);
		
		size_t assumed_len = 0;
		auto var_os_err = getenv_s(&assumed_len, nullptr, 0, ansi.c_str());
		if ((var_os_err == 0) && (assumed_len > 0)) {
			std::vector<char> var_buf(assumed_len);				
			auto var_os_err = getenv_s(&assumed_len, var_buf.data(), assumed_len, ansi.c_str());	//with clang, 1st param cannot be nullptr
			if (var_os_err == 0) {
				var_buf.push_back(0);	//make sure its ASCIIZ
				return std::tuple<bool, std::wstring>{S_OK, Widen_Char(var_buf.data())};
			}
		}			
	}
		

	return { E_NOT_SET, std::wstring{} };	//not found at all
}

HRESULT CFilter_Parameter::from_string(const scgms::NParameter_Type desired_type, const wchar_t* str) {
	wchar_t* effective_str = const_cast<wchar_t*>(str);
	
	mDeferred_Path_Or_Var.clear();


	auto [is_var, var_name] = scgms::Is_Variable_Name(effective_str);
	if (is_var) {
		mVariable_Name = var_name;
		return S_OK;
	}
	else
		mVariable_Name.clear();

	bool valid = false;

	switch (desired_type) {

		case scgms::NParameter_Type::ptWChar_Array:		
			mWChar_Container = refcnt::make_shared_reference_ext<decltype(mWChar_Container), refcnt::wstr_container>(refcnt::WString_To_WChar_Container(effective_str), false);
			valid = true;
			break;

		case scgms::NParameter_Type::ptInt64_Array:
			valid = Parse_Container<scgms::time_segment_id_container, int64_t>(mTime_Segment_ID, effective_str, str_2_int);
			break;

		case scgms::NParameter_Type::ptRatTime:	
		case scgms::NParameter_Type::ptDouble:
		{
			double val = str_2_rat_dbl(effective_str, valid);		
			if (valid)
				mData.dbl = val;
		}
		break;

		case scgms::NParameter_Type::ptInt64:
		case scgms::NParameter_Type::ptSubject_Id:
		{
			int64_t val = str_2_int(effective_str, valid);
			if (valid)
				mData.int64 = val;
		}
		break;

		case scgms::NParameter_Type::ptBool:
		{
			bool val = str_2_bool(effective_str, valid);
			if (valid)
				mData.boolean = val;
		}
			break;

		case scgms::NParameter_Type::ptSignal_Model_Id:
		case scgms::NParameter_Type::ptDiscrete_Model_Id:
		case scgms::NParameter_Type::ptMetric_Id:
		case scgms::NParameter_Type::ptModel_Produced_Signal_Id:
		case scgms::NParameter_Type::ptSignal_Id:
		case scgms::NParameter_Type::ptSolver_Id:
		break;

		case scgms::NParameter_Type::ptDouble_Array:
			valid = Parse_Container<scgms::IModel_Parameter_Vector, double>(mModel_Parameters, effective_str, str_2_rat_dbl);	
			break;

		default:
			valid = false;
	} //switch (desc.parameter_type[i])	{

	return valid ? S_OK : E_FAIL;
}


std::tuple<HRESULT, std::wstring> CFilter_Parameter::to_string(bool read_interpreted) {
	
	std::wstring converted;
	HRESULT rc = S_OK;
	
	auto convert_scalar = [&]() {
		if (mVariable_Name.empty()) {
			//always behave as read_interpereted = true

			switch (mType) {
				case scgms::NParameter_Type::ptWChar_Array:
					if (mWChar_Container)
						converted = refcnt::WChar_Container_To_WString(mWChar_Container.get());
					break;

				case scgms::NParameter_Type::ptRatTime:
					converted = Rat_Time_To_Default_WStr(mData.dbl);
					break;

				case scgms::NParameter_Type::ptDouble:
					converted = dbl_2_wstr(mData.dbl);
					break;

				case scgms::NParameter_Type::ptInt64:
				case scgms::NParameter_Type::ptSubject_Id:
					converted = std::to_wstring(mData.int64);
					break;

				case scgms::NParameter_Type::ptBool:
					converted = mData.boolean ? L"true" : L"false";
					break;

				case scgms::NParameter_Type::ptSignal_Model_Id:
				case scgms::NParameter_Type::ptDiscrete_Model_Id:
				case scgms::NParameter_Type::ptMetric_Id:
				case scgms::NParameter_Type::ptModel_Produced_Signal_Id:
				case scgms::NParameter_Type::ptSignal_Id:
				case scgms::NParameter_Type::ptSolver_Id:
					converted = GUID_To_WString(mData.guid);
				break;

				default: break;
			} //switch (source_type) {

		}
		else {
			if (read_interpreted) 
				std::tie(rc, converted) = Evaluate_Variable(mVariable_Name);
			 else 
				converted = L"$(" + mVariable_Name + L")";
			//and that's all
		}
		
	};


	switch (mType) {

		case scgms::NParameter_Type::ptDouble_Array: 
			{							
				if (!mModel_Parameters && (!mDeferred_Path_Or_Var.empty()))	//if we have not evaluated the array yet
						rc = S_OK;
				else
						std::tie(rc, converted) = Array_To_String<double>(mModel_Parameters.get(), read_interpreted);
			}
			break;

		case scgms::NParameter_Type::ptInt64_Array:
			{
				if (!mTime_Segment_ID && (!mDeferred_Path_Or_Var.empty()))
					rc = S_OK;
				else
					std::tie(rc, converted) = Array_To_String<int64_t>(mTime_Segment_ID.get(), read_interpreted);
			}
			break;

		default: convert_scalar();
			break;
	}

	if (rc != S_OK)
		converted.clear();

	return std::tuple<HRESULT, std::wstring>{rc, converted};
}



std::tuple<bool, std::wstring> CFilter_Parameter::Is_Deferred_Parameter(const wchar_t* str_value) {
	return { false, L"" };
}
