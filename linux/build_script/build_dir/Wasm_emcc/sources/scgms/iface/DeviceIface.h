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

#include <limits>
#include <array>

#undef max

namespace scgms {

	// mg/dL -> mmol/L; source: http://www.soc-bdr.org/rds/authors/unit_tables_conversions_and_genetic_dictionaries/conversion_glucose_mg_dl_to_mmol_l/index_en.html
	constexpr double mgdL_2_mmolL = 1.0 / 18.0182;
	constexpr double mmolL_2_mgdL = 18.0182;
	// pmol -> U; source: http://www.soc-bdr.org/content/rds/authors/unit_tables_conversions_and_genetic_dictionaries/e5196/index_en.html
	constexpr double pmol_2_U = 1.0 / 6000.0;

	constexpr double One_Hour = 1.0 / (24.0);
	constexpr double One_Minute = 1.0 / (24.0 * 60.0);
	constexpr double One_Second = 1.0 / (24.0 * 60.0 * 60.0);

	inline namespace literals {

		inline constexpr long double operator ""_hr(long double val) {
			return val * ::scgms::One_Hour;
		}
		inline constexpr long double operator ""_min(long double val) {
			return val * ::scgms::One_Minute;
		}
		inline constexpr long double operator ""_sec(long double val) {
			return val * ::scgms::One_Second;
		}

		inline constexpr long double operator ""_hr(unsigned long long val) {
			return static_cast<long double>(val) * ::scgms::One_Hour;
		}
		inline constexpr long double operator ""_min(unsigned long long val) {
			return static_cast<long double>(val) * ::scgms::One_Minute;
		}
		inline constexpr long double operator ""_sec(unsigned long long val) {
			return static_cast<long double>(val) * ::scgms::One_Second;
		}

	}

	const size_t apxNo_Derivation = 0;
	const size_t apxFirst_Order_Derivation = 1;

	/*
		The time is encoded as the number of days since January 0, 1900 00:00 UTC, see
		http://en.wikipedia.org/wiki/January_0

		Integral part stores the number of days, fractional part stores the time.
		It could have been any fixed dates, but this one is compatible with
		FreePascal, Delphi and Microsoft Products such as Excel, Access and COM's variant in general.

		Therefore, 01 Jan 1900 00:00 would be 1.0 and 01 Jan 1900 24:00 would be 2.0

		However, the UI is supposed to use QDateTime whose epoch starts on 1.1. 1970 0:0 UTC0 aka UNIX epoch start.
		But note that leap seconds are not calculated with when using the UNIX epoch!
	*/

	// special GUID value that means "all signal ids" - it is used especially in modules, which are able to work with a set of signals
	constexpr GUID signal_All = { 0xffffffff, 0xffff, 0xffff, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff } };	// {FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF}
	constexpr GUID signal_Null = { 0x706e7fdb, 0x8f22, 0x486f, { 0xbf, 0xa5, 0x6a, 0x56, 0xd3, 0x51, 0x42, 0x9 } }; // {706E7FDB-8F22-486F-BFA5-6A56D3514209}

	//Synchronization signal - used in DoD trainer, Icarus and similar frontends, where the whole chain is synchronized to an external clock-like signal
	constexpr GUID signal_Synchronization = { 0x97f2d189, 0x2319, 0x4a4a, { 0x8c, 0xbe, 0x5d, 0xdd, 0xd6, 0x0, 0x5f, 0x81 } };	// {97F2D189-2319-4A4A-8CBE-5DDDD6005F81}

	//Measured signals
	constexpr GUID signal_BG = { 0xf666f6c2, 0xd7c0, 0x43e8,{ 0x8e, 0xe1, 0xc8, 0xca, 0xa8, 0xf8, 0x60, 0xe5 } };	// {F666F6C2-D7C0-43E8-8EE1-C8CAA8F860E5}
	constexpr GUID signal_IG = { 0x3034568d, 0xf498, 0x455b,{ 0xac, 0x6a, 0xbc, 0xf3, 0x1, 0xf6, 0x9c, 0x9e } };		// {3034568D-F498-455B-AC6A-BCF301F69C9E}
	constexpr GUID signal_ISIG = { 0x3f62c28a, 0x4d25, 0x4086,{ 0xbd, 0x1a, 0xfc, 0x44, 0x2f, 0xdd, 0xb7, 0xcf } };		// {3F62C28A-4D25-4086-BD1A-FC442FDDB7CF}
	constexpr GUID signal_BG_Calibration = { 0xed4cd0f5, 0xf728, 0x44fe,{ 0x95, 0x52, 0x97, 0x33, 0x8b, 0xd7, 0xe8, 0xd5 } };	// {ED4CD0F5-F728-44FE-9552-97338BD7E8D5}

	//Control signals
	constexpr GUID signal_Requested_Insulin_Basal_Rate = { 0xb5897bbd, 0x1e32, 0x408a, { 0xa0, 0xd5, 0xc5, 0xbf, 0xec, 0xf4, 0x47, 0xd9 } };	// {B5897BBD-1E32-408A-A0D5-C5BFECF447D9}
	constexpr GUID signal_Requested_Insulin_Bolus = { 0x9b16b4a, 0x54c2, 0x4c6a, { 0x94, 0x8a, 0x3d, 0xef, 0x85, 0x33, 0x5, 0x9b } };		// {09B16B4A-54C2-4C6A-948A-3DEF8533059B} 
	constexpr GUID signal_Requested_Insulin_Intradermal_Rate = { 0x7fd34ce1, 0xe943, 0x4e60, { 0xbf, 0x82, 0xac, 0x55, 0x2c, 0xc0, 0x8, 0xf3 } };	// {7FD34CE1-E943-4E60-BF82-AC552CC008F3}
	constexpr GUID signal_Delivered_Insulin_Inhaled = { 0xda153f7f, 0x84a5, 0x4fd8, { 0x85, 0x99, 0x0, 0x1f, 0xae, 0xb0, 0x9d, 0x3a } };			// {DA153F7F-84A5-4FD8-8599-001FAEB09D3A}

	//Control-feedback signals
	constexpr GUID signal_Delivered_Insulin_Bolus = { 0x22d87566, 0xaf1b, 0x4cc7,{ 0x8d, 0x11, 0xc5, 0xe0, 0x4e, 0x1e, 0x9c, 0x8a } }; 	 // {22D87566-AF1B-4CC7-8D11-C5E04E1E9C8A}
	constexpr GUID signal_Delivered_Insulin_Basal_Rate = { 0xbf88a8cb, 0x1290, 0x4477, { 0xa2, 0xcf, 0xbd, 0xd0, 0x6d, 0xf6, 0x28, 0xab } }; 	 // {BF88A8CB-1290-4477-A2CF-BDD06DF628AB}
	constexpr GUID signal_Delivered_Insulin_Total = { 0xee655943, 0x6bf, 0x4f9d, { 0xb2, 0x7d, 0xaa, 0xcb, 0x39, 0x43, 0xfb, 0x91 } };	 // {EE655943-06BF-4F9D-B27D-AACB3943FB91}
	constexpr GUID signal_Delivered_Insulin_Intradermal_Rate = { 0xe92aac08, 0xf468, 0x4059, { 0x9d, 0xdf, 0x92, 0x8b, 0x92, 0x5f, 0xa5, 0xe } };// {E92AAC08-F468-4059-9DDF-928B925FA50E}

	//Physiological activity
	constexpr GUID signal_Insulin_Activity = { 0xdd057b62, 0xcbd9, 0x45e2, { 0xb1, 0x2, 0xde, 0x94, 0x10, 0x49, 0xa5, 0x5a } };	 // {DD057B62-CBD9-45E2-B102-DE941049A55A}
	constexpr GUID signal_IOB = { 0x313a1c11, 0x6bac, 0x46e2, { 0x89, 0x38, 0x73, 0x53, 0x40, 0x9f, 0x2f, 0xcd } };			// {313A1C11-6BAC-46E2-8938-7353409F2FCD}
	constexpr GUID signal_COB = { 0xb74aa581, 0x538c, 0x4b30, { 0xb7, 0x64, 0x5b, 0xd0, 0xd9, 0x7b, 0x7, 0x27 } };			// {B74AA581-538C-4B30-B764-5BD0D97B0727}
	constexpr GUID signal_Carb_Intake = { 0x37aa6ac1, 0x6984, 0x4a06,{ 0x92, 0xcc, 0xa6, 0x60, 0x11, 0xd, 0xd, 0xc7 } };	// {37AA6AC1-6984-4A06-92CC-A660110D0DC7}
	constexpr GUID signal_Carb_Rescue =  { 0xf24920f7, 0x3f7b, 0x4000, { 0xb2, 0xd0, 0x37, 0x4f, 0x94, 0xe, 0x48, 0x98 } }; // {F24920F7-3F7B-4000-B2D0-374F940E4898}
			//signal_Physical_Activity == 1.0 means the basal metabolism activity when awake; 0.0 means death
	constexpr GUID signal_Physical_Activity = { 0xf4438e9a, 0xdd52, 0x45bd,{ 0x83, 0xce, 0x5e, 0x93, 0x61, 0x5e, 0x62, 0xbd } }; // {F4438E9A-DD52-45BD-83CE-5E93615E62BD}			
	constexpr GUID signal_Insulin_Sensitivity = { 0x100576f2, 0x8c2, 0x4959, { 0xb3, 0x14, 0x5a, 0x8c, 0x49, 0x29, 0x6c, 0x2 } };	// {100576F2-08C2-4959-B314-5A8C49296C02}
	constexpr GUID signal_Carb_Ratio = { 0xe8dc8ba1, 0x15b4, 0x4f80, { 0xb8, 0xd7, 0xb4, 0xe7, 0xb3, 0x2e, 0xd5, 0x1e } };			// {E8DC8BA1-15B4-4F80-B8D7-B4E7B32ED51E}

	constexpr GUID signal_Skin_Temperature = { 0x6fb4aa36, 0xc05b, 0x4686, { 0x9e, 0x87, 0xce, 0x62, 0xac, 0x3c, 0xc5, 0x51 } };// {6FB4AA36-C05B-4686-9E87-CE62AC3CC551}
	constexpr GUID signal_Air_Temperature = { 0x1ab2abf6, 0xe719, 0x499d, { 0xa5, 0x80, 0xee, 0xf2, 0xe5, 0xba, 0x40, 0xe5 } };	// {1AB2ABF6-E719-499D-A580-EEF2E5BA40E5}
	constexpr GUID signal_Heartbeat = { 0x6dfcfd02, 0xc48c, 0x4ce0, { 0xbd, 0x82, 0x2d, 0x94, 0x1e, 0x76, 0x7a, 0x99 } }; // {6DFCFD02-C48C-4CE0-BD82-2D941E767A99}
	constexpr GUID signal_Electrodermal_Activity = { 0xacff91a6, 0xd9fd, 0x490e, { 0x9b, 0xe9, 0xe2, 0xb7, 0xb5, 0x46, 0x9, 0xc2 } }; // {ACFF91A6-D9FD-490E-9BE9-E2B7B54609C2}
	constexpr GUID signal_Steps = { 0xd0d33895, 0xfbe8, 0x462a, { 0xb4, 0x5a, 0xaf, 0x2e, 0xe9, 0x7f, 0xe6, 0x81 } };// {D0D33895-FBE8-462A-B45A-AF2EE97FE681}
	constexpr GUID signal_Sleep_Quality = { 0xb4fc34ad, 0xb65a, 0x4775, { 0x82, 0xc5, 0x16, 0xa4, 0x7b, 0x33, 0xe9, 0xb6 } };	// {B4FC34AD-B65A-4775-82C5-16A47B33E9B6}
	constexpr GUID signal_Acceleration = { 0xc22ef521, 0xf5a4, 0x49de, { 0xa8, 0x8e, 0xf4, 0x46, 0x59, 0xc, 0x99, 0x75 } }; // {C22EF521-F5A4-49DE-A88E-F446590C9975}
	constexpr GUID signal_Movement_Speed = { 0xa42c3bde, 0x5d45, 0x4671, { 0x9a, 0x72, 0x39, 0x52, 0x55, 0xc1, 0x42, 0x45 } }; // {A42C3BDE-5D45-4671-9A72-395255C14245}

	//virtual signals used for temporal remapping
	extern const std::array<GUID, 100> signal_Virtual;

	using IModel_Parameter_Vector = refcnt::double_container;

	enum class NDevice_Event_Code : uint8_t {
		Nothing = 0,		//internal event of the object
		Shut_Down,			//transform the filter to the "Zombie" state (see Linux task state) so that it still can provide data
							//via an inspection interface (obtained by QueryInterface), but performs no tasks
							//SmartCGMS can invoke filter's destructor without sending the Shut_Down event first

		Level,				//level contains newly measured or calculated level of a given signal
		Masked_Level,		//level not advertised for solving, i.e., tranining, but for testing set
		Parameters,			//new parameters are available for a given signal
		Parameters_Hint,	//some solver requires e.g., initial estimate of the model parameters so that
							//params stored in non-volatile memory should be broadcasted so that
							//solvers and calculators can use them

		//-------- simulation related codes ------
		Suspend_Parameter_Solving,
		Resume_Parameter_Solving,
		Solve_Parameters,	//user can either request to recalculate, or we can request to recalculate it at the end of the segment - i.e., prior sending Time_Segment_Stop
		Time_Segment_Start,
		Time_Segment_Stop,
		Warm_Reset,			//any received data are thrown away, self-calculated parameters are kept and DB/File input filters replays the data from begining
							//this is an analogy to x86 jumping to the reset-vector address

		//-------- codes intended for log parsers ------
		Information,
		Warning,
		Error,

		count
	};


	struct TDevice_Event {
		NDevice_Event_Code event_code = NDevice_Event_Code::Nothing;

		GUID device_id = Invalid_GUID;					//supporting parallel measurements
		GUID signal_id = Invalid_GUID;					//blood, ist, isig, model id aka e.g, calculated blood, etc.
														//discrete_model is also allowed as it may produce multiple signals

		double device_time = std::numeric_limits<double>::quiet_NaN();	//signal with multiple values are aggregated by device_time with the same signal_id and device_id
		int64_t logical_time = std::numeric_limits<int64_t>::max();

		uint64_t segment_id = std::numeric_limits<uint64_t>::max();			// segment identifier or Invalid_Segment_Id

		union {
			double level = 0.0;
			IModel_Parameter_Vector* parameters;		//this will have to be marshalled
														//as different models have different number of parameters, statically sized field would case over-complicated code later on
			refcnt::wstr_container* info;				//information, warning, error 
		};
	};

	//To make TDevice_Event handling more efficient, particulalry when passing through the pipe,
	//IDevice_Event exposes TDevice_Event container iface so that the pipe can accept and pass throught only a pointer, not the entire structure.
	//This way, we avoid the overhead of copying size_of(TDevice_Event) so many times.
	class IDevice_Event : public virtual refcnt::IUnique_Reference {
	public:
		// provides pointer to the contained TDevice_Event (free to modify as needed)
		virtual HRESULT IfaceCalling Raw(TDevice_Event **raw) = 0;
		virtual HRESULT IfaceCalling Clone(IDevice_Event** event) const = 0;
	};

	static constexpr decltype(TDevice_Event::segment_id) Invalid_Segment_Id = std::numeric_limits<decltype(Invalid_Segment_Id)>::max();
	static constexpr decltype(TDevice_Event::segment_id) All_Segments_Id = std::numeric_limits<decltype(All_Segments_Id)>::max() - 1;

	struct TBounds {
		double Min, Max;
	};

	class ISignal : public virtual refcnt::IReferenced {
	public:
		/* on S_OK, *filled elements were copied into times and double levels of the count size
		   for measured signal, it returns the measured values
		   for calculated signal, it returns E_NOIMPL
		*/
		virtual HRESULT IfaceCalling Get_Discrete_Levels(double* const times, double* const levels, const size_t count, size_t *filled) const = 0;

		/* gets bounds and level_count, any of these parameters can be nullptr
		   for measured and calculated signals, dtto Get_Discrete_Levels
		*/
		virtual HRESULT IfaceCalling Get_Discrete_Bounds(TBounds* const time_bounds, TBounds* const level_bounds, size_t *level_count) const = 0;

		/* adds measured levels to internal containers
		   for measured and calculated signals, dtto Get_Discrete_Levels
		*/
		virtual HRESULT IfaceCalling Update_Levels(const double *times, const double *levels, const size_t count) = 0;

		/*
			this method will be called in parallel by solvers and therefore it has to be const

			params - params from which to calculate the signal
						can be nullptr to indicate use of default parameters
			times - times at which to get the levels, i.e., y values for x values
			levels - the levels, must be already allocated with size of count
					- level that cannot be calculated must be se to quiet nan
			count - the total number of times for which to get the levels
			derivation_order - order of derivation requested
		*/
		virtual HRESULT IfaceCalling Get_Continuous_Levels(IModel_Parameter_Vector *params,
			const double* times, double* const levels, const size_t count, const size_t derivation_order) const = 0;

		// returns default parameters on calculated signals, E_NOIMPL on measured signal
		virtual HRESULT IfaceCalling Get_Default_Parameters(IModel_Parameter_Vector *parameters) const = 0;
	};


	class ITime_Segment : public virtual refcnt::IReferenced {
	public:
		// retrieves or creates signal with given id; calls AddRef on returned object
		virtual HRESULT IfaceCalling Get_Signal(const GUID *signal_id, ISignal **signal) = 0;
	};

	// segment provides source levels for the calculation
	// only ITime_Segment::Get_Signal is supposed to call this function to avoid (although not probihit) creating of over-complex segment-graphs
	// approx can be nullptr to use a default one
	using TCreate_Signal = HRESULT(IfaceCalling *)(const GUID *calc_id, ITime_Segment *segment, const GUID *approx_id, ISignal **signal);

	using TCreate_Device_Event = HRESULT(IfaceCalling *)(scgms::NDevice_Event_Code code, scgms::IDevice_Event **event);
}
