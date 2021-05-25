//
// Created by anton on 2021-05-23.
//

#include "../h/shader_program_resource_factory.h"

#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>
#include <string/include/string_hash_include.h>

const shader::Attribute& shader::ShaderProgramResourceFactory::emplaceAttributeInMap(GLuint programHandle, GLuint attributeIndex, std::unordered_map<std::uint64_t, Attribute>& map) {
    const GLenum programInterface = GL_PROGRAM_INPUT;
    ASSERT_MSG(isValidIndex(programHandle, programInterface, attributeIndex), "Attribute index not valid.");

    // Retrieve the attribute name
    auto name = getName(programHandle, programInterface, attributeIndex);
    auto hashedName = hash(name.c_str(), name.size());

    // Retrieve the attribute parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Attribute::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, attributeIndex, Attribute::mscProperties);

    // Set variables in the output Attribute.
    auto inserted = map.emplace(std::make_pair(hashedName, fillResourceStructFromTuple<Attribute>(attributeIndex, hashedName, parameters)));
    ASSERT_MSG(inserted.second, "Attribute collision in ShaderProgram attribute map.");
    inserted.first->second.mName = name;

    return inserted.first->second;
}

const shader::Uniform& shader::ShaderProgramResourceFactory::emplaceUniformInMap(GLuint programHandle, GLuint uniformIndex, std::unordered_map<std::uint64_t, Uniform>& map) {
    LOG_TRC() << "Filling shader program uniform..."<< LOG_END;

    const GLenum programInterface = GL_UNIFORM;
    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Check that the uniform is a pure uniform, not a sampler or image.
    ASSERT_MSG(getUniformType(programHandle, uniformIndex) == UNIFORM, "Uniform is not a pure uniform.");

    // Retrieve the uniform name and hash it
    auto name = getName(programHandle, programInterface, uniformIndex);
    auto hashedName = hash(name.c_str(), name.size());

    // Retrieve the uniform parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Uniform::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, uniformIndex, Uniform::mscProperties);

    // Set variables in the output Uniform
    auto inserted = map.emplace(std::make_pair(hashedName, fillResourceStructFromTuple<Uniform>(uniformIndex, hashedName, parameters)));
    ASSERT_MSG(inserted.second, "Uniform collision in ShaderProgram uniform map.");
    inserted.first->second.mName = name;

    return inserted.first->second;
}

const shader::Sampler& shader::ShaderProgramResourceFactory::emplaceSamplerInMap(GLuint programHandle, GLuint uniformIndex, GLint textureImageUnit, std::unordered_map<std::uint64_t, Sampler>& map) {
    LOG_TRC() << "Filling shader program sampler..."<< LOG_END;

    const GLenum programInterface = GL_UNIFORM;
    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Check that the uniform is a sampler.
    ASSERT_MSG(getUniformType(programHandle, uniformIndex) == SAMPLER, "Uniform is not a sampler.");

    // Retrieve the uniform name from OpenGL and hash it
    auto name = getName(programHandle, programInterface, uniformIndex);
    auto hashedName = hash(name.c_str(), name.size());

    // Retrieve the sampler parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Uniform::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, uniformIndex, Uniform::mscProperties);

    // Set variables in the output Sampler.
    auto inserted = map.emplace(std::make_pair(hashedName, fillResourceStructFromTuple<Sampler>(uniformIndex, hashedName, parameters)));
    ASSERT_MSG(inserted.second, "Sampler collision in ShaderProgram sampler map.");
    inserted.first->second.mUniform.mName = name;
    inserted.first->second.mTextureImageUnit = textureImageUnit;
    inserted.first->second.mGlTextureImageUnit = Sampler::textureImageUnitToGlTextureImageUnit(inserted.first->second.mTextureImageUnit);

    return inserted.first->second;
}

const shader::Image& shader::ShaderProgramResourceFactory::emplaceImageInMap(GLuint programHandle, GLuint uniformIndex, GLint imageUnit, GLint imageFormat, std::unordered_map<std::uint64_t, Image>& map) {
    LOG_TRC() << "Filling shader program image..."<< LOG_END;

    const GLenum programInterface = GL_UNIFORM;
    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Check that the uniform is an image.
    ASSERT_MSG(getUniformType(programHandle, uniformIndex) == IMAGE, "Uniform is not an image.");

    // Retrieve the uniform name from OpenGL and hash it
    auto name = getName(programHandle, programInterface, uniformIndex);
    auto hashedName = hash(name.c_str(), name.size());

    // Retrieve the image parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Uniform::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, uniformIndex, Uniform::mscProperties);

    // Set variables in the output Image.
    auto inserted = map.emplace(std::make_pair(hashedName, fillResourceStructFromTuple<Image>(uniformIndex, hashedName, parameters)));
    ASSERT_MSG(inserted.second, "Image collision in ShaderProgram image map.");
    inserted.first->second.mUniform.mName = name;
    inserted.first->second.mImageUnit = imageUnit;
    inserted.first->second.mFormat = imageFormat;

    return inserted.first->second;
}

const shader::ShaderBlock& shader::ShaderProgramResourceFactory::emplaceShaderBlockInMap(GLuint programHandle, GLuint blockProgramInterface, GLuint blockIndex, std::unordered_map<std::uint64_t, ShaderBlock>& map) {
    LOG_TRC() << "Filling shader program block..."<< LOG_END;

    ASSERT_MSG(isValidIndex(programHandle, blockProgramInterface, blockIndex), "Block index not valid.");

    // Find the correct program interface for this block's variables.
    const int variableProgramInterface = getBlockVariableProgramInterface(blockProgramInterface);

    // Retrieve the block name from OpenGL and hash it
    auto name = getName(programHandle, blockProgramInterface, blockIndex);
    auto hashedName = hash(name.c_str(), name.size());

    // Check that the number of active variables is less than max allowed
    const auto numActiveVariables = static_cast<GLsizei>(getParameter(programHandle, blockProgramInterface, blockIndex, GL_NUM_ACTIVE_VARIABLES));

    // Retrieve the block parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(ShaderBlock::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, blockProgramInterface, blockIndex, ShaderBlock::mscProperties);

    // Set variables in the output ShaderBlock.
    auto inserted = map.emplace(std::make_pair(hashedName, fillResourceStructFromTuple<ShaderBlock>(blockIndex, hashedName, parameters)));
    ASSERT_MSG(inserted.second, "ShaderBlock collision in ShaderProgram shader block map.");
    inserted.first->second.mName = name;

    // Find and fill the block's active variables indices, names and offsets
    const auto activeVariablesIndices = getParameters(programHandle, blockProgramInterface, blockIndex, GL_ACTIVE_VARIABLES, numActiveVariables);
    for (int i = 0; i < numActiveVariables; i++) {
        auto activeVariableName = getName(programHandle, variableProgramInterface, activeVariablesIndices[i]);
        static_cast<void>(
            inserted.first->second.mActiveVariables.emplace_back(
                activeVariablesIndices[i],
                hash(activeVariableName.c_str(), activeVariableName.size()),
                getParameter(programHandle, variableProgramInterface, activeVariablesIndices[i], GL_OFFSET),
                activeVariableName
            )
        );
    }

    return inserted.first->second;
}

bool shader::ShaderProgramResourceFactory::isUniformIndexAUniformBlockVariable(GLuint programHandle, GLuint uniformIndex) {
    const GLuint programInterface = GL_UNIFORM;
    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Uniforms within blocks get assigned a location of -1. Return true if this is the case
    return getParameter(programHandle, programInterface, uniformIndex, GL_LOCATION) == -1;
}

shader::UniformType shader::ShaderProgramResourceFactory::getUniformType(GLuint programHandle, GLuint uniformIndex) {
    ASSERT_MSG(isValidIndex(programHandle, GL_UNIFORM, uniformIndex), "Uniform index not valid.");

    GLint glType = getParameter(programHandle, GL_UNIFORM, uniformIndex, GL_TYPE);

    if (Sampler::glTypeIsSampler(glType)) {
        return SAMPLER;
    }

    if (Image::glTypeIsImage(glType)) {
        return IMAGE;
    }

    if (Uniform::glTypeIsUniform(glType)) {
        return UNIFORM;
    }

    ASSERT_MSG(false, "Unknown uniform type!");
    return UNIFORM;
}

bool shader::ShaderProgramResourceFactory::isValidIndex(GLuint programHandle, GLenum programInterface, GLuint index) {
    GLint activeResources = 0;
    glGetProgramInterfaceiv(programHandle, programInterface, GL_ACTIVE_RESOURCES, &activeResources);
    ASSERT_GL();

    return index >= 0 && index < activeResources;
}

GLint shader::ShaderProgramResourceFactory::getParameter(GLuint programHandle, GLenum programInterface, GLuint index, GLenum property) {
    GLint parameter = -1;

    GLsizei length = 0;
    glGetProgramResourceiv(programHandle, programInterface, index, 1, &property, 1, &length, &parameter);
    ASSERT_GL();
    ASSERT_MSG(length == 1, "Returned number of parameters does not equal 1. Did you mean getBlockParameters?");

    return parameter;
}

std::vector<GLint> shader::ShaderProgramResourceFactory::getParameters(GLuint programHandle, GLenum programInterface, GLuint index, GLenum property, GLsizei numParametersOut) {
    std::vector<GLint> parameters(numParametersOut);

    GLsizei length = 0;
    glGetProgramResourceiv(programHandle, programInterface, index, 1, &property, 1, &length, parameters.data());
    ASSERT_GL();
    ASSERT_MSG(length == numParametersOut, "Returned number of parameters does not equal output size.");

    return parameters;
}

template<GLsizei size>
std::vector<GLint> shader::ShaderProgramResourceFactory::getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const std::array<GLenum, size>& properties, GLsizei numParametersOut) {
    std::vector<GLint> parameters(numParametersOut);

    GLsizei length = 0;
    glGetProgramResourceiv(programHandle, programInterface, index, size, properties.data(), size, &length, parameters.data());
    ASSERT_GL();
    ASSERT_MSG(length == numParametersOut, "Returned number of parameters does not equal output size.");

    return parameters;
}

template<GLsizei size>
std::array<GLint, size> shader::ShaderProgramResourceFactory::getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const std::array<GLenum, size>& properties) {
    std::array<GLint, size> parameters{};

    GLsizei length = 0;
    glGetProgramResourceiv(programHandle, programInterface, index, size, properties.data(), size, &length, parameters.data());
    ASSERT_GL();
    ASSERT_MSG(length == size, "Returned number of parameters does not equal output size.");

    return parameters;
}

std::string shader::ShaderProgramResourceFactory::getName(GLuint programHandle, GLenum programInterface, GLuint index) {
    GLint maxNameLength = 0;
    glGetProgramInterfaceiv(programHandle, programInterface, GL_MAX_NAME_LENGTH, &maxNameLength);
    ASSERT_GL();

    std::unique_ptr<GLchar> name(new GLchar[maxNameLength]);
    GLsizei length = 0;
    glGetProgramResourceName(programHandle, programInterface, index, maxNameLength, &length, name.get());
    ASSERT_GL();

    return std::string(name.get());
}

GLint shader::ShaderProgramResourceFactory::getBlockVariableProgramInterface(GLuint blockProgramInterface) {
    switch (blockProgramInterface) {
        case GL_UNIFORM_BLOCK:
            return GL_UNIFORM;
        case GL_SHADER_STORAGE_BLOCK:
            return GL_BUFFER_VARIABLE;
        default:
            ASSERT_MSG(false, "Unknown block program interface!");
            return GL_UNIFORM;
    }
}

template<class T, class Tuple>
constexpr T shader::ShaderProgramResourceFactory::fillResourceStructFromTuple(GLuint index, std::uint64_t hashedName, Tuple&& t) {
    return std::apply([index, hashedName](auto&&... args){return T{index, hashedName, decltype(args)(args)...};}, std::forward<Tuple>(t));
}