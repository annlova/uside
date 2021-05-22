//
// Created by Anton on 2021-05-22.
//

#ifndef USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_INFO_H
#define USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_INFO_H

#include <glad/glad.h>

/**
 * @class Framebuffer
 * Sometings...
 */

namespace framebuffer {
    struct FramebufferInfo {
        // Viewport variables
        GLint mViewportX;
        GLint mViewportY;
        GLsizei mViewportWidth;
        GLsizei mViewportHeight;

        // Clear color variables
        GLfloat mRed;
        GLfloat mGreen;
        GLfloat mBlue;
        GLfloat mAlpha;

        // Depth variables
        bool mDepthTestingEnabled;
        GLfloat mClearDepth;
        GLenum mDepthFunction;
        GLboolean mDepthMask;
        GLfloat mDepthRangeNear;
        GLfloat mDepthRangeFar;

        // Stencil variables
        bool mStencilTestingEnabled;
        GLint mClearStencil;
        GLenum mStencilFunctionFunc;
        GLint mStencilFunctionRef;
        GLuint mStencilFunctionMask;
        GLuint mStencilMask;
        GLenum mStencilOpSFail;
        GLenum mStencilOpDpFail;
        GLenum mStencilOpDpPass;

        // Culling variables
        bool mCullingEnabled;
        GLenum mFrontFace;
        GLenum mCullFace;
    };
}
#endif //USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_INFO_H
