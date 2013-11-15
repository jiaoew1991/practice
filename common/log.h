#include <log4cplus/helpers/loglog.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

namespace UranusLog {
    enum Level {
        DEBUG, INFO, WARNING, ERROR, FETAL
    };
    
} /* namespace log */
void LOG(UranusLog::Level eLevel, const std::string& name, const std::string& sLogMessage)
{
    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(name));
    switch (eLevel) {
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
