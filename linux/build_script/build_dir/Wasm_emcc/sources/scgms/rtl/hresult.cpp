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

#include "hresult.h"

const wchar_t* Describe_Error(const HRESULT error) {
	//although we could use the system error description, at least on Win32,
	//we provide the meanings as we use them

	
	switch (error) {
		case S_OK: return L"No error"; break;
		case S_FALSE: return L"Succeeded, but no result"; break;
		case ERROR_FILE_NOT_FOUND: return L"File not found"; break;
		case ERROR_READ_FAULT: return L"Cannot read from the given source"; break;
		case ERROR_DS_DRA_EXTN_CONNECTION_FAILED: return L"No object to complete the operation"; break;

		case E_NOTIMPL: return L"Not implemented"; break;
		case E_UNEXPECTED: return L"Catastrophic failure"; break;
		case E_FAIL: return L"Unspecified error"; break;
		case E_NOINTERFACE: return L"No such interface"; break;
		case E_ABORT: return L"Operation aborted"; break;
		case E_ILLEGAL_METHOD_CALL: return L"Method cannot be called at this time"; break;
		case E_ILLEGAL_STATE_CHANGE: return L"Attempted illegal state change"; break;
		case E_ACCESSDENIED: return L"Access denied"; break;
		case TYPE_E_AMBIGUOUSNAME: return L"Ambiguous name"; break;
		case E_INVALIDARG: return L"One or more invalid argument(s)"; break;
		case MK_E_CANTOPENFILE: return L"Cannot open file"; break;
		case MK_E_UNAVAILABLE: return L"Operation unavailable"; break;
		case CO_E_ERRORINDLL: return L"Dynamic-libray error"; break;
		case EVENT_E_TOO_MANY_METHODS: return L"Too many methods invoked to complete the operation"; break;
		case E_HANDLE: return L"Invalid object"; break;
		case E_OUTOFMEMORY: return L"Out of memory"; break;
		case /*E_NOT_SET*/((HRESULT)0x80070490L): return L"Not set/found"; break;	//otherwise fails to compile on Win
		case E_UAC_DISABLED: return L"Access control disabled"; break;

		default:	return L"Error description is not available"; break;
	}
}


bool Succeeded(const HRESULT rc) {
	return (rc == S_OK) || (rc == S_FALSE);
}
