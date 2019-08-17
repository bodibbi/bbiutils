#include "GenericLogger.h"

using namespace std;

using namespace BBI::App;

GenericLogger::Stream::Stream(GenericLogger& logger, LogLevel level)
    : logger(logger),
      level(level)
{
}

GenericLogger::Stream& GenericLogger::log(LogLevel level)
{
    switch(level)
    {
    case VERBOSE:
        static GenericLogger::Stream verbose(*this, VERBOSE);
        return verbose;
    case TRACE:
        static GenericLogger::Stream trace(*this, TRACE);
        return trace;
    case DEBUG:
        static GenericLogger::Stream debug(*this, DEBUG);
        return debug;
    case INFO:
        static GenericLogger::Stream info(*this, INFO);
        return info;
    case WARN:
        static GenericLogger::Stream warn(*this, WARN);
        return warn;
    case ERROR:
        static GenericLogger::Stream error(*this, ERROR);
        return error;
    case FATAL:
        static GenericLogger::Stream fatal(*this, FATAL);
        return fatal;
    default:
        log(ERROR, " trying to log to an unkown log level");
        return log(ERROR);
    }
}

GenericLogger::Stream& operator<<(GenericLogger::Stream& stream, const std::string& message)
{
    stream.logger.log(stream.level, message);
    return stream;
}

GenericLogger::Stream& operator<<(GenericLogger::Stream& stream, bool message)
{
    static const std::string trueLogString("true");
    static const std::string falseLogString("false");

    stream.logger.log(stream.level, message ? trueLogString : falseLogString);
    return stream;
}

GenericLogger::Stream& operator<<(GenericLogger::Stream& stream, const char* message)
{
    stream.logger.log(stream.level, std::string(message));
    return stream;
}
