//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_LOG_H_LOGGER_H
#define USIDE_SRC_LOG_H_LOGGER_H

#include <iostream>
#include <iomanip>
#include <windows.h>

#include <configs/log_config.h>

#include "log_severity_level.h"
#include "log_buffer.h"

namespace logs {

    /**
     *  Class for handling debug output to console. Interacted
     *  with through the macro LOG defined on the global scope
     *  in logger_global.cpp.
     */
class LogStream : public std::ostream {
    public:
        LogStream() : mLogBuffer(std::cout.rdbuf()), std::ostream(&mLogBuffer) {}

    public:
        LogStream& begin(LogSeverityLevel level, const char* file, long line);

    private:
        /** Helper function for begin() to print the severity level formatted.
         * @param severity - The severity level to print. */
        static void appendSeverity(LogSeverityLevel severity, std::stringstream& stringBuilder) ;

        /** Helper function for begin() to print the current time formatted.*/
        static void appendTime(std::stringstream& stringBuilder) ;

    private:
        LogBuffer mLogBuffer;
    };

    /** Global LogStream instance used by LOG macro to output debug messages to the console. */
    extern LogStream& getLogStream();
}
#endif //USIDE_SRC_LOG_H_LOGGER_H
