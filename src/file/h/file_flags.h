//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_FILE_FLAGS_H
#define USIDE_FILE_FLAGS_H

#include <fstream>

namespace file {
    enum WriteFlag : unsigned long {
        TRUNCATE = std::ios::trunc,
        APPEND   = std::ios::app
    };
}

#endif //USIDE_FILE_FLAGS_H
