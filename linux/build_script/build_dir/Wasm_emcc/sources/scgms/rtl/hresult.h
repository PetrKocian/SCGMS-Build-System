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

#pragma once

#include <stdbool.h>
#include <stddef.h>

#ifdef _WIN32
	#include <WTypes.h>
#else
	typedef long HRESULT;

	typedef unsigned long	DWORD;
	typedef long			LONG;
	typedef unsigned long	ULONG;
	// define macro to avoid redefinition in several used libraries (e.g. ExcelFormat)
	#define INT32_TYPES_DEFINED

	#define S_OK									((HRESULT)0L)
	#define S_FALSE									((HRESULT)1L)
	#define ERROR_FILE_NOT_FOUND					((HRESULT)2L)
	#define ERROR_READ_FAULT						((HRESULT)30L)
	#define ERROR_DS_DRA_EXTN_CONNECTION_FAILED		((HRESULT)8466L)

	#define E_NOTIMPL								((HRESULT)0x80004001L)
	#define E_UNEXPECTED							((HRESULT)0x8000FFFFL)
	#define E_FAIL									((HRESULT)0x80004005L)
	#define E_NOINTERFACE							((HRESULT)0x80004002L)
	#define E_ABORT									((HRESULT)0x80004004L)
	#define E_ILLEGAL_METHOD_CALL					((HRESULT)0x8000000EL)
	#define E_ILLEGAL_STATE_CHANGE					((HRESULT)0x8000000DL)
	#define E_ACCESSDENIED							((HRESULT)0x80070005L)
	#define TYPE_E_AMBIGUOUSNAME					((HRESULT)0x8002802CL)
	#define E_INVALIDARG							((HRESULT)0x80070057L)
	#define MK_E_CANTOPENFILE						((HRESULT)0x800401EAL)
	#define MK_E_UNAVAILABLE						((HRESULT)0x800401E3L)
	#define CO_E_ERRORINDLL							((HRESULT)0x800401F9L)
	#define EVENT_E_TOO_MANY_METHODS				((HRESULT)0x80040209L)
	#define E_HANDLE								((HRESULT)0x80070006L)
	#define E_OUTOFMEMORY							((HRESULT)0x8007000EL)
	#define E_NOT_SET								((HRESULT)0x80070490L)
	#define E_UAC_DISABLED							((HRESULT)0x80270252L)

#endif

#ifdef __cplusplus
	extern "C"
#endif
const wchar_t* Describe_Error(const HRESULT error);


#ifdef __cplusplus
	extern "C"
#endif
	bool Succeeded(const HRESULT rc);
	//the default Succeeded macro tests rc>0, which fails to indicate e.g.; file not found as a success
