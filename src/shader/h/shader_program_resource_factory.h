//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SHADER_PROGRAM_RESOURCE_FACTORY_H
#define USIDE_SHADER_PROGRAM_RESOURCE_FACTORY_H

#include <cstdint>
#include <memory>
#include <array>
#include <tuple>

#include <glad/glad.h>

#include "attribute.h"
#include "image.h"
#include "sampler.h"
#include "shader_block.h"
#include "uniform.h"
#include "uniform_type.h"

namespace shader {
    class ShaderProgramResourceFactory {
    public:
        static void fillAttribute(GLuint programHandle, GLuint attributeIndex, Attribute& attribute);
        static void fillUniform(GLuint programHandle, GLuint uniformIndex, Uniform& uniform);
        static void fillSampler(GLuint programHandle, GLuint uniformIndex, GLint textureImageUnit, Sampler& sampler);
        static void fillImage(GLuint programHandle, GLuint uniformIndex, GLint imageUnit, GLint imageFormat, Image& image);
        static void fillShaderBlock(GLuint programHandle, GLuint blockProgramInterface, GLuint blockIndex, ShaderBlock& shaderBlock);

    public:
        static bool isUniformIndexAUniformBlockVariable(GLuint programHandle, GLuint uniformIndex);
        static UniformType getUniformType(GLuint programHandle, GLuint uniformIndex);

    private:
        static bool isValidIndex(GLuint programHandle, GLenum programInterface, GLuint index);

    private:
        static GLint getParameter(GLuint programHandle, GLenum programInterface, GLuint index, GLenum property);

        static std::vector<GLint> getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const GLenum property, GLsizei numParametersOut);

        template <GLsizei size>
        static std::vector<GLint> getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const std::array<GLenum, size>& properties, GLsizei numParametersOut = size);

        static std::uint64_t getHashedName(GLuint programHandle, GLenum programInterface, GLuint index);

        static GLint getBlockVariableProgramInterface(GLuint blockProgramInterface);

    private:
        template<class T, class Tuple, std::size_t... I>
        static constexpr T fillResourceStructFromTupleImpl(GLuint index, std::uint64_t hashedName, Tuple&& t, std::index_sequence<I...>);

        template<class T, class Tuple>
        static constexpr T fillResourceStructFromTuple(GLuint index, std::uint64_t hashedName, Tuple&& t);
    };
}
#endif //USIDE_SHADER_PROGRAM_RESOURCE_FACTORY_H
