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

#include "winapi_mapping.h"
#include "string_utils.h"
#include "winapi_mapping.h"

#include <sstream>
#include <algorithm>
#include <cwctype>
#include <cstring>
#include <array>
#include <iostream>
#include <iomanip>
#include <map>
#include <cwctype>
#include <type_traits>
#include <cmath>
#include <cctype>

#undef min
#undef max

std::string Narrow_WString(const std::wstring& wstr) {
	return Narrow_WChar(wstr.c_str());
}

std::string Narrow_WChar(const wchar_t *wstr) {
    if (!wstr) return "";

	std::ostringstream stm;
	const std::ctype<wchar_t>& ctfacet = std::use_facet< std::ctype<wchar_t> >(stm.getloc());

	const size_t len = wcslen(wstr);
	for (size_t i = 0; i < len; ++i) 		
		stm << ctfacet.narrow(wstr[i], 0);
	
	return stm.str();
}

std::wstring Widen_Char(const char *str) {
    if (!str) return L"";

	std::wostringstream wstm;
	const std::ctype<wchar_t>& ctfacet = std::use_facet<std::ctype<wchar_t> >(wstm.getloc());
	const size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i)
		wstm << ctfacet.widen(str[i]);
	return wstm.str();
}


std::wstring Widen_String(const std::string& str) {
    return Widen_Char(str.c_str());
}


std::wstring Lower_String(const std::wstring& wstr) {
    std::wstring result;
    std::transform(wstr.begin(), wstr.end(), std::back_inserter(result), std::towlower);
    return result;
}

std::string Lower_String(const std::string& wstr) {
    std::string result;
    std::transform(wstr.begin(), wstr.end(), std::back_inserter(result), tolower);
    return result;
}



template <typename C>
using str_2_dbl_string = std::basic_string<C, std::char_traits<C>, std::allocator<C>>;

template <typename C>
struct TNumeric_Chars {
    static constexpr C dot = char_type_selector<C>('.', L'.');
    static constexpr C coma = char_type_selector<C>(',', L',');
    static constexpr C minus_sign = char_type_selector<C>('-', L'-');

    static constexpr C small_x = char_type_selector<C>('x', L'x');
    static constexpr C capital_x = char_type_selector<C>('X', L'X');

    static const std::array<const C, 16> small_hexa_digits;
    static const std::array<const C, 16> capital_hexa_digits;

    static const std::map<const std::basic_string<C>, double> known_symbols;
    static const std::map<const int, std::basic_string<C>> known_symbols_reverse;
};

template <>
const std::array<const char, 16> TNumeric_Chars<char>::capital_hexa_digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
template <>
const std::array<const char, 16> TNumeric_Chars<char>::small_hexa_digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

template <>
const std::array<const wchar_t, 16> TNumeric_Chars<wchar_t>::capital_hexa_digits = { L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F' };
template <>
const std::array<const wchar_t, 16> TNumeric_Chars<wchar_t>::small_hexa_digits = { L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a', L'b', L'c', L'd', L'e', L'f' };

template <>
const std::map<const std::basic_string<char>, double> TNumeric_Chars<char>::known_symbols = {
           {"oo", std::numeric_limits<double>::infinity()},
           {"inf", std::numeric_limits<double>::infinity()},
           {"infinity", std::numeric_limits<double>::infinity()},

           {"-oo", -std::numeric_limits<double>::infinity()},
           {"-inf", -std::numeric_limits<double>::infinity()},
           {"-infinity", -std::numeric_limits<double>::infinity()},

           {"nan", std::numeric_limits<double>::quiet_NaN()},

           {"min", std::numeric_limits<double>::min()},
           {"-min", -std::numeric_limits<double>::min()},
           {"max", std::numeric_limits<double>::max()},
           {"-max", -std::numeric_limits<double>::max()}
};

template <>
const std::map<const std::basic_string<wchar_t>, double> TNumeric_Chars<wchar_t>::known_symbols = {
           {L"\x221e", std::numeric_limits<double>::infinity()},
           {L"oo", std::numeric_limits<double>::infinity()},
           {L"inf", std::numeric_limits<double>::infinity()},
           {L"infinity", std::numeric_limits<double>::infinity()},

           {L"-\x221e", -std::numeric_limits<double>::infinity()},
           {L"-oo", -std::numeric_limits<double>::infinity()},
           {L"-inf", -std::numeric_limits<double>::infinity()},
           {L"-infinity", -std::numeric_limits<double>::infinity()},

           {L"nan", std::numeric_limits<double>::quiet_NaN()},

           {L"min", std::numeric_limits<double>::min()},
           {L"-min", -std::numeric_limits<double>::min()},
           {L"max", std::numeric_limits<double>::max()},
           {L"-max", -std::numeric_limits<double>::max()}
};

template <>
const std::map<const int, std::basic_string<char>> TNumeric_Chars<char>::known_symbols_reverse = {
           {FP_INFINITE, "inf"},
           {FP_NAN, "nan"},
           {FP_SUBNORMAL, "subnormal"},
           {FP_ZERO, "0"}
};

template <>
const std::map<const int, std::basic_string<wchar_t>> TNumeric_Chars<wchar_t>::known_symbols_reverse = {
           {FP_INFINITE, L"\x221e"},
           {FP_NAN, L"nan"},
           {FP_SUBNORMAL, L"subnormal"},
           {FP_ZERO, L"0"}
};

template <typename C>
bool Is_Hexa_Double(const C* str) {
    bool result = false;  
    if (str != nullptr) {        
        if (*str == TNumeric_Chars<C>::small_hexa_digits[0]) {
            if ((*(str + 1) == TNumeric_Chars<C>::small_x) || (*(str + 1) == TNumeric_Chars<C>::capital_x))
                result = true;
        }
    }

    return result;
}

bool Has_Hexa_Prefix(const char* str) { return Is_Hexa_Double(str); }
bool Has_Hexa_Prefix(const std::string& str) { return Is_Hexa_Double(str.c_str()); }
bool Has_Hexa_Prefix(const wchar_t* wstr) { return Is_Hexa_Double(wstr); }
bool Has_Hexa_Prefix(const std::wstring& wstr) { return Is_Hexa_Double(wstr.c_str()); }

bool rtl0_isspace(const char str) { return std::isspace(static_cast<unsigned char>(str)) != 0; }
bool rtl0_isspace(const wchar_t str) { return std::iswspace(static_cast<wint_t>(str)) != 0; }

double rtl0_str_dbl(const char* str, char** end_ptr) { return strtod(str, end_ptr); }
double rtl0_str_dbl(const wchar_t* str, wchar_t** end_ptr) { return wcstod(str, end_ptr); }

uint64_t rtl0_str_uint64(const char* str, char** end_ptr, int base) { return strtoul(str, end_ptr, base); }
uint64_t rtl0_str_uint64(const wchar_t* str, wchar_t** end_ptr, int base) { return wcstoul(str, end_ptr, base); }


template <typename C>
double rtl_str_dbl(const C* str, C** end_ptr) {
    const bool is_hexa = Is_Hexa_Double(str);
    double result = std::numeric_limits<double>::quiet_NaN();
    if (is_hexa) {        
        //after the preliminary check, we expect 16 hexa, uninterrupted digits there

        const C *start_digit = str + 2;
        const C* expected_end_digit = start_digit + 16;

        bool ok = true;
        C* test_digit = const_cast<C*>(start_digit);
        while (test_digit < expected_end_digit) {
            if ((*test_digit == 0) || rtl0_isspace(*test_digit)) {                
                ok = false;
                break;
            }

            test_digit++;
        }

        if (ok) {

            auto convert_single_digit = [&ok](const C digit)->size_t {
                if ((digit >= TNumeric_Chars<C>::capital_hexa_digits[0]) && (digit <= TNumeric_Chars<C>::capital_hexa_digits[9]))
                    return static_cast<size_t>(digit) - static_cast<size_t>(TNumeric_Chars<C>::capital_hexa_digits[0]);

                if ((digit >= TNumeric_Chars<C>::capital_hexa_digits[0xA]) && (digit <= TNumeric_Chars<C>::capital_hexa_digits[0xF]))
                    return static_cast<size_t>(digit) - static_cast<size_t>(TNumeric_Chars<C>::capital_hexa_digits[0xA]) + 10;

                if ((digit >= TNumeric_Chars<C>::small_hexa_digits[0xA]) && (digit <= TNumeric_Chars<C>::small_hexa_digits[0xF]))
                    return static_cast<size_t>(digit) - static_cast<size_t>(TNumeric_Chars<C>::small_hexa_digits[0xA]) + 10;

                ok = false;
                return 0;
            };
            
            //result = 0.0; -- should be there for sanity, but we overwrite it all
            //let us load the double simply as a memory dump of 8 bytes
            uint8_t* converted = reinterpret_cast<uint8_t*>(&result);
            C* converting_digit = const_cast<C*>(start_digit);
            for (size_t i = 0; i < 8; i++) {
                const size_t num = convert_single_digit(*converting_digit) * 16 + convert_single_digit(*(converting_digit + 1));
                converted[i] = static_cast<uint8_t>(num);
                converting_digit += 2;
            }
            
            if (ok)
                *end_ptr = const_cast<C*>(expected_end_digit);
            else
                *end_ptr = const_cast<C*>(str);
            
        }
    }
    else
        result = rtl0_str_dbl(str, end_ptr);

    return result;
}
template <typename C>
double convert_str_2_double(const C* wstr, bool& ok) {         

    if ((wstr == nullptr) || (*wstr ==0)) {
        ok = false;
        return std::numeric_limits<double>::quiet_NaN();    //std lib seems to happily return zero on empty string
    }

    C* end_char = nullptr;   
    double value = rtl_str_dbl(wstr, &end_char);
    ok = (end_char != nullptr) && (*end_char == 0);

    //detecting local does not seems reliable in all cases we encountered
    auto try_convert = [&](const C old_point, const C new_point) {
        //could have made the number by properly combining mantisa and exponent
        //but then, we would have to detect e.g.; 1.0e61 formatting
        //does not seem worth the effort

        str_2_dbl_string<C> converted{ wstr };
        std::replace(converted.begin(), converted.end(), old_point, new_point);
        value = rtl_str_dbl(converted.c_str(), &end_char);
        ok = (end_char != nullptr) && (*end_char == 0);
        return value;
    };

    if (end_char != nullptr) {
        if (*end_char == TNumeric_Chars<C>::dot) value = try_convert(TNumeric_Chars<C>::dot, TNumeric_Chars<C>::coma);
        else if (*end_char == TNumeric_Chars<C>::coma) value = try_convert(TNumeric_Chars<C>::coma, TNumeric_Chars<C>::dot);
    }


    if (!ok) {
        const auto symbols = TNumeric_Chars<C>::known_symbols;
        auto iter = symbols.find(Lower_String(wstr));
        if (iter != symbols.end()) {
            value = iter->second;
            ok = true;
        }
        else {
            value = std::numeric_limits<double>::quiet_NaN(); //sanity
        }
    }

    return value;
}

double str_2_dbl(const char* str) {
    bool tmp;
    return str_2_dbl(str, tmp);
}

double str_2_dbl(const std::string& str, bool &ok) {
    return str_2_dbl(str.c_str(), ok);
}


double str_2_dbl(const std::string& str) {
    return str_2_dbl(str.c_str());
}

double str_2_dbl(const char* str, bool& ok) {
    return convert_str_2_double<char>(str, ok);
}


double str_2_dbl(const wchar_t* wstr) {
    bool tmp;
    return str_2_dbl(wstr, tmp);
}


 double str_2_dbl(const wchar_t* wstr, bool& ok) {
     return convert_str_2_double<wchar_t>(wstr, ok);	
}

 double str_2_dbl(const std::wstring& wstr, bool &ok) {
     return convert_str_2_double<wchar_t>(wstr.c_str(), ok);
 }

 std::vector<double> str_2_dbls(const wchar_t* wstr, bool& ok) {     
     std::wstring str_copy{ wstr };	//wcstok modifies the input string
     const wchar_t* delimiters = L" \n\r";	//string of chars, which designate individual delimiters
     wchar_t* buffer = nullptr;
     wchar_t* str_val = wcstok_s(const_cast<wchar_t*>(str_copy.data()), delimiters, &buffer);
     std::vector<double> result;
     
     while (str_val != nullptr) {
        
        //and store the real value
        double value = str_2_dbl(str_val, ok);
        if (!ok) {
            //let's round subnormals to zero aka flush to zero
            if (Lower_String(str_val) == L"subnormal") {
                ok = true;
                value = 0.0;
            } else 
             return decltype(result){};
        }
        result.push_back(value);
        
        str_val = wcstok_s(nullptr, delimiters, &buffer);        
     }
     
     return result;
 }

 template <typename C>
 std::basic_string<C> rtl_dbl_2_str(const double val, const bool save_hexa) {

     std::basic_string<C> result;

     if (!save_hexa) {

         auto convert_normal = [](const double val)->std::basic_string<C> {
             std::basic_stringstream<C, std::char_traits<C>, std::allocator<C>> stream;

             auto dec_sep = new CDecimal_Separator<C>{ TNumeric_Chars<C>::dot };
             auto unused = stream.imbue(std::locale{ std::wcout.getloc(), std::move(dec_sep) }); //locale takes ownership of dec_sep
             stream << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << val;
             return stream.str();
         };

         const auto symbols = TNumeric_Chars<C>::known_symbols_reverse;
         const int cls = std::fpclassify(val);

         auto iter = symbols.find(cls);


         if (iter != symbols.end()) {
             if (std::signbit(val))
                 result += TNumeric_Chars<C>::minus_sign;
             result += iter->second;
         }
         else {
             result = convert_normal(val);
         }
     } else {
         //let us store the double simply as a memory dump of 8 bytes
         const uint8_t* converted = reinterpret_cast<const uint8_t*>(&val);
         result  = TNumeric_Chars<C>::small_hexa_digits[0];
         result += TNumeric_Chars<C>::small_x;
         for (size_t i = 0; i < 8; i++) {
             result += TNumeric_Chars<C>::capital_hexa_digits[converted[i] / 16];
             result += TNumeric_Chars<C>::capital_hexa_digits[converted[i] % 16];
         }
     }

     return result;
 }

std::wstring dbl_2_wstr(const double val, const bool save_hexa) {
    return rtl_dbl_2_str<wchar_t>(val, save_hexa);
}

std::string dbl_2_str(const double val, const bool save_hexa) {
    return rtl_dbl_2_str<char>(val, save_hexa);
}


template <typename T>
int get_base(T* str) {
    int base = 10;

    constexpr T lc = static_cast<T>('x');
    constexpr T up = static_cast<T>('X');
    constexpr T zr = static_cast<T>('0');

    if (str) {
        switch (str[0]) {
            case lc:
            case up:   base = 16;  
                        break;

            case zr:   switch (str[1]) {
                            case lc:
                            case up:   base = 16;
                                        break;
                            default: break;
                        }
                   break;

            default: break;
        }
    }

    return base;
}


int64_t str_2_int(const wchar_t* wstr) {
    bool tmp;
    return str_2_int(wstr, tmp);
}

template <typename I, typename C, typename W>
I str_2_xint(const C* wstr, bool& ok, W func) {
    C* end_char;
    I value = func(wstr, &end_char, get_base(wstr));
    ok = *end_char == 0;

    if (!ok)
        value = std::numeric_limits<I>::max(); //sanity

    return value;
}


int64_t str_2_int(const char* str) {
    bool tmp;
    return str_2_int(str, tmp);
}


int64_t str_2_int(const char* str, bool& ok) {
    return str_2_xint<int64_t, char>(str, ok, std::strtol);
}


int64_t str_2_int(const wchar_t* wstr, bool& ok) {
    return str_2_xint<int64_t, wchar_t>(wstr, ok, std::wcstoll);  
}


uint64_t str_2_uint(const wchar_t* wstr, bool& ok) {
    return str_2_xint<uint64_t, wchar_t>(wstr, ok, std::wcstoull);
}

uint64_t str_2_uint(const char* str, bool& ok) {
    return str_2_xint<uint64_t, char>(str, ok, std::strtol);
}

uint64_t str_2_uint(const char* str) {
    bool tmp = false;
    return str_2_uint(str, tmp);
}

uint64_t str_2_uint(const std::string& str) {
    bool tmp = false;
    return str_2_uint(str.c_str(), tmp);
}


int64_t str_2_int(const std::string& str, bool& converted_ok) {
    return str_2_int(str.c_str(), converted_ok);
}

int64_t str_2_int(const std::wstring& str, bool& converted_ok) {
    return str_2_int(str.c_str(), converted_ok);
}


using TGUID_Overlay = uint8_t[16];
static_assert(sizeof(GUID) == sizeof(TGUID_Overlay), "Invalid packing of GUID overlay!");
const std::array<uint8_t, 16> guid_overlay_indexes = { 3, 2, 1, 0, 5, 4, 7, 6, 8, 9, 10, 11, 12, 13, 14, 15 };	//UUID would start with 0, 1, 2, 3
const std::array<size_t, 16> guid_parsing_indexes = { 0, 2, 4, 6, 9, 11, 14, 16, 19, 21, 24, 26, 28, 30, 32, 34 };


GUID WString_To_GUID(const std::wstring& str, bool& ok) {
    GUID guid = Invalid_GUID;

    const size_t bracketless_guid_len = 36;
    const size_t str_len = str.size();
    const bool bracketed_guid = str_len == bracketless_guid_len + 2;
    ok = (str_len == bracketless_guid_len) || bracketed_guid;

    if (ok) {
        //guid str seems to have the proper size
        ok = !bracketed_guid || (bracketed_guid && (str[0] == L'{') && (str[bracketless_guid_len + 1] == L'}'));
        if (ok) {
            //if brackets are used, they are OK

            //check the hyphens
            const wchar_t* gs = str.data() + (bracketed_guid ? 1 : 0);
            const size_t h1st = 8;
            const size_t h2nd = 13;
            const size_t h3rd = 18;
            const size_t h4th = 23;
            ok = (gs[h1st] == L'-') && (gs[h2nd] == L'-') && (gs[h3rd] == L'-') && (gs[h4th] == L'-');
            if (ok) {
                auto hex_2_bin = [&ok](const wchar_t ch)->uint8_t {
                    switch (ch) {
                        case '0': case '1': case '2': case '3':	case '4': case '5':	case '6': case '7': case '8': case '9': return ch - L'0';
                        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': return ch - L'a' + 10;
                        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': return ch - L'A' + 10;
                        default: ok = false; return 0xFF;
                    }
                };

                TGUID_Overlay& guid_overlay = *reinterpret_cast<TGUID_Overlay*>(&guid);
                for (size_t i = 0; i < guid_parsing_indexes.size(); i++) {
                    const size_t idx = guid_parsing_indexes[i];
                    guid_overlay[guid_overlay_indexes[i]] = hex_2_bin(gs[idx + 0]) * 16 + hex_2_bin(gs[idx + 1]);
                }

                if (!ok) guid = Invalid_GUID;	//undo any writes that might have occured

            }
        }
    }


    return guid;
}

std::wstring GUID_To_WString(const GUID& guid) {
    std::wstring result = L"{00000000-0000-0000-0000-000000000000}";
    const wchar_t* to_x = L"0123456789ABCDEF";

    TGUID_Overlay& guid_overlay = *reinterpret_cast<TGUID_Overlay*>(const_cast<GUID*>(&guid));
    
    for (size_t i = 0; i < guid_parsing_indexes.size(); i++) {             
        
        const uint8_t byte = guid_overlay[guid_overlay_indexes[i]];
        const uint8_t lo = byte & 0xf;
        const uint8_t hi = byte / 0x10;

        const size_t result_index = guid_parsing_indexes[i];
        result[result_index + 1] = to_x[hi];        //+1 because of the starting '{'
        result[result_index + 2] = to_x[lo];
    }
    
    return result;
}


std::wstring Get_Padded_Number(uint32_t num, size_t places) {
    std::wstring tmp = std::to_wstring(num);
    while (tmp.length() < places)
        tmp = L'0' + tmp;
    return tmp;
}


template<typename T>
static constexpr const T* trim_char_type_selector(const char* arg0, const wchar_t* arg1)
{
    if constexpr (std::is_same_v<T, wchar_t>)
        return arg1;
    else
        return arg0; // fallback to static cast of last parameter in pack
}

const char* trim_ansi = " \t\n\v\f\r";          //note the leading space!
const wchar_t* trim_wide = L" \t\n\v\f\r";

template <typename T>
const T* trim_chars = trim_char_type_selector<T>(trim_ansi, trim_wide);


template <typename T>
T& ltrim(T& str) {
    using X = typename std::remove_reference<T>::type;
    using Y = typename X::value_type;
    str.erase(0, str.find_first_not_of(trim_chars<Y>));
    return str;
}

template <typename T>
T& rtrim(T& str) {
    using X = typename std::remove_reference<T>::type;
    using Y = typename X::value_type;
    str.erase(str.find_last_not_of(trim_chars<Y>) + 1);
    return str;
}

template <typename T>
T trim_core(T& str) {
    return ltrim<T>(rtrim<T>(str));
}

std::wstring& trim(std::wstring& str) {
    return trim_core<std::wstring&>(str);
}

std::string& trim(std::string& str) {
    return trim_core<std::string&>(str);
}

std::string trim(const std::string &str) {
    std::string tmp{ str };
    return trim_core(tmp);
}

std::string trim(const char* str) {
    std::string tmp{ str };
    return trim_core(tmp);
}


std::string quote(const std::string& str) {
    return '"' + str + '"';
}


bool str_2_bool(const std::wstring& str, bool& ok) {
    static std::map<std::wstring, bool> known_symbols = {
        {L"true", true},
        {L"false", false},
        {L"1", true},
        {L"0", false},
        {L"yes", true},
        {L"no", false},
        {L"on", true},
        {L"off", false},
        {L"t", true},
        {L"f", false},
    };


    auto iter = known_symbols.find(Lower_String(str));
    ok = iter != known_symbols.end();
    
    return ok ? iter->second : false;
}
