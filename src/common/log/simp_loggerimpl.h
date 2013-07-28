/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LOGGER_IMPL_H
#define COMMON_LOG_SIMP_LOGGER_IMPL_H

#include "simp_appendermanager.h"
#include "simp_logger.h"


namespace SIMP_BASE
{

class SIMP_LoggerImpl : public SIMP_AppenderManager
{
public:
	SIMP_LoggerImpl();
	~SIMP_LoggerImpl();

public:
	bool Init();

	void SetLogLevel(LogLevel ll) { m_logLevel = ll; }
	LogLevel GetLogLevel() const { return m_logLevel; }

	void Log(LogLevel ll, const SIMP_String& msg, const char* file = NULL, int line = -1);
	void ForceLog(LogLevel ll, const SIMP_String& msg, const char* file = NULL, int line = -1);

private:
	LogLevel m_logLevel;

private:
	SIMP_LoggerImpl(const SIMP_LoggerImpl& log);
	SIMP_Logger& operator =(const SIMP_LoggerImpl& log);
};

}

#endif // COMMON_LOG_SIMP_LOGGER_IMPL_H
