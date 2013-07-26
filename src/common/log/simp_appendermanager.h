/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_APPENDER_MANAGER_H
#define COMMON_LOG_SIMP_APPENDER_MANAGER_H

namespace SIMP_LOG
{

class SIMP_AppenderManager
{
public:
	void AddAppender();
	void RemoveAppender();

protected:
	SIMP_AppenderManager();
	virtual ~SIMP_AppenderManager();

private:
	SIMP_AppenderManager(const SIMP_AppenderManager& manager);
	SIMP_AppenderManager& operator =(const SIMP_AppenderManager& manager);
};

}

#endif
