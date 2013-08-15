/*
 * Copyright (C) 2013 zhh
 */

#include "simp_appender.h"
#include <assert.h>


namespace SIMP_BASE
{

SIMP_Appender::SIMP_Appender(const SIMP_String& name, SIMP_LayoutPtr layout)
	: m_name(name), m_layout(layout), m_isOpen(false), m_isWait(false)
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

	m_isOpen = OpenImpl();

	if (m_isOpen)
	{
		SIMP_Thread thrd(&SIMP_Appender::Append, this);
		thrd.detach();
	}

	return m_isOpen;
}

void SIMP_Appender::Close()
{
	if (!m_isOpen)
		return;

	m_mutex.lock();

	m_isOpen = false;

	if (m_isWait)
	{
		m_condition.notify_all();
		m_isWait = false;
	}
	else
	{
		if (0 != m_eventList.size())
		{
			m_isWait = true;
			m_condition.wait(m_mutex);
		}
	}

	m_mutex.unlock();

	CloseImpl();
}

void SIMP_Appender::DoAppend(SIMP_LogEventPtr event)
{
	if (!m_isOpen)
		return; // must be opened

	m_mutex.lock();

	m_eventList.push_back(event);
	if (m_isWait)
	{
		m_condition.notify_all();
		m_isWait = false;
	}

	m_mutex.unlock();
}

void SIMP_Appender::Append()
{
	while (m_isOpen || 0 != m_eventList.size())
	{
		m_mutex.lock();

		if (0 == m_eventList.size())
		{
			m_isWait = true;
			m_condition.wait(m_mutex);
		}

		SIMP_LogEventPtr event;
		if (0 != m_eventList.size())
		{
			event = m_eventList.front();
			m_eventList.pop_front();
		}

		m_mutex.unlock();

		SIMP_String result;
		if (!FormatEvent(event, result))
			continue;

		AppendImpl(result);
	}

	m_mutex.lock();

	if (m_isWait)
	{
		m_condition.notify_all();
		m_isWait = false;
	}

	m_mutex.unlock();
}

bool SIMP_Appender::FormatEvent(SIMP_LogEventPtr event,
								SIMP_String& result)
{
	if (NULL == m_layout.get() || NULL == event.get())
	{
		assert(false);
		return false;
	}

	return m_layout->Format(event, result);
}

}
