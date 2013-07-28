/*
 * Copyright (C) 2013 zhh
 */

#include "simp_loggerimpl.h"


namespace SIMP_LOG
{

SIMP_LoggerImpl::SIMP_LoggerImpl()
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
}

void SIMP_LoggerImpl::ForceLog(LogLevel ll,
						  const SIMP_String& msg,
						  const char* file /*= NULL*/,
						  int line /*= -1*/)
{
}

}
