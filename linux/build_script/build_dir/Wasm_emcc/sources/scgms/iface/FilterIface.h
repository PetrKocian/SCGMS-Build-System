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

#include <memory>
#include <string>
#include <vector>

#include "DeviceIface.h"
#include "referencedIface.h"
#include "../utils/winapi_mapping.h"

namespace scgms {

	using time_segment_id_container = refcnt::IVector_Container<int64_t>;

	enum class NParameter_Type : size_t {
		ptNull = 0,
		ptWChar_Array,			//IParameter_Container<wchar_t>
		ptInt64_Array,	//alias for IParameter_Container<int64_t> that selects time segments id
		ptDouble,	
		ptRatTime,					//double interperted as the rattime
		ptInt64,
		ptBool,
		ptSignal_Model_Id,
		ptDiscrete_Model_Id,
		ptMetric_Id,
		ptSolver_Id,
		ptModel_Produced_Signal_Id,	// signal dependend on model selection
		ptSignal_Id,		// any signal available (measured, calculated)
		ptDouble_Array,		// three parameter sets in one container - lower bound, default values, higher bound
		ptSubject_Id,		// int64_t, but with additional functionality in GUI

		ptInvalid				//a guardian value to indicate that something went wrong
	}; 

	class IFilter_Parameter : public virtual refcnt::IReferenced {
	public:
		//read-only
		virtual HRESULT IfaceCalling Get_Type(NParameter_Type *type) = 0;
		virtual HRESULT IfaceCalling Get_Config_Name(wchar_t **config_name) = 0;	
		
		//read-write
		virtual HRESULT IfaceCalling Set_Variable(const wchar_t* name, const wchar_t* value) = 0;

		//Get_WChar_Container also attempts to convert to string from a value of the Get_Type()'s type
		virtual HRESULT IfaceCalling Get_WChar_Container(refcnt::wstr_container **wstr, BOOL read_interpreted) = 0;	//$(Variable_Name) reads system-variable with read_interpreted==true
		//Set_WChar_Container attempts from_string conversion_factor according to the Get_Type()'s type, hence it may fail
		virtual HRESULT IfaceCalling Set_WChar_Container(refcnt::wstr_container *wstr) = 0;	
		
		//virtual HRESULT IfaceCalling Get_File_Path(refcnt::wstr_container **wstr) = 0;	//reads interpreted string as filepath, which is absolute-ed with the parent_path, when relative
		//virtual HRESULT IfaceCalling Set_Parent_Path(const wchar_t* parent_path) = 0;
		
		virtual HRESULT IfaceCalling Get_Time_Segment_Id_Container(time_segment_id_container **ids) = 0;
		virtual HRESULT IfaceCalling Set_Time_Segment_Id_Container(time_segment_id_container *ids) = 0;

		virtual HRESULT IfaceCalling Get_Double(double *value) = 0;
		virtual HRESULT IfaceCalling Set_Double(const double value) = 0;

		virtual HRESULT IfaceCalling Get_Int64(int64_t *value) = 0;
		virtual HRESULT IfaceCalling Set_Int64(const int64_t value) = 0;

		virtual HRESULT IfaceCalling Get_Bool(BOOL *boolean) = 0;
		virtual HRESULT IfaceCalling Set_Bool(const BOOL boolean) = 0;

		virtual HRESULT IfaceCalling Get_GUID(GUID *id) = 0;
		virtual HRESULT IfaceCalling Set_GUID(const GUID *id) = 0;

		virtual HRESULT IfaceCalling Get_Model_Parameters(scgms::IModel_Parameter_Vector **parameters) = 0;
		virtual HRESULT IfaceCalling Set_Model_Parameters(scgms::IModel_Parameter_Vector *parameters) = 0;

		//management
		virtual HRESULT IfaceCalling Clone(scgms::IFilter_Parameter **deep_copy) = 0;
	};
	

	using IFilter_Configuration = refcnt::IVector_Container<scgms::IFilter_Parameter*>;
	
	class IFilter_Configuration_Link : public virtual IFilter_Configuration {
	public:
		virtual HRESULT IfaceCalling Get_Filter_Id(GUID *id) = 0;	
		//virtual HRESULT IfaceCalling Set_Parent_Path(const wchar_t* parent_path) = 0;	//sets the parent path in the contained parameters
		virtual HRESULT IfaceCalling Set_Variable(const wchar_t* name, const wchar_t* value) = 0;	
	};

	class IFilter_Chain_Configuration : public virtual refcnt::IVector_Container<IFilter_Configuration_Link*> {
	public:
		//virtual HRESULT IfaceCalling Get_Parent_Path(refcnt::wstr_container** path) = 0;
		//virtual HRESULT IfaceCalling Set_Parent_Path(const wchar_t* parent_path) = 0;
		//use the $(variable_name) syntax to read this additional variables, which complements OS-variables
		virtual HRESULT IfaceCalling Set_Variable(const wchar_t* name, const wchar_t* value) = 0;	//setting value to nullptr erases the variable
	};

	class IPersistent_Filter_Chain_Configuration : public virtual IFilter_Chain_Configuration {
	public:
			//both Load_From_ methods returns S_FALSE if incomplete configuration was constructed
		//virtual HRESULT IfaceCalling Load_From_File(const wchar_t *file_path, refcnt::wstr_list* error_description) = 0;	//file_path cannot be nullptr
		virtual HRESULT IfaceCalling Load_From_Memory(const char *memory, const size_t len, refcnt::wstr_list* error_description) = 0;	//resets internal file path to nullptr
		//virtual HRESULT IfaceCalling Save_To_File(const wchar_t *file_path, refcnt::wstr_list* error_description) = 0; //if nullptr, saves to the file_name previously supplied to Load_From_File		
																				 //=> cannot be called with file_path==nullptr after Load_From_Memory only, returns E_ILLEGAL_METHOD_CALL then
	};	

	class IFilter : public virtual refcnt::IReferenced {
	public:
		//Set up filter configuration, possibly during its execution
		virtual HRESULT IfaceCalling Configure(IFilter_Configuration* configuration, refcnt::wstr_list *error_description) = 0;

		//Executes the filter's control loop
		//when called, the filter owns the event - the filter has to either forward the event, 
		//or call Release on it to discard it
		virtual HRESULT IfaceCalling Execute(scgms::IDevice_Event *event) = 0;	
	};

	class IFilter_Executor : public virtual refcnt::IReferenced {	//IEvent_Sender sends the event to the first filter
	public:
			//whatever Filter_Executor swallows it never releases back => Execute always consumes the event
		virtual HRESULT IfaceCalling Execute(scgms::IDevice_Event *event) = 0;		
			//if wait_for_shutdown, returns once all filters have terminated and joined
			//else attempt to terminate all filters at once and then return
		virtual HRESULT IfaceCalling Terminate(const BOOL wait_for_shutdown) = 0;	
	};
	
	class IFilter_Feedback : public virtual scgms::IFilter {
	public:
		virtual HRESULT IfaceCalling Name(wchar_t** const name) = 0;
	};

	constexpr GUID IID_Filter_Feedback_Receiver = { 0xee9d9028, 0xb714, 0x4412, { 0x98, 0xd8, 0xe5, 0xf7, 0xe5, 0xf1, 0xcf, 0x7a } };
	class IFilter_Feedback_Receiver : public virtual scgms::IFilter_Feedback {
	};

	constexpr GUID IID_Filter_Feedback_Sender = { 0x19d21259, 0x7358, 0x4533, { 0x8c, 0x18, 0x85, 0x65, 0x25, 0xc2, 0x35, 0x9 } };
	class IFilter_Feedback_Sender : public scgms::IFilter_Feedback {
	public:
		virtual HRESULT IfaceCalling Sink(scgms::IFilter_Feedback_Receiver *receiver) = 0;
	};


	class IDiscrete_Model : public virtual scgms::IFilter {
	public:
		virtual HRESULT IfaceCalling Initialize(const double current_time, const uint64_t segment_id) = 0;
		virtual HRESULT IfaceCalling Step(const double time_advance_delta) = 0;	//time_advance_delta == 0.0 means to emit the current state
	};

	using TCreate_Persistent_Filter_Chain_Configuration = HRESULT(IfaceCalling *)(IPersistent_Filter_Chain_Configuration **configuration);
	using TCreate_Filter = HRESULT(IfaceCalling *)(const GUID *id, IFilter *next_filter, scgms::IFilter **filter);
	using TOn_Filter_Created = HRESULT(IfaceCalling *)(scgms::IFilter *filter, const void* data);
	using TExecute_Filter_Configuration = HRESULT(IfaceCalling*)(IFilter_Chain_Configuration *configuration, scgms::TOn_Filter_Created on_filter_created, const void* on_filter_created_data, scgms::IFilter *output, scgms::IFilter_Executor **executor, refcnt::wstr_list *error_description);
	using TCreate_Filter_Parameter = HRESULT(IfaceCalling*)(const scgms::NParameter_Type type, const wchar_t *config_name, scgms::IFilter_Parameter **parameter);
	using TCreate_Filter_Configuration_Link = HRESULT(IfaceCalling*)(const GUID *filter_id, scgms::IFilter_Configuration_Link **link);
	using TCreate_Discrete_Model = HRESULT(IfaceCalling*)(const GUID *model_id, scgms::IModel_Parameter_Vector *parameters, scgms::IFilter *output, scgms::IDiscrete_Model **model);

	//The following GUIDs advertise known filters 		
	constexpr GUID IID_Drawing_Filter = { 0x850a122c, 0x8943, 0xa211,{ 0xc5, 0x14, 0x25, 0xba, 0xa9, 0x14, 0x35, 0x74 } };
	constexpr GUID IID_Drawing_Filter_v2 = { 0xa96b151a, 0xb120, 0x44ec, { 0x9b, 0x10, 0xca, 0x6a, 0x4d, 0x1d, 0x76, 0x8e } }; // {A96B151A-B120-44EC-9B10-CA6A4D1D768E}
	constexpr GUID IID_Log_Filter = { 0xc0e942b9, 0x3928, 0x4b81,{ 0x9b, 0x43, 0xa3, 0x47, 0x66, 0x82, 0x0, 0xBA } };

	//The following interfaces can be access via refcnt::IUnknown::QueryInterface 


	enum class NError_Marker : size_t {
		Average = 0,
		StdDev,
		AIC,
		Sum,
		count
	};

	enum class NError_Percentile : size_t {
		Minimum = 0,
		P25,
		Median,
		P75,
		P95,
		P99,
		Maximum,
		count
	};

	enum class NError_Range : size_t {
		R5,
		R10,
		R25,
		R50,
		count
	};

	// Structure for containing error metric values
	struct TError_Markers {
		union
		{
			double markers[static_cast<size_t>(NError_Marker::count)];
			struct
			{
				double avg;						// average value
				double stddev;					// standard deviation with Bessel's correction
				double aic;						// Akaike's information criterion
				double sum;						// sum of errors
			};
		};
		union
		{
			double percentile[static_cast<size_t>(NError_Percentile::count)]; // min, q1, median, q3, q95, q99, max
			struct
			{
				double minval;					// minimum value (0. percentile)
				double p25;						// 1. quartile (25. percentile)
				double median;					// median (50. percentile)
				double p75;						// 3. quartile (75. percentile)
				double p95;						// 95. percentile
				double p99;						// 99. percentile
				double maxval;					// maximum value ("100." percentile)
			};
		};
		union
		{
			double range[static_cast<size_t>(NError_Range::count)];
			struct
			{
				double r5;						// 5% range
				double r10;						// 10% range
				double r25;						// 25% range
				double r50;						// 50% range
			};
		};
	};
	
	enum class NECDF : size_t {
		min_value = 0,
		p25 = 24,
		median = 49,
		p75 = 74,
		p95 = 94,
		p99 = 98,
		max_value = 99		
	};


	inline NECDF operator++(NECDF& subj, int val) {	//postfix		
		const auto old_value = subj;
		const auto new_value = static_cast<std::underlying_type_t<NECDF>>(subj) + static_cast<std::underlying_type_t<NECDF>>(val == 0 ? 1 : val);
		subj = static_cast<NECDF>(new_value);
		return old_value;
	}

	inline NECDF& operator++(NECDF& subj) {
		subj = operator++(subj, 1);
		return subj;
	}

	struct TECDF : std::array<double, static_cast<size_t>(NECDF::max_value) + 1> {
		double operator[] (const NECDF idx) const {
			return this->std::array<double, static_cast<size_t>(NECDF::max_value) + 1>::operator[](static_cast<size_t>(idx));
		}

		double& operator[] (const NECDF idx) {
			return this->std::array<double, static_cast<size_t>(NECDF::max_value) + 1>::operator[](static_cast<size_t>(idx));
		}
	};


	struct TSignal_Stats {
		double avg, stddev, sum;	//standard deviation with Bessel's correction
		double exc_kurtosis, skewness;
		size_t count;				//number of elements on which we calculate the metrics
		TECDF ecdf;
	};

	// error types
	enum class NError_Type : size_t
	{
		Absolute = 0,
		Relative,
		count
	};

	// supported types of drawing outputs
	enum class TDrawing_Image_Type : size_t
	{
		Graph = 0,
		Day,
		Parkes,
		Clark,
		AGP,
		ECDF,
		Profile_Glucose,
		Profile_Insulin,
		Profile_Carbs,

		count
	};

	// supported diagnosis
	enum class TDiagnosis : size_t
	{
		Type1 = 0,
		Type2,
		Gestational,

		count,
		NotSpecified = Type1
	};

	class ILogical_Clock : public virtual refcnt::IReferenced {
	public:
		//Logical clock, which indicates if there are new data to process, starts with zero - no data to process yet.
		//Clock is the recently obtained value of the logical clock, or zero when not called yet. Hence, this parameter
		//cannot be nullptr. On success, the callee updates *clock to the current value and returns:
		//S_OK - if new data are available, hence the *clock differs from its recent value - by an arbitrary number, not necessarily 1
		//S_FALSE - if no new data are available, hence *clock has not changed
		//E_* otherwise
		virtual HRESULT IfaceCalling Logical_Clock(ULONG *clock) = 0;
	};

	constexpr GUID IID_Signal_Error_Inspection = { 0xfb51bcab, 0x5c2b, 0x45af, { 0x98, 0x80, 0xe3, 0x4d, 0xde, 0xc4, 0x3c, 0x4c } };
	class ISignal_Error_Inspection : public virtual ILogical_Clock {
	public:
		virtual HRESULT IfaceCalling Promise_Metric(const uint64_t segment_id, double* const metric_value, BOOL defer_to_dtor) = 0;
		//return S_OK if there are new data available since object construction or last call of Peek_New_Data_Available		
		virtual HRESULT IfaceCalling Calculate_Signal_Error(const uint64_t segment_id, scgms::TSignal_Stats *absolute_error, scgms::TSignal_Stats *relative_error) = 0;
			//should there be a zero reference level, then absolute_error.count != relative_error.count
		virtual HRESULT IfaceCalling Get_Description(wchar_t** const desc) = 0;
	};

	constexpr GUID IID_Drawing_Filter_Inspection = { 0xd0c81596, 0xdea0, 0x4edf,{ 0x8b, 0x97, 0xe1, 0xd3, 0x78, 0xda, 0xfe, 0x3d } };
	class IDrawing_Filter_Inspection : public virtual refcnt::IReferenced {
	public:
		virtual HRESULT IfaceCalling New_Data_Available() = 0;
		// retrieves generated SVG for given drawing type and diagnosis		
		virtual HRESULT IfaceCalling Draw(TDrawing_Image_Type type, TDiagnosis diagnosis, refcnt::str_container *svg, refcnt::IVector_Container<uint64_t> *segmentIds, refcnt::IVector_Container<GUID> *signalIds) = 0;
	};

	// event export callback function prototype; used in filters implementing IEvent_Export_Filter_Inspection iface
	using TEvent_Export_Callback = HRESULT(*)(NDevice_Event_Code /*event_code*/, GUID* /*device_id*/, GUID* /*signal_id*/, double /*device_time*/, int64_t /*logical_time*/,
												uint64_t /*segment_id*/, double /*level*/, IModel_Parameter_Vector* /*parameters*/, refcnt::wstr_container* /*info*/);

	constexpr GUID IID_Event_Export_Filter_Inspection = { 0x22724c4b, 0x57e5, 0x46a1, { 0xac, 0xfb, 0x29, 0x5a, 0x7a, 0xd2, 0xeb, 0xcc } };// {22724C4B-57E5-46A1-ACFB-295A7AD2EBCC}
	class IEvent_Export_Filter_Inspection : public virtual refcnt::IReferenced {
	public:
		// registers a new callback object with a given source device GUID; returns S_OK if the callback was successfully registered, S_FALSE if this device id with a given callback is already registered, E_FAIL otherwise
		virtual HRESULT IfaceCalling Register_Callback(const GUID* registered_device_id, TEvent_Export_Callback callback) = 0;
		// unregisters callback of a given device id; returns S_OK if the callback was successfully registered, S_FALSE if no callback with such device id is registered, E_FAIL otherwise
		virtual HRESULT IfaceCalling Unregister_Callback(const GUID* registered_device_id) = 0;
	};

	struct TPlot_Descriptor {
		GUID id;		//one of the dc constants
		const wchar_t* name;
	};

	// drawing options - passed as an input parameter to Draw method of IDrawing_Filter_Inspection_v2
	struct TDraw_Options {

		/* an array of segment IDs to draw; nullptr = all segments */
		uint64_t* segments = nullptr;

		/* a size of segments array; if segments == nullptr, this has no effect */
		size_t segment_count = 0;

		/* an array of signal IDs to draw; nullptr = all signals */
		GUID* in_signals = nullptr;

		/* an array of reference signal IDs; reference signal is optional and may be null - needed for e.g.; for error grids, then its size must match with signal size
		 *                     when using reference signal to draw e.g.; an error grid, the filter is assumed take discrete levels
		 *                     of the reference signal, while plotting them against continous levels of the signal
		 */
		GUID* reference_signals = nullptr;

		/* size of signals and reference_signals array; if in_signals == nullptr, this has no effect */
		size_t signal_count = 0;

		/* width of the resulting drawing; 0 = use default value for given drawing type (defined by implementation) */
		int width = 0;

		/* height of the resulting drawing; 0 = use default value for given drawing type (defined by implementation) */
		int height = 0;
	};

	//knonw drawing capability
	constexpr GUID dcGraph =		{ 0xb7ca6ed4, 0xfb05, 0x4b16, { 0x91, 0x4c, 0x3f, 0xdd, 0xed, 0x23, 0x22, 0xa0 } }; // {B7CA6ED4-FB05-4B16-914C-3FDDED2322A0}
	constexpr GUID dcDaily_Graph =  { 0x1564bc55, 0xcb1b, 0x4f4a, { 0x82, 0x4b, 0xef, 0x41, 0x52, 0x34, 0xc2, 0x10 } } ;// {1564BC55-CB1B-4F4A-824B-EF415234C210}
	constexpr GUID dcParkesEG_T1D =	{ 0x74258c2f, 0x3f33, 0x4497, { 0xae, 0x97, 0x88, 0x79, 0xb3, 0xc1, 0x90, 0xbc } }; // {74258C2F-3F33-4497-AE97-8879B3C190BC}
	constexpr GUID dcParkesEG_T2D = { 0xdf6a8075, 0xba09, 0x44b5, { 0x9c, 0x98, 0x1c, 0xf9, 0x75, 0x6c, 0x89, 0xc3 } };	// {DF6A8075-BA09-44B5-9C98-1CF9756C89C3}
	constexpr GUID dcClarkEG_T1D =	{ 0x6ec36bf9, 0x5516, 0x4d27, { 0xab, 0x4a, 0x8b, 0x24, 0xc4, 0xc0, 0x2b, 0x56 } };	// {6EC36BF9-5516-4D27-AB4A-8B24C4C02B56}
	constexpr GUID dcAGP =			{ 0x979503a3, 0xef64, 0x437c, { 0x98, 0xa4, 0x9e, 0xd1, 0xf2, 0x98, 0x20, 0x57 } };	// {979503A3-EF64-437C-98A4-9ED1F2982057}
	constexpr GUID dcECDF =			{ 0x46dd1fa8, 0xdfe4, 0x44be, { 0x9a, 0x9, 0xa3, 0xf3, 0x31, 0x49, 0xec, 0xe6 } };	// {46DD1FA8-DFE4-44BE-9A09-A3F33149ECE6}
	constexpr GUID dcProfile_Glucose = { 0x77be67e9, 0xfb9f, 0x4b1b, { 0xbf, 0x91, 0x2b, 0x94, 0xc3, 0x20, 0xfc, 0xd } }; // {77BE67E9-FB9F-4B1B-BF91-2B94C320FC0D}
	constexpr GUID dcProfile_Insulin = { 0x2f58f928, 0xfe42, 0x4dd1, { 0xa3, 0x75, 0x2e, 0x4d, 0x84, 0xea, 0x10, 0xa8 } }; // {2F58F928-FE42-4DD1-A375-2E4D84EA10A8}
	constexpr GUID dcProfile_Carbs = { 0xb72f566f, 0x9953, 0x4d0a, { 0xaf, 0xd8, 0x10, 0xd5, 0x1e, 0xef, 0x9, 0xe6 } };	// {B72F566F-9953-4D0A-AFD8-10D51EEF09E6}
	constexpr GUID dcCVGA =			{ 0xd374f883, 0xefec, 0x4d09, { 0x82, 0x7c, 0xe4, 0x7c, 0xdb, 0x41, 0xcd, 0xec } };	// {D374F883-EFEC-4D09-827C-E47CDB41CDEC}

	constexpr GUID IID_Drawing_Filter_Inspection_v2 = { 0x80c23438, 0x8eb8, 0x4e45, { 0xac, 0x35, 0x6f, 0x4e, 0xa8, 0xdc, 0xfc, 0xad } }; //{80C23438-8EB8-4E45-AC35-6F4EA8DCFCAD}
	class IDrawing_Filter_Inspection_v2 : public virtual ILogical_Clock {
	public:
		/**
		 * Retrieves an array of supported plots
		 * descs - a vector container of plot descriptors
		 */
		virtual HRESULT IfaceCalling Get_Capabilities(refcnt::IVector_Container<TPlot_Descriptor>* descs) const = 0;

		/**
		 * Retrieves an array of supported segments
		 * segments - container to be filled with segment IDs; the target must exist and point to a valid (preferably empty) container
		 */
		virtual HRESULT IfaceCalling Get_Available_Segments(refcnt::IVector_Container<uint64_t> *segments) const = 0;

		/**
		 * Obtains a vector of available signals for given segment
		 * segment_id - an ID of a segment of interest
		 * out_signals - container to be filled with signal GUIDs; the target must exist and point to a valid (preferably empty) container
		 */
		virtual HRESULT IfaceCalling Get_Available_Signals(uint64_t segment_id, refcnt::IVector_Container<GUID> *out_signals) = 0;

		/**
		 * Retrieves generated SVG for a given type of the plot
		 * plot_id - ID of a plot to be drawn; this must be one of IDs advertised in Get_Capabilities
		 * svg - a container to render result into; the target must exist and point to a valid empty container
		 * options - a structure of options used for rendering the result
		 */
		virtual HRESULT IfaceCalling Draw(const GUID *plot_id, refcnt::str_container *svg, const TDraw_Options* options) = 0;
	};

	class IPlot_Drawer : public virtual refcnt::IReferenced {
		virtual HRESULT IfaceCalling Draw(refcnt::str_container *svg,
										const ITime_Segment **segment, const size_t segment_count,
										const GUID *signal, const GUID *reference_signal, const size_t signal_count) = 0;
	};


	constexpr GUID IID_Log_Filter_Inspection = { 0xa6054c8d, 0x5c01, 0x9e1d,{ 0x14, 0x39, 0x50, 0xda, 0xd1, 0x08, 0xc9, 0x48 } };
	class ILog_Filter_Inspection : public virtual refcnt::IReferenced {
	public:
		/* retrives newly available log records - caller TAKES ownership of the records
		   returns S_OK if there was at least one log record, S_FALSE if none, E_FAIL otherwise
		*/
		virtual HRESULT IfaceCalling Pop(refcnt::wstr_list **str) = 0;
	};
}
