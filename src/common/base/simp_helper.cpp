/*
 * Copyright (C) 2013 zhh
 */

#include "simp_helper.h"
#include <assert.h>


namespace SIMP_BASE
{

std::wstring towstring(const char* src)
{
	assert(src != NULL);

	std::size_t n = std::strlen(src);

	std::wstring ret;
	ret.resize(n);

	for (std::size_t i = 0; i < n; ++i)
	{
		std::char_traits<char>::int_type src_int
			= std::char_traits<char>::to_int_type (src[i]);
		ret[i] = src_int <= 127
			? std::char_traits<wchar_t>::to_char_type (src_int)
			: L'?';
	}

	return ret;
}

} 
