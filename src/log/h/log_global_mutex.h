//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_LOG_H_LOG_GLOBAL_MUTEX_H
#define USIDE_SRC_LOG_H_LOG_GLOBAL_MUTEX_H

#include <mutex>

namespace log {
    /**
     * Used by log macro to ensure consecutive << calls on log will
     * not output interleaved with calls to log on other threads.
     */
    extern std::mutex gLogMutex;
}
#endif //USIDE_SRC_LOG_H_LOG_GLOBAL_MUTEX_H
