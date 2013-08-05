/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_LAYOUT_H
#define COMMON_LOG_SIMP_LAYOUT_H

#include "simp_types.h"


namespace SIMP_BASE
{

class SIMP_Layout
{
public:
	SIMP_Layout();
	virtual ~SIMP_Layout();

public:
	virtual SIMP_String Format(SIMP_LogEventPtr event) = 0;

private:
	SIMP_Layout(const SIMP_Layout&);
	SIMP_Layout& operator =(const SIMP_Layout&);
};

typedef SIMP_SharedPtr<SIMP_Layout> SIMP_LayoutPtr;

}

#endif // COMMON_LOG_SIMP_LAYOUT_H
