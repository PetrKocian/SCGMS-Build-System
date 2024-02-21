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

#ifndef INC_WINAPI_MAPPING_H
#define INC_WINAPI_MAPPING_H

#ifndef EXTERN_C
	#ifdef __cplusplus
		#define EXTERN_C extern "C"
	#else
		#define EXTERN_C extern
	#endif
#endif

#ifdef _WIN32
	#include <Windows.h>
	#include <locale.h>

	#define DLL_EXPORT

	EXTERN_C char __ImageBase;

	typedef int socklen_t;

	#define MainCalling __cdecl

	#define WSTRING_FORMATTER "%ws"

	inline _locale_t getlocale(int cat) {
		return _get_current_locale();
	}
#else
	#include <unistd.h>
	#include <errno.h>
	#include <stdlib.h>

#ifdef __cplusplus
	#include <ctime>
	#include <clocale>

	#define DLL_EXPORT  extern "C"
#else
	#include <time.h>
	#include <wchar.h>
	#include <locale.h>

	#define DLL_EXPORT
#endif

	#define MainCalling
	
	typedef int BOOL;
	#define TRUE ((BOOL)1)
#ifndef FALSE
	// strangely, on some systems, FALSE constant is not defined
	// NOTE: this has to be #define, as some libraries may check for this constant using preprocessor macro
	#define FALSE ((BOOL)0)
#endif

	typedef void* HMODULE;

	EXTERN_C void localtime_s(struct tm* t, const time_t* tim);
	EXTERN_C void gmtime_s(struct tm* t, const time_t* tim);


	static inline char* getlocale(int cat) {
		return setlocale(cat, NULL);
	}

	#define wcstok_s wcstok

	#define swscanf_s swscanf

	EXTERN_C void* _aligned_malloc(size_t n, size_t alignment);
	EXTERN_C void* _aligned_malloc_dbg(size_t n, size_t alignment, const char* filename, int line);
	EXTERN_C void _aligned_free(void* _Block);

	EXTERN_C int getenv_s(size_t *len, char *value, size_t valuesz, const char *name);

	#define SD_BOTH SHUT_RDWR

	#define WSTRING_FORMATTER "%ls"
#endif

#endif
