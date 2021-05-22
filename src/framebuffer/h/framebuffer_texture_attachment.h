//
// Created by Anton on 2021-05-22.
//

#ifndef USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_TEXTURE_ATTACHMENT_H
#define USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_TEXTURE_ATTACHMENT_H

#include <glad/glad.h>

#include <texture/include/texture_include.h>
namespace framebuffer {
    enum FramebufferTextureAttachmentType {
        COLOR,
        DEPTH,
        STENCIL,
        DEPTH_STENCIL
    };

    struct FramebufferTextureAttachment {
        /// The type of framebuffer texture attachment (color, depth, stencil, or depth&stencil).
        FramebufferTextureAttachmentType mAttachmentType;
        /// Shared pointer to the actual texture object.
        texture::Texture* mTexture;
        /// See OpenGL documentation (specifically framebuffer objects and glNamedFramebufferTextureLayer).
        GLint mLayer;
        /// See OpenGL documentation (specifically framebuffer objects and glNamedFramebufferTextureLayer).
        GLint mLevel;
    };
}
#endif //USIDE_SRC_FRAMEBUFFER_H_FRAMEBUFFER_TEXTURE_ATTACHMENT_H
