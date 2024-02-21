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

#include "../iface/referencedIface.h"
#include "manufactory.h"
#include "AlignmentAllocator.h"

#include <atomic>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

namespace refcnt {

	class CReferenced : public virtual IReferenced {
	protected:
#if defined(ESP32) || defined(WASM)
		std::atomic<ULONG> mCounter;
#elif defined(FREERTOS)
		ULONG mCounter;
#endif
		template <typename I>
		bool Internal_Query_Interface(const GUID &I_id, const GUID &riid, void **ppvObj) {
			const bool result = (I_id == riid);
			if (result) {
				*ppvObj = dynamic_cast<I*>(this);
				AddRef();
			}

			return result;
		}
	public:
		CReferenced() noexcept : mCounter(0) {};
		virtual ~CReferenced() {};

		virtual HRESULT IfaceCalling QueryInterface(const GUID*  riid, void ** ppvObj);
		virtual ULONG IfaceCalling AddRef();
		virtual ULONG IfaceCalling Release();
	};


	class CNotReferenced : public CReferenced {
	public:
		virtual ULONG IfaceCalling AddRef();
		virtual ULONG IfaceCalling Release();
	};


	template <typename I>
	class SReferenced : public std::shared_ptr<I> {
	public:
		SReferenced() : std::shared_ptr<I>() {}

		SReferenced(I *obj) {			
			if (obj) obj->AddRef();
			std::shared_ptr<I>::reset(obj, [](I* obj_to_release) { if (obj_to_release != nullptr) obj_to_release->Release(); });
		}		

		virtual ~SReferenced() = default;

		SReferenced& operator=(I*) = delete;
		template< class Y, class Deleter >
		SReferenced& operator=(std::unique_ptr<Y, Deleter>&& r) = delete;
	};

	template <class T, class I, class S, typename... Args>
	S Manufacture_Object_Shared(Args... args) {
		I* manufactured;
		S result;

		if (Manufacture_Object<T, I>(&manufactured, args...) == S_OK)
			result = refcnt::make_shared_reference_ext<S, I>(manufactured, false);

		return result;
	}

	namespace internal {

		#pragma warning( push )
		#pragma warning( disable : 4250 ) // C4250 - 'class1' : inherits 'class2::member' via dominance
	
		template <typename T>
		class CVector_Container : public virtual IVector_Container<T>, public virtual CReferenced {
		protected:
			std::vector<T, AlignmentAllocator<T>> mData;	//be aware that STL templates do not have virtual dtor => any inheritance is a non-standard behavior
															//Hence, STL objet can became garbage sooner than assume and e.g., clang is just like this case and we do inherit from std::vector
															//STL was not designed for inheritance (also we do here) https://www.stroustrup.com/oopsla.pdf
															//See The C++ Programming Language, in section 16.3.4, where he adds the following warning : 
															//"...derivation from a concrete class should be done with care and only rarely because of the lack of virtual functions and run-time type information..
															//=> we would have to add member struct with any method to uniqe_ptr, which is an overhead both to performance and code complexity.
		private:
			template <typename D = typename std::remove_pointer<T>::type>
			typename std::enable_if<!std::is_base_of<refcnt::IReferenced, D>::value && !std::is_base_of<refcnt::IUnique_Reference, D>::value, void>::type
			Add_Content(T *begin, T *end) {
				std::copy(begin, end, std::back_inserter(mData));
			};

			template <typename D = typename std::remove_pointer<T>::type>
			typename std::enable_if<std::is_base_of<refcnt::IReferenced, D>::value, void>::type
			Add_Content(T *begin, T *end) {
				for (T* iter = begin; iter != end; iter++) {
					T real_ptr = *iter;
					mData.push_back(real_ptr);
					real_ptr->AddRef();
				}
			}

			template <typename D = typename std::remove_pointer<T>::type>
			typename std::enable_if<std::is_base_of<refcnt::IUnique_Reference, D>::value, void>::type
			Add_Content(T *begin, T *end) {
				for (T* iter = begin; iter != end; iter++) {
					T real_ptr = *iter;
					mData.push_back(std::move(real_ptr));
					*iter = nullptr;	//now, we own the unique reference and therefore we clean the caller's data not to ever use the reference again
				}
			}


			template <typename D = typename std::remove_pointer<T>::type>
			typename std::enable_if<!std::is_base_of<refcnt::IReferenced, D>::value && !std::is_base_of<refcnt::IUnique_Reference, D>::value, void>::type
			Release_Item(T &item) {};

			template <typename D = typename std::remove_pointer<T>::type>
			typename std::enable_if<std::is_base_of<refcnt::IReferenced, D>::value || std::is_base_of<refcnt::IUnique_Reference, D>::value, void>::type
			Release_Item(T &item) {				
				item->Release();	//as we own both kind of references, we release them
			}

			void Release_Content() {
				for (T &item : mData)
					Release_Item(item);	//as we own both kind of references, we release them
			}
			

		public:
			virtual ~CVector_Container() { Release_Content();  };

			virtual HRESULT IfaceCalling set(T *begin, T *end) override final {
				Release_Content();
				mData.clear();
				return add(begin, end);
			}

			virtual HRESULT IfaceCalling add(T *begin, T *end) override {
				if (begin != nullptr)
					Add_Content(begin, end);
				return S_OK;
			}

			virtual HRESULT IfaceCalling get(T **begin, T **end) const override final {
				const size_t sz = mData.size();
				if (sz > 0) {
					const auto dta = const_cast<T*>(mData.data());
					*begin = dta;
					*end = dta + sz;
					return S_OK;
				} else {
					*begin = *end = nullptr;
					return S_FALSE;
				}
			}
		
			virtual HRESULT IfaceCalling pop(T* value) override final {
				if (mData.empty()) return S_FALSE;

				*value = mData.back();
				mData.pop_back();

				//there is no reference add_refing/releasing needed, because we are moving from the vector out
				return S_OK;
			}

			virtual HRESULT IfaceCalling remove(const size_t index) override {
				if (mData.empty()) return S_FALSE;
								
				Release_Item(mData.operator [](index) );
				mData.erase(mData.begin() + index);
				
				return S_OK;
			}

			virtual HRESULT IfaceCalling move(const size_t from_index, const size_t to_index) override {
				const size_t sz = mData.size();
				if ((from_index >= sz) ||
					(to_index >= sz) ||
					(from_index == to_index)) return E_INVALIDARG;

				if (from_index < to_index)	// move down = rotate left by 1 element on given range
					std::rotate(mData.begin() + from_index, mData.begin() + from_index + 1, mData.begin() + to_index + 1);
				else						// move up = rotate right by 1 element on given range = rotate left by whole range minus 1
					std::rotate(mData.begin() + to_index, mData.begin() + from_index, mData.begin() + from_index + 1);
				

				return S_OK;
			}

			virtual HRESULT IfaceCalling empty() const override final {
				return mData.empty() ? S_OK : S_FALSE;
			}
		};


		template <typename T>
		class CVector_View : public virtual IVector_Container<T>, public virtual CNotReferenced  {
		protected:
			const T *mBegin, *mEnd;
		public:
			CVector_View(const T *begin, const T *end) : mBegin(begin), mEnd(end) {}

			virtual HRESULT IfaceCalling set(T *begin, T *end) override final { return E_NOTIMPL; };
			virtual HRESULT IfaceCalling add(T *begin, T *end) override final { return E_NOTIMPL; };
			virtual HRESULT IfaceCalling get(T** begin, T** end) const override final { *begin = const_cast<T*>(mBegin); *end = const_cast<T*>(mEnd); return S_OK; }
			virtual HRESULT IfaceCalling pop(T* value) override final { return E_NOTIMPL; };
			virtual HRESULT IfaceCalling remove(const size_t index) override final { return E_NOTIMPL; };
			virtual HRESULT IfaceCalling move(const size_t from_index, const size_t to_index) override final { return E_NOTIMPL; };
			virtual HRESULT IfaceCalling empty() const override final { return mEnd <= mBegin ? S_OK : S_FALSE; };
		};

		#pragma warning( pop ) 
	}

	

	template <typename T>
	IVector_Container<T>* Create_Container(T *begin, T *end) {
		IVector_Container<T> *obj = nullptr;
		if (Manufacture_Object<internal::CVector_Container<T>, IVector_Container<T>>(&obj) == S_OK) {
			if (!Succeeded(obj->set(begin, end))) {
				obj->Release();
				obj = nullptr;
			};
		}
		return obj;
	}

	template <typename T>
	class SVector_Container : public std::shared_ptr<IVector_Container<T>> {
	protected:
		T* get_bound(const bool first) const {
			//Do not cache these values as we cannot track every possible modification of the underlying vector.
			//Hence, the code complexity is less or comparable to a stack-constructed solution that would cache both values once needed.
			T* b = nullptr;
			T* e = nullptr;

			if (this->operator bool()) {
				if (std::shared_ptr<IVector_Container<T>>::get()->get(&b, &e) != S_OK)
					return nullptr;
			}

			return first ? b : e;
		}
	public:
		T* begin() const { return get_bound(true); } ;
		T* end() const { return get_bound(false); };
	};


	template <typename T, typename S = SVector_Container<T>>
	S Create_Container_shared(T *begin, T *end) {
		IVector_Container<T> *obj = Create_Container<T>(begin, end);
		return refcnt::make_shared_reference_ext <S, IVector_Container<T>>(obj, false);
	}

	template <typename T, typename I = IVector_Container<T>>
	I* Copy_Container(I* src) {
		I* result = nullptr;

		if (src) {
			// copy parameter hint to internal vector
			T *begin, *end;
			if (src->get(&begin, &end) == S_OK)
				result = Create_Container<T>(begin, end);
		}

		return result;
	}

	template <typename T, typename S = SVector_Container<T>>
	S Copy_Container_shared(IVector_Container<T>* src) {
		S result;
	
		if (src) {
			// copy parameter hint to internal vector
			T* begin, * end;
			if (src->get(&begin, &end) == S_OK)
				result = Create_Container_shared<T, S>(begin, end);
		}

		return result;
	}

	template <typename T, typename S = SVector_Container<T>>
	S Copy_Container(SVector_Container<T> src) {
		S result;
		// copy parameter hint to internal vector
		T *begin, *end;
		if (src->get(&begin, &end) == S_OK)
			result = Create_Container_shared<T, S>(begin, end);

		return result;
	}


	template <typename T, typename C = std::vector<T>>
	C Container_To_Vector(IVector_Container<T> *container) {
		T *begin, *end;
		if ((container) && (container->get(&begin, &end) == S_OK)) {
			return C{ begin, end };
		}
		else
			return C{};
	}

	std::string Char_Container_To_String(str_container *container);
	
	std::wstring WChar_Container_To_WString(wstr_container *container);
	wstr_container* WString_To_WChar_Container(const wchar_t* str);
	std::shared_ptr<wstr_container> WString_To_WChar_Container_shared(const wchar_t* str);
	bool WChar_Container_Equals_WString(wstr_container *container, const wchar_t* str, size_t offset = 0, size_t maxCount = (size_t)-1);



	template <typename S, typename I>
	std::vector<S> Referenced_To_Vector(I **items, const size_t count) {
		std::vector<S> result;

		for (size_t i = 0; i < count; i++)
			result.push_back(refcnt::make_shared_reference_ext<S, I>(const_cast<I*>(items[i]), true));

		return result;
	}


	class Swstr_container : public virtual std::shared_ptr<refcnt::wstr_container> {
	public:
		Swstr_container& operator=(const Swstr_container&) = default;	//https://stackoverflow.com/questions/34554612/warning-defaulted-move-assignment-operator-of-x-will-move-assign-virtual-base-c
		void set(const wchar_t *str);
		bool operator==(const wchar_t *other) const;
	};

	class Swstr_list : public virtual refcnt::SReferenced<refcnt::wstr_list> {
	public:
		Swstr_list();
		void push(const wchar_t* wstr);
		void push(const std::wstring &wstr);

		void for_each(std::function<void(const std::wstring &wstr)> callback) const;
	};
	
}
