﻿/**
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

#include "data_filter.h"
#include "descriptor.h"


#if defined (WASM)
#include <iostream>
#elif defined(ESP32)
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#elif  defined(FREERTOS)
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#endif

CData_Filter::CData_Filter(scgms::IFilter *output) : CBase_Filter(output) {
	//
}

CData_Filter::~CData_Filter() {
	//
}

HRESULT IfaceCalling CData_Filter::QueryInterface(const GUID*  riid, void ** ppvObj) {
	if (Internal_Query_Interface<scgms::IFilter>(data_filter::id, *riid, ppvObj)) return S_OK;

	return E_NOINTERFACE;
}

HRESULT IfaceCalling CData_Filter::Do_Configure(scgms::SFilter_Configuration configuration, refcnt::Swstr_list& error_description) {

	// let us read configured parameters
	//when reading a strin, use .Read_File_Path to read a file path relative to the configuration file
	auto example_str = configuration.Read_String(data_filter::rsExample_Config_String);	
	auto example_num = configuration.Read_Double(data_filter::rsExample_Config_Double, 123.0); // default value parameter is optional

	// here we can put an extra constraint on some of the configuration parameters
	// if the constraint fails, we should return appropriate error code according to COM specification
	if (example_num < 0) {
		error_description.push(L"Example number parameter must be non-negative!");
		return E_INVALIDARG;
	}

	// return S_OK on success
	return S_OK;
}

HRESULT IfaceCalling CData_Filter::Do_Execute(scgms::UDevice_Event event) {

	// here we can work with the event, that was executed on us

	if (event.is_level_event()) {
		// if this is a level event, the "level" field is valid
		// we may, for some reason, want to modify it; note the level() call returns a l-value reference to an internal field
		//event.level() += 1.0;
	}
	else if (event.is_info_event()) {
		// if this is an info event, the "info" field is valid
		// we may, for some reason, want to read, parse it or overwrite it; note the "info" field is a container built on top of internal field
		//event.info.set(L"A new value of info event");
	}
	else if (event.is_parameters_event()) {
		// is this is a parameters event, the "parameters" field is valid
		// we may, for some reason, want to read and apply parameters; note the "parameters" field is a container built on top of internal field
		// the "signal_id" field always refers to a valid model signal GUID
		
		// example: read parameters one-by-one
		//double *begin, *end;
		//if (event.parameters->get(&begin, &end) == S_OK) {
		//	for (double* paramPtr = begin; paramPtr != end; paramPtr++) {
		//		double parameter = *paramPtr;
		//		// ...
		//	}
		//}
	}

	HRESULT rc;
	for (int i = 0; i < 20; i++)
	{
		scgms::UDevice_Event evt{ scgms::NDevice_Event_Code::Level };
		evt.device_id() = data_filter::id;
		evt.signal_id() = Invalid_GUID;
		evt.level() = i;
		rc = mOutput.Send(evt);
#if defined(FREERTOS) || defined(ESP32)
	vTaskDelay(200);
#elif defined(WASM)
	sleep(2);
#endif
	}
	return rc;

	// let us emit a new event every time a "blood glucose" (BG) signal of "level" greater than 10.0 comes, just to demonstrate how to send a new event through the filter chain
	/*if (event.is_level_event() && event.signal_id() == scgms::signal_BG) {

		if (event.level() > 8.0) {

			scgms::UDevice_Event evt{ scgms::NDevice_Event_Code::Information };
			evt.device_id() = data_filter::id;
			evt.signal_id() = Invalid_GUID;
			evt.device_time() = event.device_time(); // reuse original event's device time
			evt.info.set(L"Example info: BG is greater than 10 mmol/L !");

			// additional event send failure should be detected and the error propagated either immediatelly, or after the original event sending
			// note this will prepend the new event before the original one
			auto rc = mOutput.Send(evt);
			if (!Succeeded(rc)) {
				return rc;
			}
		}
		else
		{
			return mOutput.Send(event);


		}
	}*/

	// after all our work is done, we may chose to:
	//   1) send the event further to the chain - this is expected behaviour by default
	//   2) consume the event, so no further event sees it; therefore, no Send() method call would be there

	// we chose to send the event further to the chain
};
