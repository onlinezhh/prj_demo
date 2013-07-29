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

void SIMP_AppenderManager::AddAppender(SIMP_Appender* appender)
{
	assert(appender != NULL);

	if (NULL != appender)
		m_appenderList.push_back(appender);
}

void SIMP_AppenderManager::RemoveAppender(const SIMP_String& name)
{
}

void SIMP_AppenderManager::RemoveAllAppender()
{
}

const SIMP_Appender* SIMP_AppenderManager::GetAppender(const SIMP_String& name)
{
}

}
