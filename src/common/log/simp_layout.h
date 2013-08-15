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
	virtual bool Format(SIMP_LogEventPtr event, SIMP_String& result) = 0;
};

typedef boost::shared_ptr<SIMP_Layout> SIMP_LayoutPtr;

}

#endif // COMMON_LOG_SIMP_LAYOUT_H
