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

#include "rattime.h"
#include "../iface/DeviceIface.h"
#include "../utils/winapi_mapping.h"
#include "../utils/string_utils.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <ctime>

#undef max

int Get_UTC_Offset()
{
	time_t gmt, rawtime = time(nullptr);
	struct tm ptm {}; //zero initalize all possibly non-set elements like daylight saving

	gmtime_s(&ptm, &rawtime);

	ptm.tm_isdst = -1;
	gmt = mktime(&ptm);

	return static_cast<int>(difftime(rawtime, gmt));
}

double Unix_Time_To_Rat_Time(const time_t qdt)
{
	int64_t diff = static_cast<int64_t>(qdt)*1000 + diffFrom1970To1900;
	return static_cast<double>(diff) * InvMSecsPerDay;
}

time_t Rat_Time_To_Unix_Time(const double rt)
{
	const double diff = rt * MSecsPerDay;
	const double ceiled_msecs = std::ceil(diff);
	const int64_t casted_msecs = static_cast<int64_t>(ceiled_msecs);
	const int64_t msecs = casted_msecs - diffFrom1970To1900;
	const int64_t secs = msecs / static_cast<int64_t>(1000);
	const time_t result = static_cast<time_t>(secs);
	return result;
}


void convert_dbl(const double rt, std::string& str) {
	str = dbl_2_str(rt);
}
void convert_dbl(const double rt, std::wstring& str) {
	str = dbl_2_wstr(rt);
}

template <typename C, typename S = std::basic_string<C>>
S core_Rat_Time_To_Local_Time_Str(const double rt, const C *fmt, const double second_fraction_granularity) {
	if (rt == 0.0) return S{};

	time_t ltim = Rat_Time_To_Unix_Time(rt);

	struct tm ptm {}; //zero initalize all possibly non-set elements like daylight saving
	localtime_s(&ptm, &ltim);	

	std::basic_stringstream<C> os;
	os << std::put_time(&ptm, fmt);

	if (second_fraction_granularity > 0.0) {
		const double rt_by_sec = rt / scgms::One_Second;
		//const double number_of_secs = ;
		const double sec_fraction = rt_by_sec - std::trunc(rt_by_sec);

		const double granules = std::trunc(sec_fraction / second_fraction_granularity);
		const double rounded_fraction = granules * second_fraction_granularity;

		S str;
		convert_dbl(rounded_fraction, str);
		str.erase(0, 1);
		os << str;

	}


	S result = os.str();
	return result;
}

std::string Rat_Time_To_Local_Time_Str(const double rt, const char* fmt, const double second_fraction_granularity) {
	return core_Rat_Time_To_Local_Time_Str(rt, fmt, second_fraction_granularity);
}

std::wstring Rat_Time_To_Local_Time_WStr(const double rt, const wchar_t* fmt, const double second_fraction_granularity) {
	return core_Rat_Time_To_Local_Time_Str(rt, fmt, second_fraction_granularity);
}

template <typename S, typename NRS = typename std::remove_reference<S>, typename C = typename NRS::value_type >
double core_Local_Time_Str_To_Rat_Time(const S& str, const C* fmt) noexcept {

	bool could_be_raw_double = Has_Hexa_Prefix(str);	//we need to check for 0x prefix as the mask could indicate e.g.; hours only
	const double possible_raw_double = could_be_raw_double ? str_2_dbl(str, could_be_raw_double) : std::numeric_limits<double>::quiet_NaN();
	could_be_raw_double &= !std::isnan(possible_raw_double);
	if (could_be_raw_double)
		return possible_raw_double;

	//note that we support a non-standard extension, which considers any trailing .zzz as a second fraction

	const C extra_space = static_cast<C>(0x20);
	const C extra_dot = static_cast<C>('.');

	const auto fraction_separator_pos = str.find_first_of(extra_dot);
	const bool has_fraction = fraction_separator_pos != S::npos;
	auto normal_part = has_fraction ? str.substr(0, fraction_separator_pos) : str;
	auto fraction_part = has_fraction ? static_cast<C>('0') + str.substr(fraction_separator_pos, str.size() - fraction_separator_pos - 1) : S{};

	struct tm ptm {}; //zero initalize all possibly non-set elements like daylight saving
	memset(&ptm, 0, sizeof(ptm)); // mktime may use fields, that may not be filled by std::get_time; to make valgrind happy, let us initialize the whole memory
	std::basic_stringstream<C>  ss(normal_part + extra_space);
										// we append extra space to avoid 1b) and enforce 1c) for https://en.cppreference.com/w/cpp/locale/time_get/get
										//practically, if mask would e.g.; contain seconds, but the source would not, then the conversion would still succeed despite missing seconds
										//the trailing, extra space removes the eof, thus making the conversion fail for the missing seconds
	ss >> std::get_time(&ptm, fmt);



	double result = std::numeric_limits<double>::quiet_NaN();
	const bool invalid_ptm = (ptm.tm_mday < 0) || (ptm.tm_mon < 0) || (ptm.tm_year < 0) || (ptm.tm_hour < 0) || (ptm.tm_min < 0) || (ptm.tm_sec < 0);
	if (!invalid_ptm) {	//check whether get_time succeeded

		ptm.tm_isdst = -1;					//because Rat_Time_To_Local_Time_WStr is the inverse function to this one, and it ses localtime_s which makes automatic correction
		//hence, we need to let the system to decide
		time_t ltim = mktime(&ptm);


		bool fraction_ok = false;

		double fraction = 0.0;
		if (has_fraction) 	
			fraction = str_2_dbl(fraction_part.c_str(), fraction_ok);		

		
		if (ltim != -1) 
			result = Unix_Time_To_Rat_Time(ltim);	
		else {
			//mktime returns -1 on zero ptm, which is, however, possible if measure something sub-second like e.g.; heartbeat ibi
			//=>proceed with just the time of the day
			result = static_cast<double>(ptm.tm_hour) * scgms::One_Hour +
					 static_cast<double>(ptm.tm_min) * scgms::One_Minute +
					 static_cast<double>(ptm.tm_sec) * scgms::One_Second;
		}

		if (has_fraction && fraction_ok)
			result += scgms::One_Second * fraction;
	}

	return result;
}

double Local_Time_WStr_To_Rat_Time(const std::wstring& str, const wchar_t* fmt) noexcept {
	return core_Local_Time_Str_To_Rat_Time(str, fmt);
}

double Local_Time_Str_To_Rat_Time(const std::string& str, const char* fmt) noexcept {
	return core_Local_Time_Str_To_Rat_Time(str, fmt);
}

std::wstring Rat_Time_To_Default_WStr(double rattime) {
	if (std::isnan(rattime))
		return L"NaN";

	auto calc_fraction = [&](const double factor) {
		double intpart;
		rattime *= factor;
		rattime = std::modf(rattime, &intpart);
		return intpart;
	};


	auto add_fraction = [&](const double intpart, const double factor) {
		if (factor == 1.0) {	//days
			return intpart != 0.0 ? std::to_wstring(static_cast<int>(intpart)) + L' ' : L"";
		}
		else {
			std::wstring result = std::to_wstring(static_cast<int>(intpart));
			while (result.size() < 2)
				result = L'0' + result;
			return result;
		}
	};


	//handle the sign
	std::wstring result{ rattime < 0.0 ? L"-" : L"" };
	rattime = std::fabs(rattime);

	//decompose to individual parts
	double days = calc_fraction(1.0);
	double hours = calc_fraction(24.0);
	double minutes = calc_fraction(60.0);
	double seconds = calc_fraction(60.0);

	//perform round-up to seconds
	if (std::round(rattime) > 0.0) {
		seconds++;

		if (seconds >= 60.0) {
			minutes++;
			seconds = 0.0;

			if (minutes >= 60.0) {
				hours++;
				minutes = 0.0;

				if (hours >= 24.0) {
					days++;
				}
			}
		}
	}

	//and compose the string
	result += add_fraction(days, 1.0);
	result += add_fraction(hours, 24.0) + L':';
	result += add_fraction(minutes, 60.0) + L':';
	result += add_fraction(seconds, 60.0);

	return result;
}


bool is_digit(const char ch) {
	switch (ch) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9': return true;
		default: return false;
	}
}

bool is_digit(const wchar_t ch) {
	switch (ch) {
		case L'0': case L'1': case L'2': case L'3': case L'4':
		case L'5': case L'6': case L'7': case L'8': case L'9': return true;
		default: return false;
	}
}

size_t str_len(const char* str) { return strlen(str); }
size_t str_len(const wchar_t* str) { return wcslen(str); }

template <typename T>
struct TTime_Chars {
	static constexpr T minus = '-';
	static constexpr T colon = ':';
	static constexpr T dot = '-';
	static constexpr T space = ' ';
};

template <>
struct TTime_Chars<wchar_t>{
	static constexpr wchar_t minus = L'-';
	static constexpr wchar_t colon = L':';
	static constexpr wchar_t dot = L'-';
	static constexpr wchar_t space = L' ';
};

template <typename C>
double Convert_Str_To_Rat_Time(const C* input, bool& converted_ok) {
	converted_ok = false;	//assume an error (and simplify the exit code)

	double days = 0.0, hours = 0.0, minutes = 0.0, seconds = 0.0;

	double plus_minus_sign = 1.0;
	int plus_minus_pos = 0;	//must be signed int!
	
	if (!input || (*input == 0))  return std::numeric_limits<double>::quiet_NaN();	
		
	if (input[0] == TTime_Chars<C>::minus) {
		plus_minus_sign = -1.0;
		plus_minus_pos = 1;
	}


	int pos, last_pos = static_cast<int>(str_len(input));
	

	auto fetch_number = [&](const C sep, const C decimal, double& result, const double result_max) {
		pos = last_pos - 1;

		while (pos >= plus_minus_pos) {
			const C ch = input[pos];
			if (ch == sep) break;
			if (!is_digit(ch) && (ch != decimal)) return false;	

			pos--;
		}

		pos++;
		std::basic_string<C, std::char_traits<C>, std::allocator<C>> substring(&input[pos], static_cast<size_t>(last_pos) - static_cast<size_t>(pos));	//must be a string to add the terminating zero
		bool ok;
		result = str_2_dbl(substring.c_str(), ok);			

		if ((!ok) || (result >= result_max)) return false;

		last_pos = pos - 1;
		return true;
	};


	//search for seconds, minutes, hours and days

	if (!fetch_number(TTime_Chars<C>::colon, TTime_Chars<C>::dot, seconds, 60.0)) return false;

	if (last_pos > plus_minus_pos) {
		if (!fetch_number(TTime_Chars<C>::colon, 0, minutes, 60.0)) return false;

		if (last_pos > plus_minus_pos) {
			if (!fetch_number(TTime_Chars<C>::space, 0, hours, 24.0)) return false;

			if (last_pos > plus_minus_pos)
				if (!fetch_number(TTime_Chars<C>::minus, 0, days, std::numeric_limits<double>::max()))
					return std::numeric_limits<double>::quiet_NaN();				
		}
	}

	converted_ok = true;
	return plus_minus_sign * (days + scgms::One_Hour * hours + scgms::One_Minute * minutes + scgms::One_Second * seconds);

	return true;
}

double Default_Str_To_Rat_Time(const std::wstring& input, bool& converted_ok) {
	return Default_Str_To_Rat_Time(input.c_str(), converted_ok);
}

double Default_Str_To_Rat_Time(const wchar_t* input, bool& converted_ok) {
	return Convert_Str_To_Rat_Time(input, converted_ok);
}

double Default_Str_To_Rat_Time(const char* input, bool& converted_ok) {
	return Convert_Str_To_Rat_Time(input, converted_ok);
}