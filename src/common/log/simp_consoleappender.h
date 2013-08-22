/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_CONSOLE_APPENDER_H
#define COMMON_LOG_SIMP_CONSOLE_APPENDER_H

#include "simp_appender.h"


namespace SIMP_BASE
{

class SIMP_ConsoleAppender : public SIMP_Appender
{
public:
	SIMP_ConsoleAppender(const SIMP_String& name, SIMP_LayoutPtr layout);
	virtual ~SIMP_ConsoleAppender();

protected:
	virtual bool OpenImpl() { return true; }
	virtual void CloseImpl() {}
	virtual void AppendImpl(const SIMP_String& content);

private:
	SIMP_ConsoleAppender();
	SIMP_ConsoleAppender(const SIMP_ConsoleAppender&);
	SIMP_ConsoleAppender& operator =(const SIMP_ConsoleAppender&);
};

}

#endif // COMMON_LOG_SIMP_CONSOLE_APPENDER_H
