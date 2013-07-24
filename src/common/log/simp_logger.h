/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LOGGER_H
#define COMMON_LOG_SIMP_LOGGER_H

namespace SIMP_LOG
{

class SIMP_Logger
{
public:
	static SIMP_Logger* Instance();

private:
	SIMP_Logger();
	SIMP_Logger(const SIMP_Logger& log);
	~SIMP_Logger();

	SIMP_Logger& operator= (const SIMP_Logger& log);
};

}

#endif
