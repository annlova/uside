//
// Created by Anton on 2021-05-12.
//

#include "../h/frame.h"

#include <memory>

#include <assertion/h/assertion_macro.h>

frame::Frame::Frame(std::unique_ptr<GLFWwindow, GLFWwindowDeleter> handle)
: mcHandle(std::move(handle)),
  mMouseButtonFun{nullptr}, mCursorPosFun{nullptr},
  mCursorEnterFun{nullptr}, mScrollFun{nullptr},
  mKeyFun{nullptr}, mCharFun{nullptr},
  mCharModsFun{nullptr}, mDropFun{nullptr},
  mJoystickFun{nullptr}, mWindowPosFun{nullptr},
  mWindowSizeFun{nullptr}, mWindowCloseFun{nullptr},
  mWindowRefreshFun{nullptr}, mWindowFocusFun{nullptr},
  mWindowIconifyFun{nullptr}, mWindowMaximizeFun{nullptr},
  mWindowContentScaleFun{nullptr}, mFramebufferSizeFun{nullptr} {
    LOG_TRC() << "Frame constructed." << LOG_END;
}

frame::Frame::~Frame() {
    releaseCallbacks();
    LOG_TRC() << "Frame destructed." << LOG_END;
}

void frame::Frame::makeContextCurrent() {
    glfwMakeContextCurrent(mcHandle.get());

    // TODO: In practice only needs to be called once
    auto err = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)); // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast)
    if (err == 0) {
        LOG_FTL() << "GLAD failed to load GL loader." << LOG_END;
        ASSERT(false);
    }

    // TODO: Set opengl values back to this window's values
}

void frame::Frame::freeThreadContext() {
    glfwMakeContextCurrent(nullptr);
}

void frame::Frame::swapBuffers() {
    glfwSwapBuffers(mcHandle.get());
}

double frame::Frame::getTime() {
    return glfwGetTime();
}

void frame::Frame::setMouseButtonFun(GLFWmousebuttonfun callbackFunction) {
    mMouseButtonFun = callbackFunction;
    auto previousCallbackFunction = glfwSetMouseButtonCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setCursorPosFun(GLFWcursorposfun callbackFunction) {
    mCursorPosFun = callbackFunction;
    auto previousCallbackFunction = glfwSetCursorPosCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setCursorEnterFun(GLFWcursorenterfun callbackFunction) {
    mCursorEnterFun = callbackFunction;
    auto previousCallbackFunction = glfwSetCursorEnterCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setScrollFun(GLFWscrollfun callbackFunction) {
    mScrollFun = callbackFunction;
    auto previousCallbackFunction = glfwSetScrollCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setKeyFun(GLFWkeyfun callbackFunction) {
    mKeyFun = callbackFunction;
    auto previousCallbackFunction = glfwSetKeyCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setCharFun(GLFWcharfun callbackFunction) {
    mCharFun = callbackFunction;
    auto previousCallbackFunction = glfwSetCharCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setCharModsFun(GLFWcharmodsfun callbackFunction) {
    mCharModsFun = callbackFunction;
    auto previousCallbackFunction = glfwSetCharModsCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setDropFun(GLFWdropfun callbackFunction) {
    mDropFun = callbackFunction;
    auto previousCallbackFunction = glfwSetDropCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setJoystickFun(GLFWjoystickfun callbackFunction) {
    mJoystickFun = callbackFunction;
    auto previousCallbackFunction = glfwSetJoystickCallback(callbackFunction);
}

void frame::Frame::setWindowPosFun(GLFWwindowposfun callbackFunction) {
    mWindowPosFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowPosCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowSizeFun(GLFWwindowsizefun callbackFunction) {
    mWindowSizeFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowSizeCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowCloseFun(GLFWwindowclosefun callbackFunction) {
    mWindowCloseFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowCloseCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowRefreshFun(GLFWwindowrefreshfun callbackFunction) {
    mWindowRefreshFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowRefreshCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowFocusFun(GLFWwindowfocusfun callbackFunction) {
    mWindowFocusFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowFocusCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowIconifyFun(GLFWwindowiconifyfun callbackFunction) {
    mWindowIconifyFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowIconifyCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowMaximizeFun(GLFWwindowmaximizefun callbackFunction) {
    mWindowMaximizeFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowMaximizeCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setWindowContentScaleFun(GLFWwindowcontentscalefun callbackFunction) {
    mWindowContentScaleFun = callbackFunction;
    auto previousCallbackFunction = glfwSetWindowContentScaleCallback(mcHandle.get(), callbackFunction);
}

void frame::Frame::setFrameBufferSizeFun(GLFWframebuffersizefun callbackFunction) {
    mFramebufferSizeFun = callbackFunction;
    auto previousCallbackFunction = glfwSetFramebufferSizeCallback(mcHandle.get(), callbackFunction);
}

GLFWmousebuttonfun frame::Frame::getMouseButtonFun() const {
    return mMouseButtonFun;
}

GLFWcursorposfun frame::Frame::getCursorPosFun() const {
    return mCursorPosFun;
}

GLFWcursorenterfun frame::Frame::getCursorEnterFun() const {
    return mCursorEnterFun;
}

GLFWscrollfun frame::Frame::getScrollFun() const {
    return mScrollFun;
}

GLFWkeyfun frame::Frame::getKeyFun() const {
    return mKeyFun;
}

GLFWcharfun frame::Frame::getCharFun() const {
    return mCharFun;
}

GLFWcharmodsfun frame::Frame::getCharModsFun() const {
    return mCharModsFun;
}

GLFWdropfun frame::Frame::getDropFun() const {
    return mDropFun;
}

GLFWjoystickfun frame::Frame::getJoystickFun() const {
    return mJoystickFun;
}

GLFWwindowposfun frame::Frame::getWindowPosFun() const {
    return mWindowPosFun;
}

GLFWwindowsizefun frame::Frame::getWindowSizeFun() const {
    return mWindowSizeFun;
}

GLFWwindowclosefun frame::Frame::getWindowCloseFun() const {
    return mWindowCloseFun;
}

GLFWwindowrefreshfun frame::Frame::getWindowRefreshFun() const {
    return mWindowRefreshFun;
}

GLFWwindowfocusfun frame::Frame::getWindowFocusFun() const {
    return mWindowFocusFun;
}

GLFWwindowiconifyfun frame::Frame::getWindowIconifyFun() const {
    return mWindowIconifyFun;
}

GLFWwindowmaximizefun frame::Frame::getWindowMaximizeFun() const {
    return mWindowMaximizeFun;
}

GLFWwindowcontentscalefun frame::Frame::getWindowContentScaleFun() const {
    return mWindowContentScaleFun;
}

GLFWframebuffersizefun frame::Frame::getFrameBufferSizeFun() const {
    return mFramebufferSizeFun;
}

const std::string& frame::Frame::getTitle() {
    return mTitle;
}

void frame::Frame::releaseCallbacks() {
    setMouseButtonFun(nullptr);
    setCursorPosFun(nullptr);
    setCursorEnterFun(nullptr);
    setScrollFun(nullptr);
    setKeyFun(nullptr);
    setCharFun(nullptr);
    setCharModsFun(nullptr);
    setDropFun(nullptr);
    setJoystickFun(nullptr);
    setWindowPosFun(nullptr);
    setWindowSizeFun(nullptr);
    setWindowCloseFun(nullptr);
    setWindowRefreshFun(nullptr);
    setWindowFocusFun(nullptr);
    setWindowIconifyFun(nullptr);
    setWindowMaximizeFun(nullptr);
    setWindowContentScaleFun(nullptr);
    setFrameBufferSizeFun(nullptr);
}
