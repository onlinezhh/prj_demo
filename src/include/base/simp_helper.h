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
#else
	#define SIMP_C_STR_TO_TSTRING(str) std::string(str)
#endif

}

#endif // COMMON_BASE_SIMP_HELPER_H
