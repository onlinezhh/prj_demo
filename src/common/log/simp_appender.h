/*
 * Copyright (C) 2013 zhh
 */

#ifndef COMMON_LOG_SIMP_APPENDER_H
#define COMMON_LOG_SIMP_APPENDER_H

#include "simp_types.h"
#include "simp_logevent.h"
#include "simp_layout.h"


namespace SIMP_BASE
{

class SIMP_Appender
{
public:
	SIMP_Appender(const SIMP_String& name, SIMP_LayoutPtr layout);
	virtual ~SIMP_Appender();

public:
	bool Open();
	void Close();

	void DoAppend(SIMP_LogEventPtr event);

	void SetName(const SIMP_String& name) { m_name = name; }
	const SIMP_String& GetName() const { return m_name; }
	void SetLayout(SIMP_LayoutPtr layout) { m_layout = layout; }
	SIMP_LayoutPtr GetLayout() const { return m_layout; }

protected:
	void Append();

	virtual bool OpenImpl() = 0;
	virtual void CloseImpl() = 0;

	virtual void AppendImpl(const SIMP_String& content) = 0;

	void FormatEvent(SIMP_LogEventPtr event, SIMP_String& result);

protected:
	SIMP_String m_name;
	SIMP_LayoutPtr m_layout;

	typedef std::list<SIMP_LogEventPtr> LogEventPtrList;
	LogEventPtrList m_eventList;

	SIMP_Mutex m_mutex;
	SIMP_Condition m_condition;

	bool m_isOpen;

private:
	SIMP_Appender();
};

typedef boost::shared_ptr<SIMP_Appender> SIMP_AppenderPtr;

}

#endif // COMMON_LOG_SIMP_APPENDER_H
