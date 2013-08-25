/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_BASE_SIMP_HELPER_H
#define COMMON_BASE_SIMP_HELPER_H

#include "simp_types.h"


namespace SIMP_BASE
{

std::wstring towstring(const char* src);


#if defined (_UNICODE) || defined(UNICODE)
	#define SIMP_C_STR_TO_TSTRING(str) towstring(str)
	#define SIMP_TEXT(str) L##str
	#define SIMP_TIMESTAMP_TO_TSTRING(timestamp) boost::posix_time::to_simple_wstring(timestamp)
#else
	#define SIMP_C_STR_TO_TSTRING(str) std::string(str)
	#define SIMP_TEXT(str) str
	#define SIMP_TIMESTAMP_TO_TSTRING(timestamp) boost::posix_time::to_simple_string(timestamp)
#endif

}

#endif // COMMON_BASE_SIMP_HELPER_H
