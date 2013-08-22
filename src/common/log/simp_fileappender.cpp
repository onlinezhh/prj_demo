/*
 * Copyright (C) 2013 zhh
 */

#include "simp_fileappender.h"


namespace SIMP_BASE
{

SIMP_FileAppender::SIMP_FileAppender(const SIMP_String& name, SIMP_LayoutPtr layout)
	: SIMP_Appender(name, layout)
{
}

SIMP_FileAppender::~SIMP_FileAppender()
{
}

bool SIMP_FileAppender::OpenImpl()
{
	return false;
}

void SIMP_FileAppender::CloseImpl()
{

}

void SIMP_FileAppender::AppendImpl(const SIMP_String& content)
{

}

}
