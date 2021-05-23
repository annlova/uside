//
// Created by anton on 2021-05-23.
//

#include "../h/shader_program.h"

//#include <logs/include/log_include.h>
//#include <assertion/include/assertion_include.h>

shader::ShaderProgram::~ShaderProgram() {
    glDeleteProgram(mHandle);
//    ASSERT_GL();

//    LOG_TRC() << "ShaderProgram (" << mHandle << ") destructed." << LOG_END;
}

const shader::Attribute& shader::ShaderProgram::getAttribute(std::uint64_t hashedName) {
//    ASSERT_MSG(mAttributes.find(hashedName) != mAttributes.end(), "No attribute with that hashed name.");
    return mAttributes[hashedName];
}

const shader::Image &shader::ShaderProgram::getImage(std::uint64_t hashedName) {
//    ASSERT_MSG(mImages.find(hashedName) != mImages.end(), "No image uniform with that hashed name.");
    return mImages[hashedName];
}

const shader::Sampler &shader::ShaderProgram::getSampler(std::uint64_t hashedName) {
//    ASSERT_MSG(mSamplers.find(hashedName) != mSamplers.end(), "No sampler uniform with that hashed name.");
    return mSamplers[hashedName];
}

const shader::ShaderBlock &shader::ShaderProgram::getShaderStorageBlock(std::uint64_t hashedName) {
//    ASSERT_MSG(mShaderStorageBlocks.find(hashedName) != mShaderStorageBlocks.end(), "No shader storage block with that hashed name.");
    return mShaderStorageBlocks[hashedName];
}

const shader::ShaderBlock &shader::ShaderProgram::getUniformBlock(std::uint64_t hashedName) {
//    ASSERT_MSG(mUniformBlocks.find(hashedName) != mUniformBlocks.end(), "No uniform block with that hashed name.");
    return mUniformBlocks[hashedName];
}

const shader::Uniform &shader::ShaderProgram::getUniform(std::uint64_t hashedName) {
//    ASSERT_MSG(mUniforms.find(hashedName) != mUniforms.end(), "No uniform with that hashed name.");
    return mUniforms[hashedName];
}
