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
	if (!m_outStream.good())
	{
		return false;
	}

	return true;
}

void SIMP_FileAppender::CloseImpl()
{
	m_outStream.close();
}

void SIMP_FileAppender::AppendImpl(SIMP_LogEventPtr event)
{
	m_layout->FormatEvent(m_outStream, event);

	if (m_immediateFlush)
		m_outStream.flush();
}

}
