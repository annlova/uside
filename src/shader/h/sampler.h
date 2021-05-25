//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_SAMPLER_H
#define USIDE_SRC_SHADER_H_SAMPLER_H

#include <glad/glad.h>

#include "uniform.h"

namespace shader {
    struct Sampler {
        Uniform mUniform;
        GLint mTextureImageUnit;
        GLint mGlTextureImageUnit;

        /**
         * Converts texture image unit in integer form to GL constant GL_TEXTUREX.
         * @param textureImageUnit - Integer 0 - 31.
         * @return GL constant version of texture image unit.
         */
        static GLint textureImageUnitToGlTextureImageUnit(GLint textureImageUnit);

        /**
         * Checks if given glType is a sampler glType.
         * @param glType - GL glType constant to check.
         * @return True if given glType is a sampler glType.
         */
        static bool glTypeIsSampler(GLint glType);
    };
}
#endif //USIDE_SRC_SHADER_H_SAMPLER_H
