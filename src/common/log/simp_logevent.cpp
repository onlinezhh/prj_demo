/*
 * Copyright (C) 2013 zhh
 */

#include "simp_logevent.h"


namespace SIMP_BASE
{

SIMP_LogEvent::SIMP_LogEvent()
{
}

SIMP_LogEvent::SIMP_LogEvent(LogLevel ll,
							 const SIMP_String& msg,
							 const char* file,
							 int line)
	: m_logLevel(ll), m_msg(msg), m_file(file), m_line(line)
{
}

SIMP_LogEvent::~SIMP_LogEvent()
{
}

} 

