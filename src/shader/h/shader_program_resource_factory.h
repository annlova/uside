//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SHADER_PROGRAM_RESOURCE_FACTORY_H
#define USIDE_SHADER_PROGRAM_RESOURCE_FACTORY_H

#include <cstdint>
#include <memory>
#include <array>
#include <tuple>
#include <unordered_map>

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
        static const Attribute& emplaceAttributeInMap(GLuint programHandle, GLuint attributeIndex, std::unordered_map<std::uint64_t, Attribute>& map);
        static const Uniform& emplaceUniformInMap(GLuint programHandle, GLuint uniformIndex, std::unordered_map<std::uint64_t, Uniform>& map);
        static const Sampler& emplaceSamplerInMap(GLuint programHandle, GLuint uniformIndex, GLint textureImageUnit, std::unordered_map<std::uint64_t, Sampler>& map);
        static const Image& emplaceImageInMap(GLuint programHandle, GLuint uniformIndex, GLint imageUnit, GLint imageFormat, std::unordered_map<std::uint64_t, Image>& map);
        static const ShaderBlock& emplaceShaderBlockInMap(GLuint programHandle, GLuint blockProgramInterface, GLuint blockIndex, std::unordered_map<std::uint64_t, ShaderBlock>& map);

    public:
        static bool isUniformIndexAUniformBlockVariable(GLuint programHandle, GLuint uniformIndex);
        static UniformType getUniformType(GLuint programHandle, GLuint uniformIndex);

    private:
        static bool isValidIndex(GLuint programHandle, GLenum programInterface, GLuint index);

    private:
        static GLint getParameter(GLuint programHandle, GLenum programInterface, GLuint index, GLenum property);

        static std::vector<GLint> getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const GLenum property, GLsizei numParametersOut);

        template <GLsizei size>
        static std::vector<GLint> getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const std::array<GLenum, size>& properties, GLsizei numParametersOut);

        template <GLsizei size>
        static std::array<GLint, size> getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const std::array<GLenum, size>& properties);

        static std::string getName(GLuint programHandle, GLenum programInterface, GLuint index);

        static GLint getBlockVariableProgramInterface(GLuint blockProgramInterface);

    private:
        template<class T, class Tuple>
        static constexpr T fillResourceStructFromTuple(GLuint index, std::uint64_t hashedName, Tuple&& t);
    };
}
#endif //USIDE_SHADER_PROGRAM_RESOURCE_FACTORY_H
