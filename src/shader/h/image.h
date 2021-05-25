//
// Created by anton on 2021-05-23.
//

#ifndef USIDE_SRC_SHADER_H_IMAGE_H
#define USIDE_SRC_SHADER_H_IMAGE_H

#include <glad/glad.h>

#include "uniform.h"

namespace shader {
    struct Image {
        Uniform mUniform;
        GLint mImageUnit;
        GLint mFormat;

        /**
         * Checks if given type is an image type.
         * @param type - Gl type constant to check.
         * @return True if given type is an image type.
         */
        static bool glTypeIsImage(GLint glType);
    };
}

#endif //USIDE_SRC_SHADER_H_IMAGE_H
