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

#include "../iface/DeviceIface.h"
#include "../iface/FilterIface.h"
#if !defined(EMBEDDED)
#include "Dynamic_Library.h"
#endif

namespace scgms {

    namespace factory {
        namespace internal {

            constexpr bool import_test_fails = false;

            void* resolve_scgms_symbol(const char* symbol_name) noexcept;
            void* resolve_not_impl_symbol(const char* symbol_name) noexcept;
        }

        template <typename T>
        T resolve_symbol(const char* symbol_name) noexcept {
            if (internal::import_test_fails)
                return reinterpret_cast<T>(internal::resolve_not_impl_symbol(symbol_name));

            void* resolution = internal::resolve_scgms_symbol(symbol_name);
            if (!resolution) resolution = internal::resolve_not_impl_symbol(symbol_name);	//still returning not_impl if cannot load the symbol

            return reinterpret_cast<T>(resolution);
        }
    }

	#if !defined(EMBEDDED) 
    bool is_scgms_loaded();
    bool force_scgms_unload();
    #endif
}
