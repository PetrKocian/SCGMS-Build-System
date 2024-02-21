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
#include "winapi_mapping.h"

#ifdef FREERTOS
extern "C"{
#include <print.h>
#include <FreeRTOS/Source/include/portable.h>
}

#endif
#ifdef _WIN32
#else

#ifdef __cplusplus
	#include <string>
	#include <cstdlib>
#else
	#include <string.h>
	#include <stdlib.h>
#endif

EXTERN_C void localtime_s(struct tm* t, const time_t* tim)
{
	localtime_r(tim, t);
}

EXTERN_C void gmtime_s(struct tm* t, const time_t* tim)
{
	gmtime_r(tim, t);
}

EXTERN_C void* _aligned_malloc(size_t n, size_t alignment)
{
	void* mem = NULL;
#if defined(WASM) || defined(ESP32) 
	mem = malloc(n);
#elif defined(FREERTOS)
	mem = pvPortMalloc(n);
#endif

#endif

	return mem;
}

EXTERN_C void* _aligned_malloc_dbg(size_t n, size_t alignment, const char* filename, int line)
{
	return _aligned_malloc(n, alignment);
}

EXTERN_C void _aligned_free(void* _Block)
{
#if defined(WASM) || defined(ESP32) 
    free(_Block);
#elif defined(FREERTOS)
	vPortFree(_Block);
#endif
}

EXTERN_C int getenv_s(size_t *len, char *value, size_t valuesz, const char *name)
{
	char* env = getenv(name);
	if (!env)
		return 1;

	if (value)
		value = env;

	*len = 1;//strlen(env);
	return 0;
}
