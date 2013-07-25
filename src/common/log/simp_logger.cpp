/*
 * Copyright (C) 2013 zhh
 */

#include "simp_logger.h"


namespace SIMP_LOG
{

SIMP_Logger* SIMP_Logger::Instance()
{
	static SIMP_Logger instance;
	return &instance;
}

bool SIMP_Logger::Init()
{
}

void SIMP_Logger::SetLogLevel(LogLevel ll)
{
}

LogLevel SIMP_Logger::GetLogLevel() const
{
}

void SIMP_Logger::Log(LogLevel ll, const SIMP_String& msg, const char* file /*= NULL*/, int line /*= -1*/)
{
}

void SIMP_Logger::Assert(bool val, const SIMP_String& msg)
{
}

}


