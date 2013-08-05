/*
 * Copyright (C) 2013 zhh
 */

#include "simp_loggerimpl.h"
#include "simp_logevent.h"


namespace SIMP_LOG
{

SIMP_LoggerImpl::SIMP_LoggerImpl()
	: m_logLevel(LL_ALL), m_name("simple_log")
{
}

SIMP_LoggerImpl::SIMP_LoggerImpl(const SIMP_String& name)
	: m_logLevel(LL_ALL), m_name(name)
{
}

SIMP_LoggerImpl::~SIMP_LoggerImpl()
{
}

void SIMP_LoggerImpl::Log(LogLevel ll,
						  const SIMP_String& msg,
						  const char* file /*= NULL*/,
						  int line /*= -1*/)
{
	if (!CanLog(ll))
		return;

	SIMP_LogEventPtr eventPtr(new SIMP_LogEvent(ll, msg, file, line));
	AppendLoop(eventPtr);
}

}
