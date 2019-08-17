#ifndef BBI_GENERICLOGGER_H
#define BBI_GENERICLOGGER_H

#include <string>

namespace BBI
{

namespace App
{

enum LogLevel
{
    ALL,
    VERBOSE = ALL,
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL,

    OFF
};

class GenericLogger
{
public:
    virtual ~GenericLogger(){}

    class Stream
    {
    public:
        Stream(GenericLogger& logger, LogLevel level);

    public:
        GenericLogger& logger;
        LogLevel level;
    };

    Stream& log(LogLevel level);
    virtual void log(LogLevel level, const std::string& message) = 0;

    Stream& verbose() {return log(VERBOSE);}
    void verbose(const std::string& message) {return log(VERBOSE, message);}

    Stream& trace() {return log(TRACE);}
    void trace(const std::string& message) {return log(TRACE, message);}

    Stream& debug() {return log(DEBUG);}
    void debug(const std::string& message) {return log(DEBUG, message);}

    Stream& info() {return log(INFO);}
    void info(const std::string& message) {return log(INFO, message);}

    Stream& warn() {return log(WARN);}
    void warn(const std::string& message) {return log(WARN, message);}

    Stream& error() {return log(ERROR);}
    void error(const std::string& message) {return log(ERROR, message);}

    Stream& fatal() {return log(FATAL);}
    void fatal(const std::string& message) {return log(FATAL, message);}
};

}

}

template <typename MessageType>
BBI::App::GenericLogger::Stream& operator<<(BBI::App::GenericLogger::Stream& stream, const MessageType& message)
{
    stream.logger.log(stream.level, std::to_string(message));
    return stream;
}

BBI::App::GenericLogger::Stream& operator<<(BBI::App::GenericLogger::Stream& stream, const char* message);
BBI::App::GenericLogger::Stream& operator<<(BBI::App::GenericLogger::Stream& stream, const std::string& message);
BBI::App::GenericLogger::Stream& operator<<(BBI::App::GenericLogger::Stream& stream, bool message);


#endif // GENERICLOGGER_H
