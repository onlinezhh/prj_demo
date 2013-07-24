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

}


