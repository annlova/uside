//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_ACTIVE_VARIABLE_H
#define USIDE_SRC_SHADER_H_ACTIVE_VARIABLE_H

#include <cstdint>

#include <glad/glad.h>

namespace shader {
    struct ActiveVariable {

        ActiveVariable(GLint index, uint64_t hashedName, GLint offset, std::string name) : mIndex(index), mHashedName(hashedName), mOffset(offset), mName(name) {}

        GLint mIndex;
        std::uint64_t mHashedName;
        GLint mOffset;
        std::string mName;
    };
}
#endif //USIDE_SRC_SHADER_H_ACTIVE_VARIABLE_H
