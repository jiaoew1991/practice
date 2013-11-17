#include <log4cplus/helpers/loglog.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/mdc.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

#define INIT_LOG(NAME) \
	log4cplus::initialize();\
	LogLog::getLogLog()->setInternalDebugging(true);\
	SharedObjectPtr<Appender> append1(new ConsoleAppender());\
	append1->setName(LOG4CPLUS_TEXT(NAME));\
	log4cplus::getMDC().put(LOG4CPLUS_TEXT("key"), LOG4CPLUS_TEXT("MDC value"));\
	log4cplus::tstring pattern =\
			LOG4CPLUS_TEXT(\
					"%d{%m/%d/%y %H:%M:%S,%Q} [%t] %-5p %c{2} %%%x%% - %X{key} - %m [%l]%n");\
	append1->setLayout(std::auto_ptr<Layout>(new PatternLayout(pattern)));\
	Logger::getRoot().addAppender(append1);\


namespace UranusLog
{
enum Level
{
	DEBUG, INFO, WARNING, ERROR, FETAL
};

} /* namespace log */
void LOG(UranusLog::Level eLevel, const std::string& name,
		const std::string& sLogMessage)
{
	log4cplus::Logger logger = log4cplus::Logger::getInstance(
			LOG4CPLUS_TEXT(name));
	switch (eLevel)
	{
	case UranusLog::INFO:
		LOG4CPLUS_INFO(logger, sLogMessage);
		break;
	case UranusLog::DEBUG:
		LOG4CPLUS_DEBUG(logger, sLogMessage);
		break;
	case UranusLog::WARNING:
		LOG4CPLUS_WARN(logger, sLogMessage);
		break;
	case UranusLog::ERROR:
		LOG4CPLUS_ERROR(logger, sLogMessage);
		break;
	case UranusLog::FETAL:
		LOG4CPLUS_FATAL(logger, sLogMessage);
		break;
	}
}
