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

#include "scgmsLib.h"
#ifdef EMBEDDED
#include "generated/combined_descriptors.h"
#elif
#include "FilesystemLib.h"
#endif

namespace scgms {

	namespace factory {

		namespace internal {

		#ifdef _WIN32
			const wchar_t* scgms_dynamic_lib_name = L"scgms.dll";
		#elif __APPLE__
			const wchar_t* scgms_dynamic_lib_name = L"libscgms.dylib";
		#else
			const wchar_t* scgms_dynamic_lib_name = L"libscgms.so";
		#endif

		#ifdef EMBEDDED
			void* resolve_scgms_symbol(const char* symbol_name) noexcept {
				return resolve_generated_symbol(symbol_name);
			}
		#elif
			CDynamic_Library gScgms_Library;

			void* resolve_scgms_symbol(const char* symbol_name) noexcept {

				if (!gScgms_Library.Is_Loaded()) {
					const std::wstring lib_path{ scgms_dynamic_lib_name };
					if (!gScgms_Library.Load(lib_path)) {
						return nullptr;
					}
				}

				return gScgms_Library.Resolve(symbol_name);
			}

		#endif

			const char* rsGet_Filter_Descriptors = "get_filter_descriptors";
			const char* rsGet_Metric_Descriptors = "get_metric_descriptors";
			const char* rsGet_Model_Descriptors = "get_model_descriptors";
			const char* rsGet_Solver_Descriptors = "get_solver_descriptors";
			const char* rsGet_Approx_Descriptors = "get_approx_descriptors";
			const char* rsGet_Signal_Descriptors = "get_signal_descriptors";

			const char* rsCreate_Filter = "create_filter";
			const char* rsCreate_Metric = "create_metric";
			const char* rsCreate_Signal = "create_signal";
			const char* rsCreate_Device_Event = "create_device_event";
			const char* rsCreate_Persistent_Filter_Chain_Configuration = "create_persistent_filter_chain_configuration";
			const char* rsCreate_Filter_Parameter = "create_filter_parameter";
			const char* rsCreate_Filter_Configuration_Link = "create_filter_configuration_link";
			const char* rsCreate_Discrete_Model = "create_discrete_model";
			const char* rsCreate_Approximator = "create_approximator";

			const char* rsSolve_Generic = "solve_generic";

			const char* rsExecute_Filter_Configuration = "execute_filter_configuration";
			const char* rsOptimize_Parameters = "optimize_parameters";
			const char* rsOptimize_Multiple_Parameters = "optimize_multiple_parameters";

			// stub for: get_*_descriptors exported functions
			HRESULT IfaceCalling get_desc_not_impl(void *begin, void *end) { return E_NOTIMPL; }
			// specialized stubs
			HRESULT IfaceCalling create_filter_not_impl(void* id, void* input, void* output, void* filter) { return E_NOTIMPL; }
			HRESULT IfaceCalling create_metric_not_impl(void *parameters, void *metric) { return E_NOTIMPL; };
			HRESULT IfaceCalling create_signal_not_impl(void *signal_id, void *segment, void *signal) { return E_NOTIMPL; }
			HRESULT IfaceCalling create_device_event_not_impl(scgms::NDevice_Event_Code code, void *event) { return E_NOTIMPL; }
			HRESULT IfaceCalling create_persistent_filter_chain_configuration_not_impl(void *config) { return E_NOTIMPL; };
			HRESULT IfaceCalling create_filter_parameter_not_impl(scgms::NParameter_Type type, void *config_name, void *parameter) { return E_NOTIMPL; };
			HRESULT IfaceCalling create_filter_configuration_link_not_impl(void *id, void *link) { return E_NOTIMPL; };
			HRESULT IfaceCalling create_discrete_model_not_impl(void *model_id, void *parameters, void *output, void *model) { return E_NOTIMPL; };
			HRESULT IfaceCalling create_approximator_not_impl(void* approx_id, void *signal, void* configuration, void* approx) { return E_NOTIMPL; }

			HRESULT IfaceCalling solve_generic_not_impl(void *solver_id, void *setup, void *progress) { return E_NOTIMPL; }


			HRESULT IfaceCalling execute_filter_configuration_not_impl(void *configuration, void* on_filter_created, void* data, void *custom_output, void *executor, void *error_description) { return E_NOTIMPL; }
			HRESULT IfaceCalling optimize_parameters_not_impl(void *cfg, size_t idx, void *parameters_configuration_name, void* on_filter_created, void* data, void *solver_id, size_t population_size, size_t max_generations, void *progress, void *error_description) { return E_NOTIMPL; }
			HRESULT IfaceCalling optimize_multiple_parameters_not_impl(void *cfg, size_t *idx, void *parameters_configuration_name, size_t count, void* on_filter_created, void* data, void *solver_id, size_t population_size, size_t max_generations, void *progress, void *error_description) { return E_NOTIMPL; }

			template<typename... Args>
			HRESULT factory_lazy_load(const char* symbol_name, Args... args)
			{
				void* resolved = resolve_scgms_symbol(symbol_name);
				if (!resolved)
					return E_NOTIMPL;

				return reinterpret_cast<HRESULT(*)(Args...)>(resolved)(args...);
			}

			// lazy loading routines
			HRESULT IfaceCalling get_filter_desc_lazy(void *begin, void *end) { return factory_lazy_load(rsGet_Filter_Descriptors, begin, end); }
			HRESULT IfaceCalling get_metric_desc_lazy(void *begin, void *end) { return factory_lazy_load(rsGet_Metric_Descriptors, begin, end); }
			HRESULT IfaceCalling get_model_desc_lazy(void *begin, void *end) { return factory_lazy_load(rsGet_Model_Descriptors, begin, end); }
			HRESULT IfaceCalling get_solver_desc_lazy(void *begin, void *end) { return factory_lazy_load(rsGet_Solver_Descriptors, begin, end); }
			HRESULT IfaceCalling get_approx_desc_lazy(void *begin, void *end) { return factory_lazy_load(rsGet_Approx_Descriptors, begin, end); }
			HRESULT IfaceCalling get_signal_desc_lazy(void *begin, void *end) { return factory_lazy_load(rsGet_Signal_Descriptors, begin, end); }

			HRESULT IfaceCalling create_filter_lazy(void* id, void* input, void* output, void* filter) { return factory_lazy_load(rsCreate_Filter, id, input, output, filter); }
			HRESULT IfaceCalling create_metric_lazy(void *parameters, void *metric) { return factory_lazy_load(rsCreate_Metric, parameters, metric); };
			HRESULT IfaceCalling create_signal_lazy(void *signal_id, void *segment, void *signal) { return factory_lazy_load(rsCreate_Signal, signal_id, segment, signal); }
			HRESULT IfaceCalling create_device_event_lazy(scgms::NDevice_Event_Code code, void *event) { return factory_lazy_load(rsCreate_Device_Event, code, event); }
			HRESULT IfaceCalling create_persistent_filter_chain_configuration_lazy(void *config) { return factory_lazy_load(rsCreate_Persistent_Filter_Chain_Configuration, config); };
			HRESULT IfaceCalling create_filter_parameter_lazy(scgms::NParameter_Type type, void *config_name, void *parameter) { return factory_lazy_load(rsCreate_Filter_Parameter, type, config_name, parameter); };
			HRESULT IfaceCalling create_filter_configuration_link_lazy(void *id, void *link) { return factory_lazy_load(rsCreate_Filter_Configuration_Link, id, link); };
			HRESULT IfaceCalling create_discrete_model_lazy(void *model_id, void *parameters, void *output, void *model) { return factory_lazy_load(rsCreate_Discrete_Model, model_id, parameters, output, model); };
			HRESULT IfaceCalling create_approximator_lazy(void* approx_id, void *signal, void* configuration, void* approx) { return factory_lazy_load(rsCreate_Approximator, approx_id, signal, configuration, approx); }

			HRESULT IfaceCalling solve_generic_lazy(void *solver_id, void *setup, void *progress) { return factory_lazy_load(rsSolve_Generic, solver_id, setup, progress); }


			HRESULT IfaceCalling execute_filter_configuration_lazy(void *configuration, void* on_filter_created, void* data, void *custom_output, void *executor, void *error_description) { return factory_lazy_load(rsExecute_Filter_Configuration, configuration, on_filter_created, data, custom_output, executor, error_description); }
			HRESULT IfaceCalling optimize_parameters_lazy(void *cfg, size_t idx, void *parameters_cfg_name, void* on_filter_created, void* data, void *solver_id, size_t population_size, size_t max_generations, void *progress, void *error_description) { return factory_lazy_load(rsOptimize_Parameters, cfg, idx, parameters_cfg_name, on_filter_created, data, solver_id, population_size, max_generations, progress, error_description); }
			HRESULT IfaceCalling optimize_multiple_parameters_lazy(void *cfg, size_t *idx, void *parameters_cfg_name, size_t count, void* on_filter_created, void* data, void *solver_id, size_t population_size, size_t max_generations, void *progress, void *error_description) { return factory_lazy_load(rsOptimize_Multiple_Parameters, cfg, idx, parameters_cfg_name, count, on_filter_created, data, solver_id, population_size, max_generations, progress, error_description); }

			void* resolve_not_impl_symbol(const char* symbol_name) noexcept {
	#if defined(__ARM_ARCH_7A__) || defined(__aarch64__)
				if (strcmp(symbol_name, rsGet_Filter_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_filter_desc_lazy);
				if (strcmp(symbol_name, rsGet_Model_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_model_desc_lazy);
				if (strcmp(symbol_name, rsGet_Metric_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_metric_desc_lazy);
				if (strcmp(symbol_name, rsGet_Solver_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_solver_desc_lazy);
				if (strcmp(symbol_name, rsGet_Approx_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_approx_desc_lazy);
				if (strcmp(symbol_name, rsGet_Signal_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_signal_desc_lazy);

				if (strcmp(symbol_name, rsCreate_Filter) == 0) return reinterpret_cast<void(*)>(internal::create_filter_lazy);
				if (strcmp(symbol_name, rsCreate_Metric) == 0) return reinterpret_cast<void(*)>(internal::create_metric_lazy);
				if (strcmp(symbol_name, rsCreate_Signal) == 0) return reinterpret_cast<void(*)>(internal::create_signal_lazy);
				if (strcmp(symbol_name, rsCreate_Device_Event) == 0) return reinterpret_cast<void(*)>(internal::create_device_event_lazy);
				if (strcmp(symbol_name, rsCreate_Persistent_Filter_Chain_Configuration) == 0) return reinterpret_cast<void(*)>(internal::create_persistent_filter_chain_configuration_lazy);
				if (strcmp(symbol_name, rsCreate_Filter_Parameter) == 0) return reinterpret_cast<void(*)>(internal::create_filter_parameter_lazy);
				if (strcmp(symbol_name, rsCreate_Filter_Configuration_Link) == 0) return reinterpret_cast<void(*)>(internal::create_filter_configuration_link_lazy);
				if (strcmp(symbol_name, rsCreate_Discrete_Model) == 0) return reinterpret_cast<void(*)>(internal::create_discrete_model_lazy);
				if (strcmp(symbol_name, rsCreate_Approximator) == 0) return reinterpret_cast<void(*)>(internal::create_approximator_lazy);

				if (strcmp(symbol_name, rsSolve_Generic) == 0) return reinterpret_cast<void(*)>(internal::solve_generic_lazy);
				if (strcmp(symbol_name, rsExecute_Filter_Configuration) == 0) return reinterpret_cast<void(*)>(internal::execute_filter_configuration_lazy);
				if (strcmp(symbol_name, rsOptimize_Parameters) == 0) return reinterpret_cast<void(*)>(internal::optimize_parameters_lazy);
				if (strcmp(symbol_name, rsOptimize_Multiple_Parameters) == 0) return reinterpret_cast<void(*)>(internal::optimize_multiple_parameters_lazy);

	#else
				if (strcmp(symbol_name, rsGet_Filter_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_desc_not_impl);
				if (strcmp(symbol_name, rsGet_Model_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_desc_not_impl);
				if (strcmp(symbol_name, rsGet_Metric_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_desc_not_impl);
				if (strcmp(symbol_name, rsGet_Solver_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_desc_not_impl);
				if (strcmp(symbol_name, rsGet_Approx_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_desc_not_impl);
				if (strcmp(symbol_name, rsGet_Signal_Descriptors) == 0) return reinterpret_cast<void(*)>(internal::get_desc_not_impl);

				if (strcmp(symbol_name, rsCreate_Filter) == 0) return reinterpret_cast<void(*)>(internal::create_filter_not_impl);
				if (strcmp(symbol_name, rsCreate_Metric) == 0) return reinterpret_cast<void(*)>(internal::create_metric_not_impl);
				if (strcmp(symbol_name, rsCreate_Signal) == 0) return reinterpret_cast<void(*)>(internal::create_signal_not_impl);
				if (strcmp(symbol_name, rsCreate_Device_Event) == 0) return reinterpret_cast<void(*)>(internal::create_device_event_not_impl);
				if (strcmp(symbol_name, rsCreate_Persistent_Filter_Chain_Configuration) == 0) return reinterpret_cast<void(*)>(internal::create_persistent_filter_chain_configuration_not_impl);
				if (strcmp(symbol_name, rsCreate_Filter_Parameter) == 0) return reinterpret_cast<void(*)>(internal::create_filter_parameter_not_impl);
				if (strcmp(symbol_name, rsCreate_Filter_Configuration_Link) == 0) return reinterpret_cast<void(*)>(internal::create_filter_configuration_link_not_impl);
				if (strcmp(symbol_name, rsCreate_Discrete_Model) == 0) return reinterpret_cast<void(*)>(internal::create_discrete_model_not_impl);
				if (strcmp(symbol_name, rsCreate_Approximator) == 0) return reinterpret_cast<void(*)>(internal::create_approximator_not_impl);

				if (strcmp(symbol_name, rsSolve_Generic) == 0) return reinterpret_cast<void(*)>(internal::solve_generic_not_impl);
				if (strcmp(symbol_name, rsExecute_Filter_Configuration) == 0) return reinterpret_cast<void(*)>(internal::execute_filter_configuration_not_impl);
				if (strcmp(symbol_name, rsOptimize_Parameters) == 0) return reinterpret_cast<void(*)>(internal::optimize_parameters_not_impl);
				if (strcmp(symbol_name, rsOptimize_Multiple_Parameters) == 0) return reinterpret_cast<void(*)>(internal::optimize_multiple_parameters_not_impl);
	#endif

				return reinterpret_cast<void(*)>(internal::get_desc_not_impl);
			}

		}

	}

	#if !defined(EMBEDDED) 
	bool is_scgms_loaded() {
		return factory::internal::resolve_scgms_symbol(factory::internal::rsCreate_Filter) != nullptr;
	}

	bool force_scgms_unload() {
		if (!factory::internal::gScgms_Library.Is_Loaded()) {
			return false;
		}

		factory::internal::gScgms_Library.Unload();
		return true;
	}
	#endif
}
