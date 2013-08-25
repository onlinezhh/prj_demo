/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LAYOUT_H
#define COMMON_LOG_SIMP_LAYOUT_H

#include "simp_types.h"
#include "simp_logevent.h"


namespace SIMP_BASE
{

class SIMP_Layout
{
public:
	SIMP_Layout();
	virtual ~SIMP_Layout();

public:
	static SIMP_String LLToString(LogLevel ll) { return SIMP_String(sm_llDesc[ll - LL_ALL - 1]); }

public:
	virtual void FormatEvent(SIMP_OStream& out, SIMP_LogEventPtr event) = 0;

private:
	static tchar* sm_llDesc[6];
};

typedef boost::shared_ptr<SIMP_Layout> SIMP_LayoutPtr;

}

#endif // COMMON_LOG_SIMP_LAYOUT_H
