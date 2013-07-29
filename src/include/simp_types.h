/*
 * Copyright (C) 2013 zhh
 */

#ifndef SIMP_TYPES_H
#define SIMP_TYPES_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <boost/shared_ptr.hpp>


namespace SIMP_BASE
{

#if defined (_UNICODE) || defined(UNICODE)
	typedef std::wchar_t tchar;
	typedef std::wstring SIMP_String;
	typedef std::wistringstream SIMP_IStringStream;
	typedef std::wostringstream SIMP_OStringStream;
	typedef std::wstringstream SIMP_StringStream;
	typedef std::wistream SIMP_IStream;
	typedef std::wostream SIMP_OStream;
	typedef std::wiostream SIMP_IOStream;
	typedef std::wifstream SIMP_IFileStream;
	typedef std::wofstream SIMP_OFileStream;
	typedef std::wfstream SIMP_FileStream;
	#define tcout std::wcout;
	#define tcin std::wcin;
#else
	typedef std::char tchar;
	typedef std::string SIMP_String;
	typedef std::istringstream SIMP_IStringStream;
	typedef std::ostringstream SIMP_OStringStream;
	typedef std::stringstream SIMP_StringStream;
	typedef std::istream SIMP_IStream;
	typedef std::ostream SIMP_OStream;
	typedef std::iostream SIMP_IOStream;
	typedef std::ifstream SIMP_IFileStream;
	typedef std::ofstream SIMP_OFileStream;
	typedef std::fstream SIMP_FileStream;
	#define tcout std::cout;
	#define tcin std::cin;
#endif

	typedef std::vector SIMP_Vector;
	typedef std::list SIMP_List;
	typedef std::map SIMP_Map;

	#define SIMP_SharedPtr boost::shared_ptr;
}

#endif
