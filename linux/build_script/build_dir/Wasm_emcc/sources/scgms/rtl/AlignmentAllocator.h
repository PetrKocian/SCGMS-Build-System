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

#include <stdlib.h>
#include "../utils/winapi_mapping.h"

const size_t AVX2Alignment = 64;

template <typename T, size_t N = AVX2Alignment>
class AlignmentAllocator {
		//usage e.g., std::vector<CDiffusion3SolverSegment*, AlignmentAllocator<CDiffusion3SolverSegment*, AVX2Alignment>> mSegments;
public:
	typedef T value_type;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

	typedef T * pointer;
	typedef const T * const_pointer;

	typedef T & reference;
	typedef const T & const_reference;

public:
	inline AlignmentAllocator() throw () { }

	template <typename T2>
	inline AlignmentAllocator(const AlignmentAllocator<T2, N> &) throw () { }

	inline ~AlignmentAllocator() /*throw ()*/ { }

	inline pointer adress(reference r) {
		return &r;
	}

	inline const_pointer adress(const_reference r) const {
		return &r;
	}

	inline pointer allocate(size_type n) {
		return (pointer)_aligned_malloc(n*sizeof(value_type), N);				
	}

	inline void deallocate(pointer p, size_type) {
		_aligned_free(p);
	}

	inline void construct(pointer p, const value_type & wert) {
		new (p)value_type(wert);
	}

	inline void destroy(pointer p) {
		p->~value_type();
	}

	inline size_type max_size() const throw () {
		return size_type(-1) / sizeof(value_type);
	}

	template <typename T2>
	struct rebind {
		typedef AlignmentAllocator<T2, N> other;
	};

	bool operator!=(const AlignmentAllocator<T, N>& other) const  {
		return !(*this == other);
	}

	// Returns true if and only if storage allocated from *this
	// can be deallocated from other, and vice versa.
	// Always returns true for stateless allocators.
	bool operator==(const AlignmentAllocator<T, N>& other) const {
		return true;
	}
};

#if defined(new) && defined(new_operator_replacement)
#undef new
#endif

template <size_t alignment = AVX2Alignment>
class alignas(alignment) CAligned {

		//alignas alings on the stack, overloaded new aligns on the heap
public:
	virtual ~CAligned() {};

	static void* operator new(size_t i) noexcept(false) {
		return _aligned_malloc(i, alignment);
	}

	static void operator delete (void *p) noexcept(false) {
		_aligned_free(p);
	}

	template<typename T>
	static void* operator new(size_t i, T placement, const char* file = nullptr, int line = 0) noexcept(false) {
		return _aligned_malloc_dbg(i, alignment, file, line);
	}

	template<typename T>
	static void operator delete(void *p, T, const char*, int) noexcept(false) {
		_aligned_free(p);
	}
};

#ifdef new_operator_replacement
#define new new_operator_replacement
#endif
