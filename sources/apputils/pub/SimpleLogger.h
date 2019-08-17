#ifndef BBI_SIMPLELOGGER_H
#define BBI_SIMPLELOGGER_H

#include "GenericLogger.h"

namespace BBI
{

namespace App
{

class SimpleLogger: public GenericLogger
{
public:
    virtual void log(LogLevel level, const std::string& message);
};

}

}

#endif //BBI_SIMPLELOGGER_H
