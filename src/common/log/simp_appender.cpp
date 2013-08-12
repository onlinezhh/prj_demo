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
	if (1 == m_eventList.size())
	{
		m_condition.notify_all();
	}

	m_mutex.unlock();
}

void SIMP_Appender::Append()
{
	m_mutex.lock();

	if (0 == m_eventList.size())
	{
		m_condition.wait(m_mutex);
	}

	SIMP_LogEventPtr event = m_eventList.front();
	m_eventList.pop_front();

	m_mutex.unlock();

	SIMP_String result;
	FormatEvent(event, result);

	AppendImpl(result);
}

void SIMP_Appender::FormatEvent(SIMP_LogEventPtr event,
								SIMP_String& result)
{
}

}
