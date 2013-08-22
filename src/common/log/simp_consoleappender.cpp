/*
 * Copyright (C) 2013 zhh
 */

#include "simp_consoleappender.h"


namespace SIMP_BASE
{

SIMP_ConsoleAppender::SIMP_ConsoleAppender(const SIMP_String& name, SIMP_LayoutPtr layout)
	: SIMP_Appender(name, layout)
{
}

SIMP_ConsoleAppender::~SIMP_ConsoleAppender()
{
}

void SIMP_ConsoleAppender::AppendImpl(const SIMP_String& content)
{

}

}
