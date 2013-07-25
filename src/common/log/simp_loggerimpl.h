/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LOGGER_IMPL_H
#define COMMON_LOG_SIMP_LOGGER_IMPL_H

namespace SIMP_LOG
{

class SIMP_LoggerImpl
{
public:
	SIMP_LoggerImpl();
	~SIMP_LoggerImpl();

public:
	bool Init();

	void SetLogLevel(LogLevel ll);
	LogLevel GetLogLevel() const;

	void Log(LogLevel ll, const SIMP_String& msg, const char* file = NULL, int line = -1);

private:
	SIMP_LoggerImpl(const SIMP_LoggerImpl& log);
	SIMP_Logger& operator =(const SIMP_LoggerImpl& log);
};

}

#endif // COMMON_LOG_SIMP_LOGGER_IMPL_H
