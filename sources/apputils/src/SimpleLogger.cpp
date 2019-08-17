#include "SimpleLogger.h"

#include <iostream>
#include <unordered_map>

using namespace std;

using namespace BBI::App;

void SimpleLogger::log(LogLevel level, const string& message)
{
    const static unordered_map<BBI::App::LogLevel, std::string> levelString = {
      { LogLevel::VERBOSE, "VERBOSE: "},
      { LogLevel::TRACE, "TRACE: "},
      { LogLevel::DEBUG, "DEBUG: "},
      { LogLevel::INFO, "INFO: "},
      { LogLevel::WARN, "WARN: "},
      { LogLevel::ERROR, "ERROR: "},
      { LogLevel::FATAL, "FATAL: "},
    };

    switch(level)
    {
    case LogLevel::VERBOSE:
    case LogLevel::TRACE:
    case LogLevel::DEBUG:
    case LogLevel::INFO:
    case LogLevel::WARN:
        cout << levelString.at(level) << message << endl;
        break;
    case LogLevel::ERROR:
    case LogLevel::FATAL:
        cerr << levelString.at(level) << message << endl;
        break;
    default:
        log(LogLevel::ERROR, "trying to log to an unknown log level");
        break;
    }
}

GenericLogger& SimpleLogger::getInstance()
{
    static SimpleLogger logger;
    return logger;
}
