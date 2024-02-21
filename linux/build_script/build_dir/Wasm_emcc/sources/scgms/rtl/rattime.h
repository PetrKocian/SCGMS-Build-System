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

#include <string>
#include <cstdint>
#include <ctime>

/*
	i.e. a diff in msecs between January 0, 1900 and 1970-01-01T00:00:00.000
	In Delphi/FPC: EncodeDate(1970, 1, 1)*MSecsPerDay aka UnixDateDelta*MSecsPerday
*/
constexpr int64_t diffFrom1970To1900 = 2209161600000;
// seconds per day
constexpr double MSecsPerDay = 24.0*60.0*60.0*1000.0;
// reciproc value of seconds per day for faster calculations
constexpr double InvMSecsPerDay = 1.0 / MSecsPerDay;

// gets current time offset from UTC
int Get_UTC_Offset();

// converts given unix timestamp to rat time
double Unix_Time_To_Rat_Time(const time_t qdt);
// converts given rat time to unix timestamp
time_t Rat_Time_To_Unix_Time(const double rt);

// fmt is the string formatting used by C++ standard library
// second_fraction_threshold says a precision of a second fraction, which should be outputed => 0.0 precision to 1 second
std::string Rat_Time_To_Local_Time_Str(const double rt, const char *fmt, const double second_fraction_threshold = 0.0);
std::wstring Rat_Time_To_Local_Time_WStr(const double rt, const wchar_t *fmt, const double second_fraction_threshold = 0.0);

// converts string representation of local time (str) to rat time; fmt is the string formatting used by C++ standard library
double Local_Time_WStr_To_Rat_Time(const std::wstring& str, const wchar_t* fmt) noexcept;
double Local_Time_Str_To_Rat_Time(const std::string& str, const char* fmt) noexcept;

std::wstring Rat_Time_To_Default_WStr(double rattime);

double Default_Str_To_Rat_Time(const wchar_t* input, bool& converted_ok);
double Default_Str_To_Rat_Time(const std::wstring &input, bool& converted_ok);
double Default_Str_To_Rat_Time(const char* input, bool& converted_ok);