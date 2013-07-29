/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_APPENDER_H
#define COMMON_LOG_SIMP_APPENDER_H

#include "simp_types.h"


namespace SIMP_BASE
{

class SIMP_Appender
{
public:
	SIMP_Appender();
	~SIMP_Appender();
};

typedef SIMP_SharedPtr<SIMP_Appender> SIMP_AppenderPtr;

}

#endif // COMMON_LOG_SIMP_APPENDER_H
