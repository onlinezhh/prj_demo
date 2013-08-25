/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_DEFAULT_LAYOUT_H
#define COMMON_LOG_SIMP_DEFAULT_LAYOUT_H

#include "simp_layout.h"


namespace SIMP_BASE
{

class SIMP_DefaultLayout : public SIMP_Layout
{
public:
	SIMP_DefaultLayout();
	virtual ~SIMP_DefaultLayout();

public:
	virtual void FormatEvent(SIMP_OStream& out, SIMP_LogEventPtr event);

private:
	SIMP_DefaultLayout(const SIMP_DefaultLayout&);
	SIMP_DefaultLayout& operator =(const SIMP_DefaultLayout&);
};

}

#endif // COMMON_LOG_SIMP_DEFAULT_LAYOUT_H
