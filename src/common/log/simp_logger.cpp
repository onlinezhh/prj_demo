/*
 * Copyright (C) 2013 zhh
 */

#include "simp_logger.h"
#include "simp_loggerimpl.h"


namespace SIMP_LOG
{

SIMP_Logger::SIMP_Logger(SIMP_LoggerImpl* impl) : m_loggerImpl(impl)
{
}

SIMP_Logger* SIMP_Logger::Instance()
{
	static SIMP_LoggerImpl impl;
	static SIMP_Logger instance(&impl);
	return &instance;
}

bool SIMP_Logger::Init()
{
	return false;
}

void SIMP_Logger::SetAppName(const SIMP_String& name)
{
	m_loggerImpl->SetName(name);
}

const SIMP_String& SIMP_Logger::GetAppName()
{
	return m_loggerImpl->GetName();
}

void SIMP_Logger::SetLogLevel(LogLevel ll)
{
	m_loggerImpl->SetLogLevel(ll);
}

LogLevel SIMP_Logger::GetLogLevel() const
{
	return m_loggerImpl->GetLogLevel();
}

void SIMP_Logger::Log(LogLevel ll,
					  const SIMP_String& msg,
					  const char* file /*= NULL*/,
					  int line /*= -1*/)
{
	m_loggerImpl->Log(ll, msg, file, line);
}

void SIMP_Logger::Assert(bool val, const SIMP_String& msg)
{
	if (!val)
	  m_loggerImpl->Log(LL_FATAL, msg);
}

}

