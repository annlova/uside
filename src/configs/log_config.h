//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_CONFIGS_LOGGING_LOGGING_CONFIG_H
#define USIDE_SRC_CONFIGS_LOGGING_LOGGING_CONFIG_H

// Controls whether or not logging output should be enabled.
#define USIDE_WITH_FEATURE_LOG() 1

/** <pre>
 * Controls the max severity level of logs messages output.<br>
 * 0 - Fatal:      Severe error that will prevent the application from continuing.<br>
 * 1 - Error:      Error in the application, possibly recoverable.<br>
 * 2 - Warning:    Event that might possibly lead to an error.<br>
 * 3 - Info:       General useful information.<br>
 * 4 - Debug:      Debug-level messages (i.e. messages logged for the sake of debugging, such as: "Opening config file ...").<br>
 * 5 - Trace:      Used for when tracing code and should provide context to understand the flow of the program, more fine-grained than debug messages.<br>
 * </pre> */
#define USIDE_LOG_MAX_SEVERITY() 5

/** Controls the severity level used when using LOG_DEF() macro. */
#define USIDE_LOG_DEFAULT_SEVERITY() logs::INF

#include <log/h/log_flag.h>

namespace logs {
    constexpr std::array<unsigned int, 6> gcLogSeverityLevelConsoleTextAttribute = {
            31,  // FTL
            91,  // ERR
            93,  // WRN
            94,  // INF
            33,  // DBG
            95   // TRC
    };

    /** Used for formatting logs output title bar severity part. */
    inline constexpr int gcLogSeverityTitleWidth   = 3;

    /** Used for formatting logs output title bar time part. */
    inline constexpr int gcLogTimeTitleWidth       = 8;

    /** Used for formatting logs output title bar file name part.*/
    inline constexpr int gcLogFileTitleWidth       = 16;

    /** Used for formatting logs output title bar file name part.*/
    inline constexpr int gcLogLineTitleWidth       = 4;

    /** Used for formatting logs output title bar file name part.*/
    inline constexpr int gcLogThreadTitleWidth     = 2;

    /** Used for formatting logs output title bar. */
    inline constexpr int gcLogTitleColumnWidth     = 1 + gcLogTimeTitleWidth + 2 + gcLogFileTitleWidth + 2 + gcLogLineTitleWidth + 2 + gcLogThreadTitleWidth + 2 + gcLogSeverityTitleWidth + 2;

    /** Used to format time for output title bar. */
    inline constexpr auto gcLogTimeTitleFormat     = "%H:%M:%S";

    inline constexpr LogFlag gcLogFlagNewLine{0};
    inline constexpr LogFlag gcLogFlagPad{1};
    inline constexpr LogFlag gcLogFlagDec{2};
    inline constexpr LogFlag gcLogFlagHex{3};
    inline constexpr LogFlag gcLogFlagEnd{4};
}
#endif //USIDE_SRC_CONFIGS_LOGGING_LOGGING_CONFIG_H
