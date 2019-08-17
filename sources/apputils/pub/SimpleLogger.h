#ifndef BBI_SIMPLELOGGER_H
#define BBI_SIMPLELOGGER_H

#include "GenericLogger.h"

#define VERBOSE_LOG() SimpleLogger::getInstance().verbose() << __PRETTY_FUNCTION__
#define TRACE_LOG() SimpleLogger::getInstance().trace() << __PRETTY_FUNCTION__
#define DEBUG_LOG() SimpleLogger::getInstance().debug() << __PRETTY_FUNCTION__
#define INFO_LOG() SimpleLogger::getInstance().info() << __PRETTY_FUNCTION__
#define WARN_LOG() SimpleLogger::getInstance().warn() << __PRETTY_FUNCTION__
#define ERROR_LOG() SimpleLogger::getInstance().error() << __PRETTY_FUNCTION__
#define FATAL_LOG() SimpleLogger::getInstance().fatal() << __PRETTY_FUNCTION__


namespace BBI
{

namespace App
{

class SimpleLogger: public GenericLogger
{
public:
    virtual void log(LogLevel level, const std::string& message);

    static GenericLogger& getInstance();
};

}

}

#endif //BBI_SIMPLELOGGER_H
