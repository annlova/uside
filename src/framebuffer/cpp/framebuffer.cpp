//
// Created by Anton on 2021-05-22.
//

#include "../h/framebuffer.h"

#include <climits>

#include <configs/framebuffer_config.h>
#include <log/include/log_include.h>
#include <assertion/include/assertion_include.h>
#include <globals/debug_code_maco.h>

GLuint framebuffer::Framebuffer::msBoundHandle = UINT_MAX; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

framebuffer::Framebuffer::Framebuffer(const GLsizei width, const GLsizei height)
    : mHandle{0},
      mTarget{gcInitialBindTarget},
      mColorTextureAttachments{},
      mDepthTextureAttachment{},
      mDepthIndexFilled{false},
      mStencilTextureAttachment{},
      mStencilIndexFilled{false},
      mBindInfo{
        0,
        0,
        width,
        height,
        gcInitialRed,
        gcInitialGreen,
        gcInitialBlue,
        gcInitialAlpha,
        gcInitialDepthTestingEnabled,
        gcInitialClearDepth,
        gcInitialDepthFunction,
        gcInitialDepthMask,
        gcInitialDepthRangeNear,
        gcInitialDepthRangeFar,
        gcInitialStencilTestingEnabled,
        gcInitialClearStencil,
        gcInitialStencilFunctionFunc,
        gcInitialStencilFunctionRef,
        gcInitialStencilFunctionMask,
        gcInitialStencilMask,
        gcInitialStencilOpSFail,
        gcInitialStencilOpDpFail,
        gcInitialStencilOpDpPass,
        gcInitialCullingEnabled,
        gcInitialFrontFace,
        gcInitialCullFace
      },
      mInfo{}
      {
          LOG_TRC() << "Default framebuffer constructed." << LOG_END;
}

framebuffer::Framebuffer::Framebuffer(const GLsizei width, const GLsizei height, std::initializer_list<FramebufferTextureAttachment> textureAttachments)
    : Framebuffer(width, height) {
    // Generate handle
    glGenFramebuffers(1, &mHandle);
    ASSERT_GL();

    glBindFramebuffer(mTarget, mHandle);
    ASSERT_GL();

    // Attach texture attachments
    for (auto& attachment: textureAttachments) {
        attachTexture(attachment);
    }

    static_cast<void>(isComplete(true));

    LOG_TRC() << "Framebuffer constructed." << LOG_END;
}

framebuffer::Framebuffer::~Framebuffer() {
    glDeleteFramebuffers(1, &mHandle);
    ASSERT_GL();

    LOG_TRC() << "Framebuffer (" << mHandle << ") destructed." << LOG_END;
}

void framebuffer::Framebuffer::configureToOnBindInfo() {
    // Set to on-bind configuration
    modifyClearColor(mBindInfo.mRed, mBindInfo.mGreen, mBindInfo.mBlue, mBindInfo.mAlpha);

    modifyDepthTestingEnabled(mBindInfo.mDepthTestingEnabled);
    modifyClearDepth(mBindInfo.mClearDepth);
    modifyDepthFunction(mBindInfo.mDepthFunction);
    modifyDepthMask(mBindInfo.mDepthMask);
    modifyDepthRange(mBindInfo.mDepthRangeNear, mBindInfo.mDepthRangeFar);

    modifyStencilTestingEnabled(mBindInfo.mStencilTestingEnabled);
    modifyClearStencil(mBindInfo.mClearStencil);
    modifyStencilFunction(mBindInfo.mStencilFunctionFunc, mBindInfo.mStencilFunctionRef, mBindInfo.mStencilFunctionMask);
    modifyStencilMask(mBindInfo.mStencilMask);
    modifyStencilOperation(mBindInfo.mStencilOpSFail, mBindInfo.mStencilOpDpFail, mBindInfo.mStencilOpDpPass);

    modifyCullingEnabled(mBindInfo.mCullingEnabled);
    modifyFrontFace(mBindInfo.mFrontFace);
    modifyCullFace(mBindInfo.mCullFace);
}

void framebuffer::Framebuffer::bindOnly() const {
    ASSERT_MSG(msBoundHandle != mHandle, "Framebuffer already bound.");

    glBindFramebuffer(mTarget, mHandle);
    ASSERT_GL();

    msBoundHandle = mHandle;
}

void framebuffer::Framebuffer::bind(GLint x, GLint y, GLsizei width, GLsizei height) {
    bindOnly();
    modifyViewport(x, y, width, height);
    configureToOnBindInfo();
}

void framebuffer::Framebuffer::bind(GLsizei width, GLsizei height) {
    bind(0, 0, width, height);
}

void framebuffer::Framebuffer::bind() {
    bind(0, 0, mBindInfo.mViewportWidth, mBindInfo.mViewportHeight);
}

void framebuffer::Framebuffer::clear(bool color, bool depth, bool stencil) const {
    ASSERT_MSG(isBound(), "Framebuffer not bound!");

    GLbitfield mask = 0;
    if (color) {
        mask |= static_cast<GLbitfield>(GL_COLOR_BUFFER_BIT);
    }

    if(depth) {
        mask |= static_cast<GLbitfield>(GL_DEPTH_BUFFER_BIT);
    }

    if (stencil) {
        mask |= static_cast<GLbitfield>(GL_STENCIL_BUFFER_BIT);
    }

    glClear(mask);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound.");
    ASSERT_MSG(width > 0, "Viewport width cannot be negative.");
    ASSERT_MSG(height > 0, "Viewport height cannot be negative.");

    mInfo.mViewportX = x;
    mInfo.mViewportY = y;
    mInfo.mViewportWidth = width;
    mInfo.mViewportHeight = height;
    glViewport(x, y, width, height);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyViewport(GLsizei width, GLsizei height) {
    modifyViewport(0, 0, width, height);
}

void framebuffer::Framebuffer::modifyClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    auto redPair = Framebuffer::clamp(red, 0.0F, 1.0F);
    auto greenPair = Framebuffer::clamp(green, 0.0F, 1.0F);
    auto bluePair = Framebuffer::clamp(blue, 0.0F, 1.0F);
    auto alphaPair = Framebuffer::clamp(alpha, 0.0F, 1.0F);

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if (redPair.second) {
        LOG_WRN() << "Red color component (" << red << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }

    if (greenPair.second) {
        LOG_WRN() << "Green color component (" << green << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }

    if (bluePair.second) {
        LOG_WRN() << "Blue color component (" << blue << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }

    if (alphaPair.second) {
        LOG_WRN() << "Alpha color component (" << alpha << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }
#endif

    mInfo.mRed = redPair.first;
    mInfo.mGreen = greenPair.first;
    mInfo.mBlue = bluePair.first;
    mInfo.mAlpha = alphaPair.first;
    glClearColor(redPair.first, greenPair.first, bluePair.first, alphaPair.first);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyDepthTestingEnabled(bool depthTestingEnabled) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    mInfo.mDepthTestingEnabled = depthTestingEnabled;
    if (depthTestingEnabled) {
        glEnable(GL_DEPTH_TEST);
        ASSERT_GL();
    } else {
        glDisable(GL_DEPTH_TEST);
        ASSERT_GL();
    }
}

void framebuffer::Framebuffer::modifyClearDepth(GLfloat clearDepth) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    auto clearDepthPair = Framebuffer::clamp(clearDepth, 0.0F, 1.0F);

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if (clearDepthPair.second) {
        LOG_WRN() << "Clear depth (" << clearDepth << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }
#endif

    mInfo.mClearDepth = clearDepthPair.first;
    glClearDepthf(clearDepthPair.first);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyDepthFunction(GLenum depthFunction) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");
    ASSERT_MSG(isValidDepthFunction(depthFunction), "Invalid depth function.");

    mInfo.mDepthFunction = depthFunction;
    glDepthFunc(depthFunction);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyDepthMask(GLboolean depthMask) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    mInfo.mDepthMask = depthMask;
    glDepthMask(depthMask);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyDepthRange(GLfloat depthRangeNear, GLfloat depthRangeFar) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    auto nearPair = Framebuffer::clamp(depthRangeNear, 0.0F, 1.0F);
    auto farPair = Framebuffer::clamp(depthRangeFar, 0.0F, 1.0F);

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if (nearPair.second) {
        LOG_WRN() << "Depth range near (" << depthRangeNear << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }

    if (farPair.second) {
        LOG_WRN() << "Depth range far (" << depthRangeFar << ") is being clamped to [0.0, 1.0]." << LOG_END;
    }
#endif

    mInfo.mDepthRangeNear = nearPair.first;
    mInfo.mDepthRangeFar = farPair.first;
    glDepthRangef(nearPair.first, farPair.first);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyStencilTestingEnabled(bool stencilTestingEnabled) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    mInfo.mStencilTestingEnabled = stencilTestingEnabled;
    if (stencilTestingEnabled) {
        glEnable(GL_STENCIL_TEST);
        ASSERT_GL();
    } else {
        glDisable(GL_STENCIL_TEST);
        ASSERT_GL();
    }
}

void framebuffer::Framebuffer::modifyClearStencil(GLint clearStencil) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    auto numBitsInStencilBuffer = getNumBitPlanesInStencilBuffer();

    mInfo.mClearStencil = clearStencil & ((1 << numBitsInStencilBuffer) - 1); // TODO: Make sure is correct

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if (mInfo.mClearStencil != clearStencil) {
        LOG_WRN() << "Clear stencil (" << clearStencil << ") is being masked by (2^numBitsInStencilBuffer - 1)." << LOG_END;
    }
#endif

    glClearStencil(mInfo.mClearStencil);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyStencilFunction(GLenum func, GLint ref, GLuint mask) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");
    ASSERT_MSG(isValidStencilFunctionFunc(func), "Stencil test function not valid.");

    auto numBitPlanesInStencilBuffer = getNumBitPlanesInStencilBuffer();
    auto refPair = clamp(ref, 0, (1 << numBitPlanesInStencilBuffer) - 1); // TODO: Make sure is correct

#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if (refPair.second) {
        LOG_WRN() << "Stencil function reference value (" << ref << ") is being clamped to [0, 2^numBitPlanesInStencilBuffer - 1]." << LOG_END;
    }
#endif

    glStencilFunc(func, refPair.first, mask);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyStencilMask(GLuint stencilMask) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    mInfo.mStencilMask = stencilMask;
    glStencilMask(stencilMask);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyStencilOperation(GLenum sFail, GLenum dpFail, GLenum dpPass) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");
    ASSERT_MSG(isValidStencilOperation(sFail), "Stencil operation sFail is not valid.");
    ASSERT_MSG(isValidStencilOperation(dpFail), "Stencil operation dpFail is not valid.");
    ASSERT_MSG(isValidStencilOperation(dpPass), "Stencil operation dpPass is not valid.");

    mInfo.mStencilOpSFail = sFail;
    mInfo.mStencilOpDpFail = dpFail;
    mInfo.mStencilOpDpPass = dpPass;
    glStencilOp(sFail, dpFail, dpPass);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyCullingEnabled(bool cullingEnabled) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");

    mInfo.mCullingEnabled = cullingEnabled;
    if (cullingEnabled) {
        glEnable(GL_CULL_FACE);
        ASSERT_GL();
    } else {
        glDisable(GL_CULL_FACE);
        ASSERT_GL();
    }
}

void framebuffer::Framebuffer::modifyFrontFace(GLenum frontFace) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");
    ASSERT_MSG(isValidFrontFace(frontFace), "Front face must be GL_CW or GL_CCW.");

    mInfo.mFrontFace = frontFace;
    glFrontFace(frontFace);
    ASSERT_GL();
}

void framebuffer::Framebuffer::modifyCullFace(GLenum cullFace) {
    ASSERT_MSG(isBound(), "Framebuffer is not bound!");
    ASSERT_MSG(isValidCullFace(cullFace), "Cull face must be GL_FRONT, GL_BACK or GL_FRONT_AND_BACK.");

    mInfo.mCullFace = cullFace;
    glCullFace(cullFace);
    ASSERT_GL();
}

bool framebuffer::Framebuffer::isBound() const {
    return mHandle == msBoundHandle;
}

bool framebuffer::Framebuffer::isComplete(bool assert) const {
    GLenum status = glCheckNamedFramebufferStatus(mHandle, mTarget);
    ASSERT_GL();

    const char* error = nullptr;

    switch (status) {
        case GL_FRAMEBUFFER_COMPLETE:
            return true;
        case GL_FRAMEBUFFER_UNDEFINED:
            error = "GL_FRAMEBUFFER_UNDEFINED: The specified framebuffer is the default read or draw framebuffer, but the default framebuffer does not exist.";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
            error = "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: One or more of the framebuffer's attachment points are framebuffer incomplete.";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
            error = "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: Frame buffer does not have at least one image attached to it.";
        case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
            error = "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: Value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for one or more color attachment point(s) named by GL_DRAW_BUFFERi";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
            error = "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER: GL_READ_BUFFER is not GL_NONE and the value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for the color attachment point named by GL_READ_BUFFER.";
            break;
        case GL_FRAMEBUFFER_UNSUPPORTED:
            error = "GL_FRAMEBUFFER_UNSUPPORTED: The combination of internal formats of the attached images violates an implementation-dependent set of restrictions";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
            error = "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: The value of GL_RENDERBUFFER_SAMPLES is not the same for all attached renderbuffers; the value of GL_TEXTURE_SAMPLES is the not same for all attached textures; or, the attached images are a mix of renderbuffers and textures, the value of GL_RENDERBUFFER_SAMPLES does not match the value of GL_TEXTURE_SAMPLES. It can also be that the value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not the same for all attached textures; or, the attached images are a mix of renderbuffers and textures, the value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not GL_TRUE for all attached textures.";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
            error = "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS: One or more framebuffer attachment is layered, and any populated attachment is not layered, or if all populated color attachments are not from textures of the same target.";
            break;
        default:
            error = "Unexpected return value from glCheckNamedFramebufferStatus!";
    }

    if (assert) {
        ASSERT_MSG(false, error);
    }

    return false;
}

GLfloat framebuffer::Framebuffer::getBindRed() const {
    return mBindInfo.mRed;
}

GLfloat framebuffer::Framebuffer::getBindGreen() const {
    return mBindInfo.mGreen;
}

GLfloat framebuffer::Framebuffer::getBindBlue() const {
    return mBindInfo.mBlue;
}

GLfloat framebuffer::Framebuffer::getBindAlpha() const {
    return mBindInfo.mAlpha;
}

void framebuffer::Framebuffer::setBindRed(GLfloat red) {
    mBindInfo.mRed = red;
}

void framebuffer::Framebuffer::setBindGreen(GLfloat green) {
    mBindInfo.mGreen = green;
}

void framebuffer::Framebuffer::setBindBlue(GLfloat blue) {
    mBindInfo.mBlue = blue;
}

void framebuffer::Framebuffer::setBindAlpha(GLfloat alpha) {
    mBindInfo.mAlpha = alpha;
}

void framebuffer::Framebuffer::setBindClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    setBindRed(red);
    setBindGreen(green);
    setBindBlue(blue);
    setBindAlpha(alpha);
}

framebuffer::FramebufferInfo framebuffer::Framebuffer::getBindInfo() const {
    return mBindInfo;
}

framebuffer::FramebufferInfo framebuffer::Framebuffer::getInfo() const {
    return mInfo;
}

void framebuffer::Framebuffer::setBindInfo(framebuffer::FramebufferInfo info) {
    mBindInfo = info;
}

void framebuffer::Framebuffer::attachTexture(const framebuffer::FramebufferTextureAttachment& textureAttachment) {
    GLenum attachment = addTextureAttachment(textureAttachment);
    GLuint textureHandle = textureAttachment.mTexture->mHandle;
    GLint level = textureAttachment.mLevel;
    GLint layer = textureAttachment.mLayer;

    // TODO Clean up and do correctly!
    switch (textureAttachment.mTexture->mTarget) {
        case GL_TEXTURE_2D:
        case GL_TEXTURE_RECTANGLE:
            glFramebufferTexture2D(mTarget, attachment, textureAttachment.mTexture->mTarget, textureHandle, level);
            break;
        default:
            glNamedFramebufferTextureLayer(mHandle, attachment, textureHandle, level, layer);
    }
    ASSERT_GL();
}

GLint framebuffer::Framebuffer::getNumBitPlanesInStencilBuffer() const {
    GLint objectType = 0;
    GLenum attachment = mHandle == 0 ? GL_STENCIL : GL_STENCIL_ATTACHMENT;
    glGetNamedFramebufferAttachmentParameteriv(mHandle, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, &objectType);
    ASSERT_GL();

    if (objectType == GL_NONE) {
        return 0; // No stencil attachment attached.
    }

    // Query the bits in the stencil attachment
    GLint numBitsInStencilBuffer = 0;
    glGetNamedFramebufferAttachmentParameteriv(mHandle, attachment, GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE, &numBitsInStencilBuffer);
    ASSERT_GL();

    return numBitsInStencilBuffer;
}

template<class T>
std::pair<T, bool> framebuffer::Framebuffer::clamp(T value, T min, T max) {
    if (value < min) {
        return std::pair<T, bool>(min, true);
    } else if (value > max) {
        return std::pair<T, bool>(max, true);
    } else {
        return std::pair<T, bool>(value, false);
    }
}

GLenum framebuffer::Framebuffer::addTextureAttachment(const framebuffer::FramebufferTextureAttachment& attachment) {
    switch (attachment.mAttachmentType) {
        case DEPTH:
            ASSERT_MSG(isValidInternalDepthTextureFormat(attachment.mTexture->mInternalFormat), "Texture format on depth attachment not valid.");
            return setDepthTextureAttachment(attachment);
        case STENCIL:
            ASSERT_MSG(isValidInternalStencilTextureFormat(attachment.mTexture->mInternalFormat), "Texture format on stencil attachment not valid.");
            return setStencilTextureAttachment(attachment);
        case DEPTH_STENCIL:
            ASSERT_MSG(isValidInternalDepthStencilTextureFormat(attachment.mTexture->mInternalFormat), "Texture format on depth-stencil attachment not valid.");
            static_cast<void>(setDepthTextureAttachment(attachment));
            static_cast<void>(setStencilTextureAttachment(attachment));
            return GL_DEPTH_STENCIL_ATTACHMENT;
        case COLOR:
            ASSERT_MSG(isValidInternalColorTextureFormat(attachment.mTexture->mInternalFormat), "Texture format on color attachment not valid.");
            return setColorTextureAttachment(attachment);
    }

    ASSERT_MSG(false, "Should be unreachable! Texture attachment type not handled.");
    return 0;
}

GLenum framebuffer::Framebuffer::setDepthTextureAttachment(const framebuffer::FramebufferTextureAttachment& attachment) {
#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if(mDepthIndexFilled) {
            LOG_WRN() << "Replacing existing depth buffer attachment." << LOG_END;
    }
    mDepthIndexFilled = true;
#endif
    mDepthTextureAttachment = attachment;
    return GL_DEPTH_ATTACHMENT;
}

GLenum framebuffer::Framebuffer::setStencilTextureAttachment(const framebuffer::FramebufferTextureAttachment& attachment) {
#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if(mStencilIndexFilled) {
        LOG_WRN() << "Replacing existing depth buffer attachment." << LOG_END;
    }
    mStencilIndexFilled = true;
#endif
    mStencilTextureAttachment = attachment;
    return GL_STENCIL_ATTACHMENT;
}

GLenum framebuffer::Framebuffer::setColorTextureAttachment(const framebuffer::FramebufferTextureAttachment& attachment) {
#if USIDE_WITH_FEATURE_DEBUG_CODE()
    if(mColorTextureAttachments.size() < gcMinFramebufferColorAttachments) {
        LOG_WRN() << "Attaching more color textures than guaranteed by OpenGL spec (" << gcMinFramebufferColorAttachments << ")." << LOG_END;
    }
#endif
    mColorTextureAttachments.push_back(attachment);
    return GL_COLOR_ATTACHMENT0 + mColorTextureAttachments.size() - 1;
}

bool framebuffer::Framebuffer::isValidFramebufferTarget(GLenum target) {
    return target == GL_FRAMEBUFFER || target == GL_DRAW_FRAMEBUFFER || GL_READ_FRAMEBUFFER;
}

bool framebuffer::Framebuffer::isValidDepthFunction(GLenum func) {
    return func == GL_NEVER ||
           func == GL_LESS ||
           func == GL_EQUAL ||
           func == GL_GREATER ||
           func == GL_NOTEQUAL ||
           func == GL_GEQUAL ||
           func == GL_ALWAYS;
}

bool framebuffer::Framebuffer::isValidStencilFunctionFunc(GLenum func) {
    return func == GL_NEVER ||
           func == GL_LESS ||
           func == GL_LEQUAL ||
           func == GL_GREATER ||
           func == GL_GEQUAL ||
           func == GL_EQUAL ||
           func == GL_NOTEQUAL ||
           func == GL_ALWAYS;
}

bool framebuffer::Framebuffer::isValidStencilOperation(GLenum op) {
    return op == GL_KEEP ||
           op == GL_ZERO ||
           op == GL_REPLACE ||
           op == GL_INCR ||
           op == GL_INCR_WRAP ||
           op == GL_DECR ||
           op == GL_DECR_WRAP ||
           op == GL_INVERT;
}

bool framebuffer::Framebuffer::isValidFrontFace(GLenum frontFace) {
    return frontFace == GL_CW || frontFace == GL_CCW;
}

bool framebuffer::Framebuffer::isValidCullFace(GLenum cullFace) {
    return cullFace == GL_FRONT || cullFace == GL_BACK || cullFace == GL_FRONT_AND_BACK;
}

bool framebuffer::Framebuffer::isValidInternalColorTextureFormat(GLint format) {
    switch (format) {
        case GL_COMPRESSED_RED_RGTC1:
        case GL_COMPRESSED_SIGNED_RED_RGTC1:
        case GL_COMPRESSED_RG_RGTC2:
        case GL_COMPRESSED_SIGNED_RG_RGTC2:
        case GL_COMPRESSED_RGBA_BPTC_UNORM:
        case GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:
        case GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:
        case GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT:
            return false;
        default:
            return !isValidInternalDepthTextureFormat(format)       &&
                   !isValidInternalStencilTextureFormat(format)     &&
                   !isValidInternalDepthStencilTextureFormat(format);
    }
}

bool framebuffer::Framebuffer::isValidInternalDepthTextureFormat(GLint format) {
    switch (format) {
        case GL_DEPTH_COMPONENT16:
        case GL_DEPTH_COMPONENT24:
        case GL_DEPTH_COMPONENT32:
        case GL_DEPTH_COMPONENT32F:
            return true;
        default:
            return false;
    }
}

bool framebuffer::Framebuffer::isValidInternalStencilTextureFormat(GLint format) {
    switch (format) {
        case GL_STENCIL_INDEX1:
        case GL_STENCIL_INDEX4:
        case GL_STENCIL_INDEX16:
            LOG_WRN() << "You are strongly advised to only use stencil texture format GL_STENCIL_INDEX8 (from OpenGL documentation)." << LOG_END;
        case GL_STENCIL_INDEX8:
            return true;
        default:
            return false;
    }
}

bool framebuffer::Framebuffer::isValidInternalDepthStencilTextureFormat(GLint format) {
    return format == GL_DEPTH24_STENCIL8 || format == GL_DEPTH32F_STENCIL8;
}
