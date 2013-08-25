/*
 * Copyright (C) 2013 zhh
 */

#include "simp_layout.h"
#include "base/simp_helper.h"


namespace SIMP_BASE
{

tchar* SIMP_Layout::sm_llDesc[] = { SIMP_TEXT("TRACE"),
								  SIMP_TEXT("DEBUG"),
								  SIMP_TEXT("INFO"),
								  SIMP_TEXT("WARNING"),
								  SIMP_TEXT("ERROR"),
								  SIMP_TEXT("FATAL") };


SIMP_Layout::SIMP_Layout()
{
}

SIMP_Layout::~SIMP_Layout()
{
}

}
