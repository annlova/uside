//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SHADER_PROGRAM_H
#define USIDE_SHADER_PROGRAM_H

#include <cstdint>
#include <unordered_map>

#include <glad/glad.h>

#include "attribute.h"
#include "image.h"
#include "sampler.h"
#include "shader_block.h"
#include "uniform.h"

namespace shader {
    class ShaderProgram {
    public:
        ShaderProgram() = default;
        ShaderProgram(const ShaderProgram& program) = delete;
        ShaderProgram(ShaderProgram&& program) = delete;
        ~ShaderProgram();

        const ShaderProgram& operator=(const ShaderProgram& program) = delete;
        const ShaderProgram& operator=(ShaderProgram&& program) = delete;

    public:
        GLuint mHandle;

    public:
        std::unordered_map<std::uint64_t, Attribute>     mAttributes;
        std::unordered_map<std::uint64_t, Image>         mImages;
        std::unordered_map<std::uint64_t, Sampler>       mSamplers;
        std::unordered_map<std::uint64_t, ShaderBlock>   mShaderStorageBlocks;
        std::unordered_map<std::uint64_t, ShaderBlock>   mUniformBlocks;
        std::unordered_map<std::uint64_t, Uniform>       mUniforms;

    public:
        const Attribute& getAttribute(std::uint64_t hashedName);
        const Image& getImage(std::uint64_t hashedName);
        const Sampler& getSampler(std::uint64_t hashedName);
        const ShaderBlock& getShaderStorageBlock(std::uint64_t hashedName);
        const ShaderBlock& getUniformBlock(std::uint64_t hashedName);
        const Uniform& getUniform(std::uint64_t hashedName);
    };
}
#endif //USIDE_SHADER_PROGRAM_H
