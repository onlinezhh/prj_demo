/*
 * Copyright (C) 2013 zhh
 */

#include "simp_appender.h"
#include <assert.h>


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

	if (0 == m_eventList.size())
	{
		m_condition.notify_all();
	}
	else
	{
		// wait for all events to be logged
		m_condition.wait(m_mutex);
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
	if (1 == m_eventList.size())
	{
		// the event list is not empty now
		m_condition.notify_all();
	}

	m_mutex.unlock();
}

void SIMP_Appender::Append()
{
	while (true)
	{
		m_mutex.lock();

		if (!m_isOpen && 0 == m_eventList.size())
		{
			m_mutex.unlock();
			break;
		}

		if (0 == m_eventList.size())
		{
			// no event in the list to handle
			m_condition.wait(m_mutex);

			if (!m_isOpen)
			{
				// be waken up by Close() and the event list is still empty
				m_mutex.unlock();
				break;
			}
		}

		// at least one event had been put in the list
		SIMP_LogEventPtr event = m_eventList.front();
		m_eventList.pop_front();

		m_mutex.unlock();

		AppendImpl(event);
	}

	m_condition.notify_all();
}

}
