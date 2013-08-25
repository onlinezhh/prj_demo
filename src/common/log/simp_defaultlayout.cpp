/*
 * Copyright (C) 2013 zhh
 */

#include "simp_defaultlayout.h"
#include "base/simp_helper.h"


namespace SIMP_BASE
{

SIMP_DefaultLayout::SIMP_DefaultLayout()
{
}

SIMP_DefaultLayout::~SIMP_DefaultLayout()
{
}

void SIMP_DefaultLayout::FormatEvent(SIMP_OStream& out, SIMP_LogEventPtr event)
{
	out << SIMP_TEXT("[")
		<< LLToString(event->m_logLevel)
	  	<< SIMP_TEXT("] -- <")
	    << SIMP_TIMESTAMP_TO_TSTRING(event->m_timestamp)
		<< SIMP_TEXT("> ")
		<< event->m_msg
		<< SIMP_TEXT(" @")
		<< event->m_file
		<< SIMP_TEXT("(")
		<< event->m_line
		<< SIMP_TEXT(")")
		<< std::endl;
}

}
