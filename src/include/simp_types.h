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
#include <boost/thread.hpp>
#include <boost/date_time.hpp>


namespace SIMP_BASE
{

#if defined (_UNICODE) || defined(UNICODE)
	typedef wchar_t tchar;
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
	#define tcerr std::wcerr;
#else
	typedef char tchar;
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
	#define tcerr std::cerr;
#endif

	typedef boost::thread SIMP_Thread;
	typedef boost::mutex SIMP_Mutex;
	typedef boost::condition_variable_any SIMP_Condition;
	typedef boost::posix_time::ptime SIMP_DateTime;
}

#endif
