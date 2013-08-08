/*
 * Copyright (C) 2013 zhh
 */

#include "simp_appender.h"


namespace SIMP_BASE
{

SIMP_Appender::SIMP_Appender(const SIMP_String& name, SIMP_LayoutPtr layout)
	: m_name(name), m_layout(layout), m_isOpen(false)
{
}

SIMP_Appender::~SIMP_Appender()
{
	Close();
}

bool SIMP_Appender::Open()
{
	if (m_isOpen)
		return true;

	SIMP_Thread thread(&SIMP_Appender::Append, this);
	thread.detach();

	m_isOpen = OpenImpl();

	return m_isOpen;
}

void SIMP_Appender::Close()
{
	if (!m_isOpen)
		return;

	CloseImpl();
	m_isOpen = false;
}

void SIMP_Appender::DoAppend(SIMP_LogEventPtr event)
{
	if (!m_isOpen)
		return; // must be opened

	m_mutex.lock();

	m_eventList.push_back(event);

	m_mutex.unlock();
}

void SIMP_Appender::Append()
{
}

void SIMP_Appender::FormatEvent(SIMP_LogEventPtr event,
								SIMP_String& result)
{
}

}
