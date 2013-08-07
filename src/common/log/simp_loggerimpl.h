/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LOGGER_IMPL_H
#define COMMON_LOG_SIMP_LOGGER_IMPL_H

#include "simp_appendermanager.h"
#include "simp_loglevel.h"


namespace SIMP_BASE
{

class SIMP_LoggerImpl : public SIMP_AppenderManager
{
public:
	SIMP_LoggerImpl(const SIMP_String& name);
	virtual ~SIMP_LoggerImpl();

public:
	void SetLogLevel(LogLevel ll) { m_logLevel = ll; }
	LogLevel GetLogLevel() const { return m_logLevel; }

	void SetName(const SIMP_String& name) { m_name = name; }
	const SIMP_String& GetName() const { return m_name; }

	void Log(LogLevel ll, const SIMP_String& msg, const char* file = NULL, int line = -1);

private:
	bool CanLog(LogLevel ll) { return (ll >= m_logLevel); }

private:
	LogLevel m_logLevel;
	SIMP_String m_name;

private:
	SIMP_LoggerImpl();
	SIMP_LoggerImpl(const SIMP_LoggerImpl&);
	SIMP_LoggerImpl& operator =(const SIMP_LoggerImpl&);
};

}

#endif // COMMON_LOG_SIMP_LOGGER_IMPL_H
