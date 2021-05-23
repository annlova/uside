//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_ACTIVE_VARIABLE_H
#define USIDE_ACTIVE_VARIABLE_H

#include <cstdint>

#include <glad/glad.h>

namespace shader {
    struct ActiveVariable {

        ActiveVariable(GLint mIndex, uint64_t mHashedName, GLint mOffset) : mIndex(mIndex), mHashedName(mHashedName), mOffset(mOffset) {}

        GLint mIndex;
        std::uint64_t mHashedName; // TODO
        GLint mOffset;
    };
}
#endif //USIDE_ACTIVE_VARIABLE_H
