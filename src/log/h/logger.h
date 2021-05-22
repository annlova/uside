//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_LOG_H_LOGGER_H
#define USIDE_SRC_LOG_H_LOGGER_H

#include <iostream>
#include <iomanip>
#include <windows.h>

#include <configs/log_config.h>

#include "log_flag.h"
#include "log_pad.h"
#include "log_severity_level.h"

namespace log {

    /**
     *  Class for handling debug output to console. Interacted
     *  with through the macro LOG defined on the global scope
     *  in logger_global.cpp.
     */
    class Logger {
    public:
        Logger() = default;

    public:
        const Logger& begin(LogSeverityLevel level, const char* file, long line) const;

    private:
        /** Helper function for begin() to print the severity level formatted.
         * @param severity - The severity level to print. */
        static void printSeverity(LogSeverityLevel severity) ;

        /** Helper function for begin() to print the current time formatted.*/
        static void printTime() ;

    public:
        template<typename T>
        const Logger& operator<<(const T& type) const {
            std::cout << type;
            return *this;
        }

        const Logger& operator<<(LogFlag type) const {
            switch (type.mFlag) {
                case gcLogFlagNewLine.mFlag:  std::cout << "\n" << std::setw(gcLogTitleColumnWidth) << " "; break;
                case gcLogFlagPad.mFlag:      std::cout << std::setw(gcLogTimeTitleWidth + 2) << " "; break;
                case gcLogFlagDec.mFlag:      std::cout << std::dec; break;
                case gcLogFlagHex.mFlag:      std::cout << std::hex; break;
                case gcLogFlagEnd.mFlag:      std::cout << std::endl; break;
                default: break;
            }

            return *this;
        }

        const Logger& operator<<(LogPad type) const {
            std::cout << std::setw(type.mPadding) << std::left;
            return *this;
        }
    };

    /** Global logger instance used by LOG macro to output debug messages to the console. */
    const Logger gcLogger;
}
#endif //USIDE_SRC_LOG_H_LOGGER_H
