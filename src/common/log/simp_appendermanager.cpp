/*
 * Copyright (C) 2013 zhh
 */

#include "simp_appendermanager.h"
#include "simp_appender.h"
#include <assert.h>


namespace SIMP_BASE
{

SIMP_AppenderManager::SIMP_AppenderManager()
{
}

SIMP_AppenderManager::~SIMP_AppenderManager()
{
	RemoveAllAppender();
}

void SIMP_AppenderManager::AddAppender(SIMP_AppenderPtr appender)
{
	if (NULL == appender)
	{
		assert(false);
		return;
	}

	AppenderPtrList::iterator it = std::find(m_appenderList.begin(),
		m_appenderList.end(), appender);

	if (it == m_appenderList.end())
		m_appenderList.push_back(appender);
}

void SIMP_AppenderManager::RemoveAppender(const SIMP_String& name)
{
	for (AppenderPtrList::iterator it = m_appenderList.begin();
		it != m_appenderList.end();
		++it)
	{
		if ((*it)->GetName() == name)
		{
			m_appenderList.erase(it);
			break;
		}
	}
}

const SIMP_AppenderPtr SIMP_AppenderManager::GetAppender(const SIMP_String& name)
{
	for (AppenderPtrList::iterator it = m_appenderList.begin();
		it != m_appenderList.end();
		++it)
	{
		if (it->GetName() == name)
			return *it;
	}

	return SIMP_AppenderPtr(NULL);
}

void SIMP_AppenderManager::AppendLoop(const SIMP_LogEvent& event) const
{
	for (AppenderPtrList::iterator it = m_appenderList.begin();
		it != m_appenderList.end();
		++it)
	{
		(*it)->DoAppend(event);
	}
}

}
