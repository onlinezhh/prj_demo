/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_FILE_APPENDER_H
#define COMMON_LOG_SIMP_FILE_APPENDER_H

#include "simp_appender.h"


namespace SIMP_BASE
{

class SIMP_FileAppender : public SIMP_Appender
{
public:
	SIMP_FileAppender(const SIMP_String& name,
					  SIMP_LayoutPtr layout,
					  const SIMP_String& filename,
					  bool immediateFlush = true);
	virtual ~SIMP_FileAppender();

protected:
	virtual bool OpenImpl();
	virtual void CloseImpl();
	virtual void AppendImpl(SIMP_LogEventPtr event);

private:
	SIMP_OFileStream m_outStream;
	SIMP_String m_filename;
	bool m_immediateFlush;

private:
	SIMP_FileAppender();
	SIMP_FileAppender(const SIMP_FileAppender&);
	SIMP_FileAppender& operator =(const SIMP_FileAppender&);
};

}

#endif // COMMON_LOG_SIMP_FILE_APPENDER_H
