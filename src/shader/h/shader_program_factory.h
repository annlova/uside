//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_SHADER_PROGRAM_FACTORY_H
#define USIDE_SRC_SHADER_H_SHADER_PROGRAM_FACTORY_H

#include <glad/glad.h>

#include "shader_program.h"

namespace shader {
    class ShaderProgramFactory {
        public:
            static void createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource, const char* tessellationControlShaderSource, const char* tessellationEvaluationShaderSource, const char* geometryShaderSource, ShaderProgram& out);
            static void createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource, ShaderProgram& out);
            static void createShaderProgram(const char* computeShaderSource, ShaderProgram& out);

        private:
            static void createShaderProgram(GLuint programHandle, ShaderProgram& out);

        private:
            static void fillShaderProgramAttributes(GLuint programHandle, ShaderProgram& out);
            static void fillShaderProgramUniforms(GLuint programHandle, ShaderProgram& out);
            static void fillShaderProgramPureUniform(GLuint programHandle, GLuint uniformIndex, shader::ShaderProgram& out);
            static void fillShaderProgramSampler(GLuint programHandle, GLuint uniformIndex, GLint textureImageUnit, shader::ShaderProgram& out);
            static void fillShaderProgramImage(GLuint programHandle, GLuint uniformIndex, GLint imageUnit, GLint imageFormat, shader::ShaderProgram& out);
            static void fillShaderProgramUniformBlocks(GLuint programHandle, ShaderProgram& out);
            static void fillShaderProgramShaderStorageBlocks(GLuint programHandle, ShaderProgram& out);

        private:
            static GLuint createShader(const GLchar* source, GLenum type);
            static GLuint createProgram();
            static void attachShader(GLuint programHandle, GLuint shaderHandle);
            static void linkProgram(GLuint programHandle);
            static void detachAndDeleteShaders(GLuint programHandle);

        public:
            static GLint getActiveResourceAmount(GLuint programHandle, GLenum programInterface);
            static bool typeIsShaderType(GLenum type);
    };
}

#endif //USIDE_SRC_SHADER_H_SHADER_PROGRAM_FACTORY_H
