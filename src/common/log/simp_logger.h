/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LOGGER_H
#define COMMON_LOG_SIMP_LOGGER_H

#include "simp_loglevel.h"
#include "simp_types.h"


namespace SIMP_BASE
{

//! \brief	logger interface
class SIMP_Logger
{
public:
	static SIMP_Logger* Instance();

public:
	bool Init();

	void SetAppName(const SIMP_String& name);
	const SIMP_String& GetAppName() const;
	void SetLogLevel(LogLevel ll);
	LogLevel GetLogLevel() const;

	void Log(LogLevel ll, const SIMP_String& msg, const char* file = NULL, int line = -1);
	void Assert(bool val, const SIMP_String& msg);

	~SIMP_Logger();

private:
	class SIMP_LoggerImpl;
	SIMP_Logger(SIMP_LoggerImpl* impl);

private:
	SIMP_Logger();
	SIMP_Logger(const SIMP_Logger& log);

	SIMP_Logger& operator =(const SIMP_Logger& log);

private:
	SIMP_LoggerImpl* m_loggerImpl;
};

}

#endif // COMMON_LOG_SIMP_LOGGER_H
