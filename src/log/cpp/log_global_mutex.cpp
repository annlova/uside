//
// Created by Anton on 2021-05-12.
//

#include "../h/log_global_mutex.h"

std::mutex log::gLogMutex{}; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
