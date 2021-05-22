//
// Created by Anton on 2021-05-22.
//

#ifndef USIDE_SRC_CONFIGS_FRAMEBUFFER_CONFIG_H
#define USIDE_SRC_CONFIGS_FRAMEBUFFER_CONFIG_H

#include <climits>

#include <glad/glad.h>

namespace framebuffer {
    constexpr int gcDefaultWidth = 600;
    constexpr int gcDefaultHeight = 800;

    inline constexpr int gcMinFramebufferColorAttachments = 8; // OpenGL guarantees at least 8 color attachment points available

    // Framebuffer variables initial values (set according to OpenGL initial values).
    inline constexpr GLenum gcInitialBindTarget = GL_FRAMEBUFFER;

    // Color variables initial values
    inline constexpr GLfloat gcInitialRed = 0.0F;
    inline constexpr GLfloat gcInitialGreen = 0.0F;
    inline constexpr GLfloat gcInitialBlue = 0.0F;
    inline constexpr GLfloat gcInitialAlpha = 0.0F;

    // Depth variables initial values
    inline constexpr bool gcInitialDepthTestingEnabled = false;
    inline constexpr GLfloat gcInitialClearDepth = 1.0F;
    inline constexpr GLenum gcInitialDepthFunction = GL_LESS;
    inline constexpr GLboolean gcInitialDepthMask = GL_TRUE;
    inline constexpr GLfloat gcInitialDepthRangeNear = 0.0F;
    inline constexpr GLfloat gcInitialDepthRangeFar = 1.0F;

    // Stencil variables initial values
    inline constexpr bool gcInitialStencilTestingEnabled = false;
    inline constexpr GLint gcInitialClearStencil = 0;
    inline constexpr GLenum gcInitialStencilFunctionFunc = GL_ALWAYS;
    inline constexpr GLint gcInitialStencilFunctionRef = 0;
    inline constexpr GLuint gcInitialStencilFunctionMask = UINT_MAX;
    inline constexpr GLuint gcInitialStencilMask = UINT_MAX;
    inline constexpr GLenum gcInitialStencilOpSFail = GL_KEEP;
    inline constexpr GLenum gcInitialStencilOpDpFail = GL_KEEP;
    inline constexpr GLenum gcInitialStencilOpDpPass = GL_KEEP;

    // Culling variables initial values
    inline constexpr bool gcInitialCullingEnabled = false;
    inline constexpr GLenum gcInitialFrontFace = GL_CCW;
    inline constexpr GLenum gcInitialCullFace = GL_BACK;
}
#endif //USIDE_SRC_CONFIGS_FRAMEBUFFER_CONFIG_H
