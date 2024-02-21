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

#include "../rtl/hresult.h"

template <typename T, typename A = std::allocator<T>, typename V = std::vector<T, A>>
HRESULT do_get_descriptors(const V &descriptors, T **begin, T **end) {
	if (!descriptors.empty()) {
		*begin = const_cast<T*>(descriptors.data());
		*end = *begin + descriptors.size();
	}
	else
		begin = end = nullptr;
	return begin != nullptr ? S_OK : S_FALSE;
}

constexpr scgms::TSolver_Descriptor Describe_Non_Specialized_Solver(const GUID id, const wchar_t* desc) {
	return scgms::TSolver_Descriptor{
		id,
		desc,
		false,
		0,
		nullptr
	};
}


template <typename R, typename T>
R Set_Value_First_Followers(const T first, const T follower, const size_t param_count) {
	using Q = typename std::remove_const<R>::type;
	Q result;
	result[0] = first;
	for (size_t i = 1; i < param_count; i++)
		result[i] = follower;
	return result;
}

template <typename R>
R Set_Double_First_Followers(const double first, const double follower, const size_t param_count) {
	R result = { first };
	result.vector = Set_Value_First_Followers<decltype(result.vector), double>(first, follower, param_count);
	return result;
}
template <typename R>
R Name_Parameters_First_Followers(const wchar_t* first, const wchar_t* follower_prefix, bool ui, const size_t param_count, std::vector<std::wstring>& name_placeholder) {
	using Q = typename std::remove_const<R>::type;

	Q result = { const_cast<wchar_t*>(first) };
	for (size_t i = 0; i < param_count; i++) {
		std::wstring tmp = follower_prefix;
		tmp += ui ? L' ' : L'_';
		tmp += std::to_wstring(i+1);

		const size_t idx = static_cast<size_t>(2) * i + (ui ? static_cast<size_t>(0) : static_cast<size_t>(1));
		name_placeholder[idx] = std::move(tmp);
		result[i] = const_cast<wchar_t*>(name_placeholder[idx].c_str());
	}

	return result;
}
