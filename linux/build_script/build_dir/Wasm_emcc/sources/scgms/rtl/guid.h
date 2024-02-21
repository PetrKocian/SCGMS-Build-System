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

#include <assert.h>

#ifndef SCGMS_GUID_DEFINED

#define SCGMS_GUID_DEFINED

#ifdef _WIN32
	#include <guiddef.h>
#else
	#ifdef __cplusplus
		#include <cstring>
		#include <cstdint>
	#else
		#include <string.h>
		#include <stdint.h>
	#endif

#ifndef GUID_DEFINED
	typedef struct GUID {
		uint32_t Data1;
		uint16_t Data2;
		uint16_t Data3;
		uint8_t  Data4[8];
	} GUID;

	// some libraries expect the constant GUID_DEFINED to be defined in order to avoid redefinition of GUID structure
	#define GUID_DEFINED
#endif

	#ifdef __cplusplus
		static inline int IsEqualGUID(const GUID& rguid1, const GUID& rguid2) {
			return !memcmp(&rguid1, &rguid2, sizeof(GUID));
		}

		static inline bool operator==(const GUID& guidOne, const GUID& guidOther) {
			return !!IsEqualGUID(guidOne, guidOther);
		}

		static inline bool operator!=(const GUID& guidOne, const GUID& guidOther) {
			return !(guidOne == guidOther);
		}
	#else
		static inline int IsEqualGUID(const GUID *rguid1, const GUID *rguid2) {
			return !memcmp(rguid1, rguid2, sizeof(GUID));
		}
	#endif
#endif

#ifdef __cplusplus
	static inline bool operator<(const GUID& rguid1, const GUID& rguid2) {
		return memcmp(&rguid1, &rguid2, sizeof(GUID)) < 0;
	}
	constexpr GUID Invalid_GUID = { 0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } };

	static inline bool Is_Invalid_GUID(const GUID& id) {
		return id == Invalid_GUID;
	}

	template <typename... Args>
	bool Is_Invalid_GUID(const GUID& id, const Args&... args) {
		return Is_Invalid_GUID(id) || Is_Invalid_GUID(args...);
	}


	// on several systems (OS's and compilers), the lengths of standard types may vary (e.g. "unsigned long" on LLP64 vs. LP64);
	// the C++ standard itself defines minimal length, but does not guarantee exact length on every platform;
	// this is here to ensure correct lengths of all GUID fields

	static_assert(sizeof(GUID::Data1) == 4, "GUID Data1 (unsigned long) is not 4 bytes long");
	static_assert(sizeof(GUID::Data2) == 2, "GUID Data2 (unsigned short) is not 2 bytes long");
	static_assert(sizeof(GUID::Data3) == 2, "GUID Data3 is not 2 bytes long");
	static_assert(sizeof(GUID::Data4) == 8, "GUID Data4 is not 8 bytes long");

	#include <typeindex> // for std::hash; this is a "cheaper" standard header, than the functional, that guarantees the proper definition of std::hash

	// explicitly specialize std::hash for GUID type; this is due to occassional need of having the GUID as a key in std::unordered_map or std::unordered_set
	// note, that this is not an extension of namespace std (would be undefined behavior), but just a template specialization, which is allowed by the standard (https://en.cppreference.com/w/cpp/language/extending_std)
	template<>
	struct std::hash<GUID> {

		// combine hashes - this is taken from the boost library (Qt does essentially the same)
		template<typename T>
		inline void hash_combine(std::size_t& cur_hash, T value) const noexcept {
			std::hash<T> hasher;
			cur_hash ^= hasher(value) + 0x9e3779b9 + (cur_hash << 6) + (cur_hash >> 2);
		}

		std::size_t operator()(const GUID& g) const noexcept {
			std::size_t ret = 0;

			hash_combine(ret, g.Data1);
			hash_combine(ret, g.Data2);
			hash_combine(ret, g.Data3);
			for (size_t i = 0; i < 8; i++)
				hash_combine(ret, g.Data4[i]);

			return ret;
		}
	};


	// Generates a new GUID version 4 (completely random, suitable for network traffic)
	// C++ code only for simplicity as C++ has more powerful tools for randnom numbers out of the box
	GUID Generate_GUIDv4();	
#endif

#endif
