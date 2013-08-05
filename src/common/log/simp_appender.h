/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_APPENDER_H
#define COMMON_LOG_SIMP_APPENDER_H

#include "simp_types.h"
#include "simp_logevent.h"


namespace SIMP_BASE
{

class SIMP_Appender
{
public:
	SIMP_Appender();
	virtual ~SIMP_Appender();

public:
	void DoAppend(SIMP_LogEventPtr event);
	SIMP_String FormatEvent(SIMP_LogEventPtr event);

	virtual Append() = 0;
	virtual void Close() = 0;

	void SetName(const SIMP_String& name) { m_name = name; }
	const SIMP_String& GetName() const { return m_name; }
	void SetLayout(SIMP_LayoutPtr layout) { m_layout = layout; }
	SIMP_LayoutPtr GetLayout() const { return m_layout; }

protected:
	SIMP_String m_name;
	SIMP_LayoutPtr m_layout;
};

typedef SIMP_SharedPtr<SIMP_Appender> SIMP_AppenderPtr;

}

#endif // COMMON_LOG_SIMP_APPENDER_H
