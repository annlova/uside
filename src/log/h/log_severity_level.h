//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_LOG_H_LOG_SEVERITY_LEVEL_H
#define USIDE_SRC_LOG_H_LOG_SEVERITY_LEVEL_H

namespace log {
    enum LogSeverityLevel {
        FTL   = 0,
        ERR   = 1,
        WRN   = 2,
        INF   = 3,
        DBG   = 4,
        TRC   = 5
    };
}
#endif //USIDE_SRC_LOG_H_LOG_SEVERITY_LEVEL_H