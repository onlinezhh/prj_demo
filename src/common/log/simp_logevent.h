/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LOG_EVENT_H
#define COMMON_LOG_SIMP_LOG_EVENT_H

#include "simp_loglevel.h"
#include "simp_types.h"


namespace SIMP_BASE
{

class SIMP_LogEvent
{
public:
	SIMP_LogEvent();
	SIMP_LogEvent(LogLevel ll,
				  const SIMP_String& msg,
				  const char* file,
				  int line,
				  const SIMP_DateTime& timestamp);
	SIMP_LogEvent(const SIMP_LogEvent& event);
	~SIMP_LogEvent();

public:
	SIMP_LogEvent& operator =(const SIMP_LogEvent& event);

public:
	LogLevel m_logLevel;
	SIMP_String m_msg;
	SIMP_String m_file;
	int m_line;
	SIMP_DateTime m_timestamp;
};

typedef boost::shared_ptr<SIMP_LogEvent> SIMP_LogEventPtr;

}

#endif // COMMON_LOG_SIMP_LOG_EVENT_H
