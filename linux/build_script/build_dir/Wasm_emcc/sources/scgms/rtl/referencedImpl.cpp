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

#include "referencedImpl.h"

#include "manufactory.h"
#include <limits>
#include <algorithm>
#include <iostream>

#undef max
#undef min

namespace refcnt {

	HRESULT CReferenced::QueryInterface(const GUID*  riid, void ** ppvObj) {
		return E_NOTIMPL;
	}

	ULONG IfaceCalling CReferenced::AddRef() {
		return mCounter++ + 1;
	}

	ULONG IfaceCalling CReferenced::Release() {
		ULONG rc = mCounter-- - 1;	//fetch_sub returns the old value!
		if (rc == 0) delete this;

		return rc;
	}


	ULONG IfaceCalling CNotReferenced::AddRef() {
		return std::numeric_limits<ULONG>::max();
	}

	ULONG IfaceCalling CNotReferenced::Release() {
		return std::numeric_limits<ULONG>::max();
	}

	std::string Char_Container_To_String(str_container *container) {
		return Container_To_Vector<char, std::string>(container);
	}


	std::wstring WChar_Container_To_WString(refcnt::wstr_container *container) {
		return Container_To_Vector<wchar_t, std::wstring>(container);
	}

	std::shared_ptr<wstr_container> WString_To_WChar_Container_shared(const wchar_t* str) {
		const size_t len = str != nullptr ? wcslen(str) : 0;
		wchar_t *str_ptr = const_cast<wchar_t*>(str);
		return Create_Container_shared<wchar_t>(str_ptr, str_ptr + len);
	}

	wstr_container* WString_To_WChar_Container(const wchar_t* str) {
		const size_t len = str != nullptr ? wcslen(str) : 0;
		wchar_t *str_ptr = const_cast<wchar_t*>(str);
		return Create_Container<wchar_t>(str_ptr, str_ptr + len);
	}

	bool WChar_Container_Equals_WString(wstr_container *container, const wchar_t* str, size_t offset, size_t maxCount) {
		wchar_t *cont_begin, *cont_end;

		if (container->get(&cont_begin, &cont_end) != S_OK || !str) return false;	//cannot compare

		cont_begin += offset;
		if (cont_begin >= cont_end)
			return false;

		const size_t cont_len = static_cast<size_t>(cont_end - cont_begin);
		if (maxCount == (size_t)-1 && cont_len != wcslen(str)) return false;	//different size, thus not equal

		return wmemcmp(cont_begin, str, std::min(cont_len, maxCount > 0 ? maxCount : wcslen(str))) == 0;
	}


	void Swstr_container::set(const wchar_t *str) {
		if (operator bool()) {
			wchar_t *str_ptr = const_cast<wchar_t*>(str);
			const size_t str_len = str == nullptr ? 0 : wcslen(str);

			if (str_len>0) get()->set(str_ptr, str_ptr + str_len);
				else get()->set(nullptr, nullptr);
		}
	}


	bool Swstr_container::operator==(const wchar_t *other) const {
		if (!operator bool()) return false;

		return WChar_Container_Equals_WString(get(), other);
	}

	Swstr_list::Swstr_list() : SReferenced<refcnt::wstr_list>{ Create_Container<refcnt::wstr_container*>(nullptr, nullptr) } {
		if (operator bool())
			get()->Release();	//both ctor and Create_Container called AddRef => one AddRef is excessive
	}


	void Swstr_list::push(const wchar_t* wstr) {
		if (operator bool()) {
			auto container = WString_To_WChar_Container_shared(wstr);
			auto container_raw = container.get();
			if (container) get()->add(&container_raw, &container_raw + 1);
		}

	}

	void Swstr_list::push(const std::wstring& wstr) {
		push(wstr.c_str());
	}


	void Swstr_list::for_each(std::function<void(const std::wstring& wstr)> callback) const {
		refcnt::wstr_container** begin, ** end;
		HRESULT rc = refcnt::SReferenced<refcnt::wstr_list>::get()->get(&begin, &end);
		if (rc != S_OK) return;


		for (; begin != end; begin++)
			callback(refcnt::WChar_Container_To_WString(*begin));
	}
}
