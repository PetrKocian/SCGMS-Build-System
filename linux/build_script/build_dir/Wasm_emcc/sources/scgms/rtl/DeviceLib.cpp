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

#include "../iface/referencedIface.h"
#include <scgms/src/device_event.h>

#include "DeviceLib.h"
#include "rattime.h"


bool scgms::SModel_Parameter_Vector::set(const std::vector<double> &params) {
	double *data_ptr = const_cast<double*>(params.data());
	if (!operator bool()) {
		scgms::IModel_Parameter_Vector *new_vector = refcnt::Create_Container<double>(data_ptr, data_ptr + params.size());
		reset(new_vector, [](scgms::IModel_Parameter_Vector* obj_to_release) { if (obj_to_release != nullptr) obj_to_release->Release(); });
		return operator bool();
	} else
		return get()->set(data_ptr, data_ptr + params.size()) == S_OK;
}


bool scgms::SModel_Parameter_Vector::set(const scgms::SModel_Parameter_Vector &params) {
	if (!params) return false;

	double *begin, *end;
	if (params->get(&begin, &end) != S_OK) return false;

	if (!operator bool()) {
		scgms::IModel_Parameter_Vector *new_vector = refcnt::Create_Container<double>(begin, end);
		reset(new_vector, [](scgms::IModel_Parameter_Vector* obj_to_release) { if (obj_to_release != nullptr) obj_to_release->Release(); });
		return operator bool();
	} else
		return get()->set(begin, end) == S_OK;
}

bool scgms::SModel_Parameter_Vector::empty() const {
	if (!operator bool()) return true;
	return get()->empty() == S_OK;
}

scgms::TDevice_Event* Get_Raw_Event(scgms::IDevice_Event *event) {
	scgms::TDevice_Event* result;
	if ((event == nullptr) || (event->Raw(&result) != S_OK)) result = nullptr;

	return result;
}

scgms::IDevice_Event* Create_Event(const scgms::NDevice_Event_Code code) {
	scgms::IDevice_Event *result;
	if (create_device_event(code, &result) != S_OK) result = nullptr;
	assert(result != nullptr);
	return result;
}

scgms::UDevice_Event::UDevice_Event(const scgms::NDevice_Event_Code code) noexcept : UDevice_Event(Create_Event(code)) {
}

scgms::UDevice_Event::UDevice_Event(scgms::UDevice_Event&& event) noexcept: mRaw(event.mRaw) {
	event.release();
}

scgms::UDevice_Event::UDevice_Event(IDevice_Event *event) : std::unique_ptr<IDevice_Event, UDevice_Event_Deleter>(event), mRaw(Get_Raw_Event(event)){
	switch (major_type()) {
		case scgms::UDevice_Event_internal::NDevice_Event_Major_Type::info:
			if (mRaw->info) info = refcnt::make_shared_reference_ext<refcnt::Swstr_container, refcnt::wstr_container>(mRaw->info, true);
			break;

		case scgms::UDevice_Event_internal::NDevice_Event_Major_Type::parameters:
			if (mRaw->parameters) parameters = refcnt::make_shared_reference_ext<scgms::SModel_Parameter_Vector, scgms::IModel_Parameter_Vector>(mRaw->parameters, true);
			break;

		default:
			break;
	}
}

scgms::UDevice_Event_internal::NDevice_Event_Major_Type scgms::UDevice_Event::major_type() const {
	if (mRaw == nullptr) return scgms::UDevice_Event_internal::NDevice_Event_Major_Type::null;
	return UDevice_Event_internal::major_type(mRaw->event_code);
}

scgms::UDevice_Event_internal::NDevice_Event_Major_Type scgms::UDevice_Event_internal::major_type(const scgms::NDevice_Event_Code code) {
	switch (code) {
		case scgms::NDevice_Event_Code::Level:
		case scgms::NDevice_Event_Code::Masked_Level:		return scgms::UDevice_Event_internal::NDevice_Event_Major_Type::level;

		case scgms::NDevice_Event_Code::Parameters:
		case scgms::NDevice_Event_Code::Parameters_Hint:	return scgms::UDevice_Event_internal::NDevice_Event_Major_Type::parameters;

		case scgms::NDevice_Event_Code::Information:
		case scgms::NDevice_Event_Code::Warning:
		case scgms::NDevice_Event_Code::Error:				return scgms::UDevice_Event_internal::NDevice_Event_Major_Type::info;

		case scgms::NDevice_Event_Code::Time_Segment_Start:
		case scgms::NDevice_Event_Code::Time_Segment_Stop:
		case scgms::NDevice_Event_Code::Solve_Parameters:		
		case scgms::NDevice_Event_Code::Shut_Down:
		case scgms::NDevice_Event_Code::Warm_Reset:
		case scgms::NDevice_Event_Code::Suspend_Parameter_Solving:
		case scgms::NDevice_Event_Code::Resume_Parameter_Solving:
															return scgms::UDevice_Event_internal::NDevice_Event_Major_Type::control;

		default:	break;
	}

	return scgms::UDevice_Event_internal::NDevice_Event_Major_Type::null;
}

void scgms::UDevice_Event::reset(IDevice_Event *event) {
	if (operator bool()) {
		auto deleter = get_deleter();
		auto obj = get();
		release();
		deleter(obj);
	}

	if (event) {
		if (event->Raw(&mRaw) == S_OK) event->Release();	//do not forget that we're moving the object!
	}
	
}

scgms::UDevice_Event scgms::UDevice_Event::Clone() {	
	scgms::IDevice_Event* clone;
	if (operator bool() && (get()->Clone(&clone) == S_OK)) {
		return scgms::UDevice_Event{ clone };
	}
	else
		return scgms::UDevice_Event{};
}

const scgms::NDevice_Event_Code& scgms::UDevice_Event::event_code() const {
	return mRaw->event_code;
}

const int64_t& scgms::UDevice_Event::logical_time() const {
	return mRaw->logical_time;
}

GUID& scgms::UDevice_Event::device_id() const {
	return mRaw->device_id;
}

GUID& scgms::UDevice_Event::signal_id() const {
	return mRaw->signal_id;
}

double& scgms::UDevice_Event::device_time() const {
	return mRaw->device_time;
}
	
uint64_t& scgms::UDevice_Event::segment_id() const {
	return mRaw->segment_id;
}

double& scgms::UDevice_Event::level() const {
	return mRaw->level;
}


bool scgms::UDevice_Event::is_level_event() const {
	return major_type() == scgms::UDevice_Event_internal::NDevice_Event_Major_Type::level;
}

bool scgms::UDevice_Event::is_parameters_event() const {
	return major_type() == scgms::UDevice_Event_internal::NDevice_Event_Major_Type::parameters;
}

bool scgms::UDevice_Event::is_info_event() const {
	return major_type() == scgms::UDevice_Event_internal::NDevice_Event_Major_Type::info;
}

bool scgms::UDevice_Event::is_control_event() const {
	return major_type() == scgms::UDevice_Event_internal::NDevice_Event_Major_Type::control;
}