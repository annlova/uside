//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_LOGS_H_LOG_GLOBAL_MUTEX_H
#define USIDE_SRC_LOGS_H_LOG_GLOBAL_MUTEX_H

#include <mutex>

namespace logs {
    /**
     * Used by logs macro to ensure consecutive << calls on logs will
     * not output interleaved with calls to logs on other threads.
     */
    extern std::mutex gLogMutex;
}
#endif //USIDE_SRC_LOGS_H_LOG_GLOBAL_MUTEX_H
