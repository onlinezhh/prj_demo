SET(LIBLOG_LIST
	simp_logger.cpp
	simp_loggerimpl.cpp
	simp_appender.cpp
	simp_fileappender.cpp
	simp_consoleappender.cpp
	simp_appendermanager.cpp
	simp_layout.cpp
	simp_defaultlayout.cpp
	simp_logevent.cpp)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

ADD_LIBRARY(SimpleLog SHARED ${LIBLOG_LIST})
SET_TARGET_PROPERTIES(SimpleLog
	PROPERTIES CLEAN_DIRECT_OUTPUT 1
	VERSION 1.0
	SOVERSION 1)

ADD_LIBRARY(SimpleLog_Static STATIC ${LIBLOG_LIST})
SET_TARGET_PROPERTIES(SimpleLog_Static
	PROPERTIES CLEAN_DIRECT_OUTPUT 1
	OUTPUT_NAME "SimpleLog")
