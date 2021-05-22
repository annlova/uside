//
// Created by Anton on 2021-05-22.
//

#ifndef USIDE_SRC_TEXTURE_H_TEXTURE_H
#define USIDE_SRC_TEXTURE_H_TEXTURE_H

#include <glad/glad.h>

#include <log/include/log_include.h>
#include <assertion/include/assertion_include.h>

namespace texture {
    struct Texture {
        /** The handle for the OpenGL texture object. */
        GLuint mHandle; // NOLINT(clion-misra-cpp2008-11-0-1)

        /** The texture objects target (e.g. GL_TEXTURE_2D, etc.). */
        GLenum mTarget; // NOLINT(clion-misra-cpp2008-11-0-1)

        /** The OpenGL internal format (i.e. the one defined in the shader). */
        GLint mInternalFormat; // NOLINT(clion-misra-cpp2008-11-0-1)

        Texture() = default;
        Texture(const Texture& texture) = delete;
        Texture(Texture&& texture) = default;
        ~Texture() {
            glDeleteTextures(1, &mHandle);
            ASSERT_GL();
            LOG_TRC() << "Texture (" << mHandle << ") destructed." << LOG_END;
        }

        Texture& operator=(const Texture& in) = delete;
        Texture& operator=(Texture&& in) = default;
    };
}
#endif //USIDE_SRC_TEXTURE_H_TEXTURE_H