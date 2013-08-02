/*
 * Copyright (C) 2013 zhh
 */

#include "simp_loggerimpl.h"


namespace SIMP_LOG
{

SIMP_LoggerImpl::SIMP_LoggerImpl() : m_logLevel(LL_ALL), m_name("simple_log")
{
}

SIMP_LoggerImpl::SIMP_LoggerImpl(const SIMP_String& name) : m_name(name)
{
}

SIMP_LoggerImpl::~SIMP_LoggerImpl()
{
}

bool SIMP_LoggerImpl::Init()
{
}

void SIMP_LoggerImpl::Log(LogLevel ll,
						  const SIMP_String& msg,
						  const char* file /*= NULL*/,
						  int line /*= -1*/)
{
	if (!CanLog(ll))
		return;

	LogEventPtr eventPtr(new LogEvent(ll, msg, file, line));
	AppendLoop(eventPtr);
}

}
