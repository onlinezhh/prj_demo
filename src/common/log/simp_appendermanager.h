/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_APPENDER_MANAGER_H
#define COMMON_LOG_SIMP_APPENDER_MANAGER_H

#include "simp_types.h"


namespace SIMP_BASE
{

class SIMP_Appender;
typedef SIMP_List<SIMP_Appender*> AppenderList;

class SIMP_AppenderManager
{
public:

public:
	void AddAppender(SIMP_Appender* appender);
	void RemoveAppender(const SIMP_String& name);
	void RemoveAllAppender();

	const AppenderList& GetAllAppender() { return m_appenderList; }

protected:
	SIMP_AppenderManager();
	virtual ~SIMP_AppenderManager();

protected:
	AppenderList m_appenderList;

private:
	SIMP_AppenderManager(const SIMP_AppenderManager& manager);
	SIMP_AppenderManager& operator =(const SIMP_AppenderManager& manager);
};

}

#endif
