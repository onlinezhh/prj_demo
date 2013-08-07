/*
 * Copyright (C) 2013 zhh
 */

#include "simp_logevent.h"


namespace SIMP_BASE
{

SIMP_LogEvent::SIMP_LogEvent()
	: m_logLevel(LL_ALL), m_line(-1)
{
}

SIMP_LogEvent::SIMP_LogEvent(LogLevel ll,
							 const SIMP_String& msg,
							 const char* file,
							 int line)
	: m_logLevel(ll), m_msg(msg), m_file(file), m_line(line)
{
}

SIMP_LogEvent::SIMP_LogEvent(const SIMP_LogEvent& event)
{
	*this = event;
}

SIMP_LogEvent::~SIMP_LogEvent()
{
}

SIMP_LogEvent& SIMP_LogEvent::operator =(const SIMP_LogEvent& event);
{
	m_logLevel = event.m_logLevel;
	m_msg = event.m_msg;
	m_file = event.m_file;
	m_line = event.m_line;
}

} 

