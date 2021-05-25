//
// Created by Anton on 2021-05-22.
//

#ifndef USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_H
#define USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_H

#include <vector>
#include <climits>

#include "framebuffer_texture_attachment.h"
#include "framebuffer_info.h"

/**
 * @file framebuffer.h
 * @fn bindOnly
 * comment
 */
namespace framebuffer {
    class Framebuffer {
    public:
        /// Constructs the DEFAULT framebuffer, i.e. handle = 0.
        Framebuffer(const GLsizei width, const GLsizei height);

        // Constructs a new framebuffer
        Framebuffer(const GLsizei width, const GLsizei height, std::initializer_list<FramebufferTextureAttachment> textureAttachments);

        // Destructor
        ~Framebuffer();

    private:
        void configureToOnBindInfo();
        void bindOnly() const;

    public:
        void bind(GLint x, GLint y, GLsizei width, GLsizei height);
        void bind(GLsizei width, GLsizei height);
        void bind();
        void markUnbound();

    public:
        void clear(bool color, bool depth = false, bool stencil = false) const;

    public: // Current state modifiers
        void modifyViewport(GLint x, GLint y, GLsizei width, GLsizei height);
        void modifyViewport(GLsizei width, GLsizei height);

        void modifyClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

        void modifyDepthTestingEnabled(bool depthTestingEnabled);
        void modifyClearDepth(GLfloat clearDepth);
        void modifyDepthFunction(GLenum depthFunction);
        void modifyDepthMask(GLboolean depthMask);
        void modifyDepthRange(GLfloat depthRangeNear, GLfloat depthRangeFar);

        void modifyStencilTestingEnabled(bool stencilTestingEnabled);
        void modifyClearStencil(GLint clearStencil);
        void modifyStencilFunction(GLenum func, GLint ref, GLuint mask);
        void modifyStencilMask(GLuint stencilMask);
        void modifyStencilOperation(GLenum sFail, GLenum dpFail, GLenum dpPass);

        void modifyCullingEnabled(bool cullingEnabled);
        void modifyFrontFace(GLenum frontFace);
        void modifyCullFace(GLenum cullFace);

    public: // State checks
        bool isBound() const;
        bool isComplete(bool assert = false) const;

    public: // Getters and Setters
        GLfloat getBindRed() const;
        GLfloat getBindGreen() const;
        GLfloat getBindBlue() const;
        GLfloat getBindAlpha() const;

        void setBindRed(GLfloat red);
        void setBindGreen(GLfloat green);
        void setBindBlue(GLfloat blue);
        void setBindAlpha(GLfloat alpha);

        void setBindClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

        FramebufferInfo getBindInfo() const;
        FramebufferInfo getInfo() const;
        void setBindInfo(FramebufferInfo info);

    private:
        void attachTexture(const FramebufferTextureAttachment& textureAttachment);
        // TODO: Renderbuffer attachments

        GLint getNumBitPlanesInStencilBuffer() const;

        template <class T>
        static std::pair<T, bool> clamp(T value, T min, T max);

        GLenum addTextureAttachment(const FramebufferTextureAttachment& attachment);
        GLenum setDepthTextureAttachment(const FramebufferTextureAttachment& attachment);
        GLenum setStencilTextureAttachment(const FramebufferTextureAttachment& attachment);
        GLenum setColorTextureAttachment(const FramebufferTextureAttachment& attachment);

        static bool isValidFramebufferTarget(GLenum target);
        static bool isValidDepthFunction(GLenum func);
        static bool isValidStencilFunctionFunc(GLenum func);
        static bool isValidStencilOperation(GLenum op);
        static bool isValidFrontFace(GLenum frontFace);
        static bool isValidCullFace(GLenum cullFace);

        static bool isValidInternalColorTextureFormat(GLint format);
        static bool isValidInternalDepthTextureFormat(GLint format);
        static bool isValidInternalStencilTextureFormat(GLint format);
        static bool isValidInternalDepthStencilTextureFormat(GLint format);

    private:
        /// The latest bound framebuffer.
        static GLuint msBoundHandle;

        /// Value indicating that no framebuffer is currently bound (even though technically this is not possible).
        static constexpr GLuint mscBoundHandleUnboundValue = UINT_MAX;

        /// OpenGL handle.
        GLuint mHandle;

        /// Current target (GL_FRAMEBUFFER, GL_FRAMEBUFFER_DRAW, or GL_FRAMEBUFFER_READ).
        GLenum mTarget;

        // Attachments
        std::vector<FramebufferTextureAttachment> mColorTextureAttachments;
        FramebufferTextureAttachment mDepthTextureAttachment;
        bool mDepthIndexFilled;
        FramebufferTextureAttachment mStencilTextureAttachment;
        bool mStencilIndexFilled;

        /// Bind settings
        FramebufferInfo mBindInfo;

        /// Current settings
        FramebufferInfo mInfo;
    };
}
#endif //USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_H
