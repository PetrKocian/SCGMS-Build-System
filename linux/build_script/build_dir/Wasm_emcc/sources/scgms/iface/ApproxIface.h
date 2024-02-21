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

#include "../rtl/guid.h"
#include "referencedIface.h"
#include "DeviceIface.h"

namespace scgms {
	constexpr GUID apxLine = { 0xb89204aa, 0x5842, 0xa8f1, { 0x4c, 0xa1, 0x43, 0x12, 0x5f, 0x4e, 0xb2, 0xa7 } };		// {B89204AA-5842-A8F1-4CA1-43125F4EB2A7}
	constexpr GUID apxAkima = { 0xc3e9669d, 0x594a, 0x4fd4,{ 0xb0, 0xf4, 0x44, 0xab, 0x9d, 0x4e, 0x7, 0x39 } };			// {C3E9669D-594A-4FD4-B0F4-44AB9D4E0739}
	constexpr GUID apxAvgExpAppx = { 0x97b51526, 0x533b, 0x40ae, { 0xa9, 0xb4, 0x9f, 0xac, 0xfd, 0x82, 0x41, 0x49 } };	// {97B51526-533B-40AE-A9B4-9FACFD824149}
		//primary DOI: 10.1109/ITAB.2010.5687663		following DOI: 10.1007/978-3-319-00846-2_304

	class IApproximator : public virtual refcnt::IReferenced
	{
		public:
			// parameters of approximation curve(s) on given signal (signal is passed in constructor of each approximation) are calculated when
			// performing construction of approximator object;

			// approximates signal levels (or derivations) on given times array of size "count"
			// a call to Approximate method must precede (once per ISignal data set)
			virtual HRESULT IfaceCalling GetLevels(const double* times, double* const levels, const size_t count, const size_t derivation_order) = 0;
	};

	using TCreate_Approximator = HRESULT(IfaceCalling *)(const GUID *approx_id, ISignal *signal, IApproximator **approx);
}
