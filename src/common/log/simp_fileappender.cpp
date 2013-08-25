/*
 * Copyright (C) 2013 zhh
 */

#include "simp_fileappender.h"


namespace SIMP_BASE
{

SIMP_FileAppender::SIMP_FileAppender(const SIMP_String& name,
									 SIMP_LayoutPtr layout,
									 const SIMP_String& filename,
									 bool immediateFlush = true)
									 : SIMP_Appender(name, layout)
									 , m_filename(filename)
									 , m_immediateFlush(immediateFlush)
{
}

SIMP_FileAppender::~SIMP_FileAppender()
{
}

bool SIMP_FileAppender::OpenImpl()
{
	m_outStream.open(m_filename, std::ios_base::out | std::ios_base::app);
}

void SIMP_FileAppender::CloseImpl()
{

}

void SIMP_FileAppender::AppendImpl(const SIMP_String& content)
{

}

}
