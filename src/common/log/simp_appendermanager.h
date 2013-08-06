/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_APPENDER_MANAGER_H
#define COMMON_LOG_SIMP_APPENDER_MANAGER_H

#include "simp_types.h"
#include "simp_appender.h"


namespace SIMP_BASE
{

typedef SIMP_List<SIMP_AppenderPtr> AppenderPtrList;

class SIMP_AppenderManager
{
public:
	void AddAppender(SIMP_AppenderPtr appender);
	void RemoveAppender(const SIMP_String& name);
	void RemoveAllAppender() { m_appenderList.clear(); }

	SIMP_AppenderPtr GetAppender(const SIMP_String& name);
	const AppenderPtrList& GetAllAppender() { return m_appenderList; }

	void AppendLoop(SIMP_LogEventPtr eventPtr) const;

protected:
	SIMP_AppenderManager();
	virtual ~SIMP_AppenderManager();

protected:
	AppenderPtrList m_appenderList;

private:
	SIMP_AppenderManager(const SIMP_AppenderManager&);
	SIMP_AppenderManager& operator =(const SIMP_AppenderManager&);
};

}

#endif // COMMON_LOG_SIMP_APPENDER_MANAGER_H
