/*
 * Copyright (C) 2013 zhh
 */

#include "simp_logevent.h"
#include "base/simp_helper.h"


namespace SIMP_BASE
{

SIMP_LogEvent::SIMP_LogEvent()
	: m_logLevel(LL_ALL), m_line(-1)
{
}

SIMP_LogEvent::SIMP_LogEvent(LogLevel ll,
							 const SIMP_String& msg,
							 const char* file,
							 int line,
							 const SIMP_DateTime& timestamp)
	: m_logLevel(ll), m_msg(msg), m_line(line), m_timestamp(timestamp)
{
	m_file = SIMP_C_STR_TO_TSTRING(file);
}

SIMP_LogEvent::SIMP_LogEvent(const SIMP_LogEvent& event)
{
	*this = event;
}

SIMP_LogEvent::~SIMP_LogEvent()
{
}

SIMP_LogEvent& SIMP_LogEvent::operator =(const SIMP_LogEvent& event)
{
	m_logLevel = event.m_logLevel;
	m_msg = event.m_msg;
	m_file = event.m_file;
	m_line = event.m_line;
	m_timestamp = event.m_timestamp;

	return *this;
}

} 

