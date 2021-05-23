//
// Created by anton on 2021-05-23.
//

#include "../h/shader_program_resource_factory.h"

//#include <logs/include/log_include.h>
//#include <assertion/include/assertion_include.h>
//#include <string/include/string_hash_include.h>

void shader::ShaderProgramResourceFactory::fillAttribute(GLuint programHandle, GLuint attributeIndex, shader::Attribute &attribute) {
//    LOG_TRC() << "Filling shader program attribute..."<< LOG_END;

    const GLenum programInterface = GL_PROGRAM_INPUT;
//    ASSERT_MSG(isValidIndex(programHandle, programInterface, attributeIndex), "Attribute index not valid.");

    // Retrieve the attribute name and hash it
    std::uint64_t hashedName = getHashedName(programHandle, programInterface, attributeIndex);

    // Retrieve the attribute parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Attribute::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, attributeIndex, Attribute::mscProperties);

    // Set variables in the output Attribute.
    attribute = fillResourceStructFromTuple<Attribute>(attributeIndex, hashedName, parameters);
}

void shader::ShaderProgramResourceFactory::fillUniform(GLuint programHandle, GLuint uniformIndex, shader::Uniform &uniform) {
//    LOG_TRC() << "Filling shader program uniform..."<< LOG_END;

    const GLenum programInterface = GL_UNIFORM;
//    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Check that the uniform is a pure uniform, not a sampler or image.
//    ASSERT_MSG(getUniformType(programHandle, uniformIndex) == UNIFORM, "Uniform is not a pure uniform.");

    // Retrieve the uniform name and hash it
    std::uint64_t hashedName = getHashedName(programHandle, programInterface, uniformIndex);

    // Retrieve the uniform parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Uniform::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, uniformIndex, Uniform::mscProperties);

    // Set variables in the output Uniform.
    uniform = fillResourceStructFromTuple<Uniform>(uniformIndex, hashedName, parameters);
}

void shader::ShaderProgramResourceFactory::fillSampler(GLuint programHandle, GLuint uniformIndex, GLint textureImageUnit, shader::Sampler &sampler) {
//    LOG_TRC() << "Filling shader program sampler..."<< LOG_END;

    const GLenum programInterface = GL_UNIFORM;
//    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Check that the uniform is a sampler.
//    ASSERT_MSG(getUniformType(programHandle, uniformIndex) == SAMPLER, "Uniform is not a sampler.");

    // Retrieve the uniform name from OpenGL and hash it
    std::uint64_t hashedName = getHashedName(programHandle, programInterface, uniformIndex);

    // Retrieve the sampler parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Uniform::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, uniformIndex, Uniform::mscProperties);

    // Set variables in the output Sampler.
    sampler = fillResourceStructFromTuple<Sampler>(uniformIndex, hashedName, parameters);
    sampler.mTextureImageUnit = textureImageUnit;
    sampler.mGlTextureImageUnit = Sampler::textureImageUnitToGlTextureImageUnit(sampler.mTextureImageUnit);
}

void shader::ShaderProgramResourceFactory::fillImage(GLuint programHandle, GLuint uniformIndex, GLint imageUnit, GLint imageFormat, shader::Image &image) {
//    LOG_TRC() << "Filling shader program image..."<< LOG_END;

    const GLenum programInterface = GL_UNIFORM;
//    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Check that the uniform is an image.
//    ASSERT_MSG(getUniformType(programHandle, uniformIndex) == IMAGE, "Uniform is not an image.");

    // Retrieve the uniform name from OpenGL and hash it
    std::uint64_t hashedName = getHashedName(programHandle, programInterface, uniformIndex);

    // Retrieve the image parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(Uniform::mscProperties.size());
    const auto parameters = getParameters<numProperties>(programHandle, programInterface, uniformIndex, Uniform::mscProperties);

    // Set variables in the output Image.
    image = fillResourceStructFromTuple<Image>(uniformIndex, hashedName, parameters);
    image.mImageUnit = imageUnit;
    image.mFormat = imageFormat;
}

void shader::ShaderProgramResourceFactory::fillShaderBlock(GLuint programHandle, GLuint blockProgramInterface, GLuint blockIndex, shader::ShaderBlock &shaderBlock) {
//    LOG_TRC() << "Filling shader program block..."<< LOG_END;

//    ASSERT_MSG(isValidIndex(programHandle, blockProgramInterface, blockIndex), "Block index not valid.");

    // Find the correct program interface for this block's variables.
    const int variableProgramInterface = getBlockVariableProgramInterface(blockProgramInterface);

    // Retrieve the block name from OpenGL and hash it
    std::uint64_t hashedName = getHashedName(programHandle, blockProgramInterface, blockIndex);

    // Check that the number of active variables is less than max allowed
    const auto numActiveVariables = static_cast<GLsizei>(getParameter(programHandle, blockProgramInterface, blockIndex, GL_NUM_ACTIVE_VARIABLES));

    // Retrieve the block parameters from OpenGL
    const auto numProperties = static_cast<GLsizei>(ShaderBlock::mscProperties.size());
    const GLsizei numParameters = numProperties;
    const auto parameters = getParameters<numProperties>(programHandle, blockProgramInterface, blockIndex, ShaderBlock::mscProperties, numParameters);

    // Set variables in the output ShaderBlock.
    shaderBlock = fillResourceStructFromTuple<ShaderBlock>(blockIndex, hashedName, parameters);

    // Find and fill the block's active variables indices, names and offsets
    const auto activeVariablesIndices = getParameters(programHandle, blockProgramInterface, blockIndex, GL_ACTIVE_VARIABLES, numActiveVariables);
    for (int i = 0; i < numActiveVariables; i++) {
        shaderBlock.mActiveVariables.emplace_back(
            activeVariablesIndices[i],
            getHashedName(programHandle, variableProgramInterface, activeVariablesIndices[i]),
            getParameter(programHandle, variableProgramInterface, activeVariablesIndices[i], GL_OFFSET)
        );
    }
}

bool shader::ShaderProgramResourceFactory::isUniformIndexAUniformBlockVariable(GLuint programHandle, GLuint uniformIndex) {
    const GLuint programInterface = GL_UNIFORM;
//    ASSERT_MSG(isValidIndex(programHandle, programInterface, uniformIndex), "Uniform index not valid.");

    // Uniforms within blocks get assigned a location of -1. Return true if this is the case
    return getParameter(programHandle, programInterface, uniformIndex, GL_LOCATION) == -1;
}

shader::UniformType shader::ShaderProgramResourceFactory::getUniformType(GLuint programHandle, GLuint uniformIndex) {
//    ASSERT_MSG(isValidIndex(programHandle, GL_UNIFORM, uniformIndex), "Uniform index not valid.");

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

//    ASSERT_MSG(false, "Unknown uniform type!");
    return UNIFORM;
}

bool shader::ShaderProgramResourceFactory::isValidIndex(GLuint programHandle, GLenum programInterface, GLuint index) {
    GLint activeResources = 0;
    glGetProgramInterfaceiv(programHandle, programInterface, GL_ACTIVE_RESOURCES, &activeResources);
//    ASSERT_GL();

    return index >= 0 && index < activeResources;
}

GLint shader::ShaderProgramResourceFactory::getParameter(GLuint programHandle, GLenum programInterface, GLuint index, GLenum property) {
    GLint parameter = -1;

    GLsizei length;
    glGetProgramResourceiv(programHandle, programInterface, index, 1, &property, 1, &length, &parameter);
//    ASSERT_GL();
//    ASSERT_MSG(length == 1, "Returned number of parameters does not equal 1. Did you mean getBlockParameters?");

    return parameter;
}

std::vector<GLint> shader::ShaderProgramResourceFactory::getParameters(GLuint programHandle, GLenum programInterface, GLuint index, GLenum property, GLsizei numParametersOut) {
    std::vector<GLint> parameters(numParametersOut);

    GLsizei length;
    glGetProgramResourceiv(programHandle, programInterface, index, 1, &property, 1, &length, parameters.data());
//    ASSERT_GL();
//    ASSERT_MSG(length == numParametersOut, "Returned number of parameters does not equal output size.");

    return parameters;
}

template<GLsizei size>
std::vector<GLint> shader::ShaderProgramResourceFactory::getParameters(GLuint programHandle, GLenum programInterface, GLuint index, const std::array<GLenum, size>& properties, GLsizei numParametersOut) {
    std::vector<GLint> parameters(numParametersOut);

    GLsizei length;
    glGetProgramResourceiv(programHandle, programInterface, index, size, properties.data(), size, &length, parameters.data());
//    ASSERT_GL();
//    ASSERT_MSG(length == numParametersOut, "Returned number of parameters does not equal output size.");

    return parameters;
}

std::uint64_t shader::ShaderProgramResourceFactory::getHashedName(GLuint programHandle, GLenum programInterface, GLuint index) {
    GLint maxNameLength = 0;
    glGetProgramInterfaceiv(programHandle, programInterface, GL_MAX_NAME_LENGTH, &maxNameLength);
//    ASSERT_GL();

    std::unique_ptr<GLchar> name(new GLchar[maxNameLength]);
    GLsizei length = 0;

    glGetProgramResourceName(programHandle, programInterface, index, maxNameLength, &length, name.get());
//    ASSERT_GL();

    return 0;
//    return hash(name.get(), length);
}

GLint shader::ShaderProgramResourceFactory::getBlockVariableProgramInterface(GLuint blockProgramInterface) {
    switch (blockProgramInterface) {
        case GL_UNIFORM_BLOCK:
            return GL_UNIFORM;
        case GL_SHADER_STORAGE_BLOCK:
            return GL_BUFFER_VARIABLE;
        default:
//            ASSERT_MSG(false, "Unknown block program interface!");
            return GL_UNIFORM;
    }
}

template<class T, class Tuple, size_t... I>
constexpr T shader::ShaderProgramResourceFactory::fillResourceStructFromTupleImpl(GLuint index, std::uint64_t hashedName, Tuple &&t, std::index_sequence<I...>) {
    return T{index, hashedName, std::get<I>(std::forward<Tuple>(t))...};
}

template<class T, class Tuple>
constexpr T shader::ShaderProgramResourceFactory::fillResourceStructFromTuple(GLuint index, std::uint64_t hashedName, Tuple &&t) {
    return fillResourceStructFromTupleImpl<T>(index, hashedName, std::forward<Tuple>(t), std::make_index_sequence<std::tuple_size<std::remove_reference_t<Tuple>>::value>{});
}
