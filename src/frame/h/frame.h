//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_FRAME_H_FRAME_H
#define USIDE_SRC_FRAME_H_FRAME_H

#include <string>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <logs/include/log_include.h>

#include "frame_input_callback_interface.h"

namespace frame {
    struct GLFWwindowDeleter {
        void operator()(GLFWwindow* handle) {
            glfwDestroyWindow(handle);
            LOG_TRC() << "glfwDestroyWindow called." << LOG_END;
        }
    };

    class Frame : public FrameInputCallbackInterface {
    public:
        Frame(std::unique_ptr<GLFWwindow, GLFWwindowDeleter> handle);
        ~Frame();

    public:
        void makeContextCurrent();
        void freeThreadContext();
        void swapBuffers();
        double getTime();

    public: // Callback getters and setters
        GLFWmousebuttonfun getMouseButtonFun() const override;
        GLFWcursorposfun getCursorPosFun() const override;
        GLFWcursorenterfun getCursorEnterFun() const override;
        GLFWscrollfun getScrollFun() const override;
        GLFWkeyfun getKeyFun() const override;
        GLFWcharfun getCharFun() const override;
        GLFWcharmodsfun getCharModsFun() const override;
        GLFWdropfun getDropFun() const override;
        GLFWjoystickfun getJoystickFun() const override;
        GLFWwindowposfun getWindowPosFun() const override;
        GLFWwindowsizefun getWindowSizeFun() const override;
        GLFWwindowclosefun getWindowCloseFun() const override;
        GLFWwindowrefreshfun getWindowRefreshFun() const override;
        GLFWwindowfocusfun getWindowFocusFun() const override;
        GLFWwindowiconifyfun getWindowIconifyFun() const override;
        GLFWwindowmaximizefun getWindowMaximizeFun() const override;
        GLFWwindowcontentscalefun getWindowContentScaleFun() const override;
        GLFWframebuffersizefun getFrameBufferSizeFun() const override;

        void setMouseButtonFun(GLFWmousebuttonfun callbackFunction) override;
        void setCursorPosFun(GLFWcursorposfun callbackFunction) override;
        void setCursorEnterFun(GLFWcursorenterfun callbackFunction) override;
        void setScrollFun(GLFWscrollfun callbackFunction) override;
        void setKeyFun(GLFWkeyfun callbackFunction) override;
        void setCharFun(GLFWcharfun callbackFunction) override;
        void setCharModsFun(GLFWcharmodsfun callbackFunction) override;
        void setDropFun(GLFWdropfun callbackFunction) override;
        void setJoystickFun(GLFWjoystickfun callbackFunction) override;
        void setWindowPosFun(GLFWwindowposfun callbackFunction) override;
        void setWindowSizeFun(GLFWwindowsizefun callbackFunction) override;
        void setWindowCloseFun(GLFWwindowclosefun callbackFunction) override;
        void setWindowRefreshFun(GLFWwindowrefreshfun callbackFunction) override;
        void setWindowFocusFun(GLFWwindowfocusfun callbackFunction) override;
        void setWindowIconifyFun(GLFWwindowiconifyfun callbackFunction) override;
        void setWindowMaximizeFun(GLFWwindowmaximizefun callbackFunction) override;
        void setWindowContentScaleFun(GLFWwindowcontentscalefun callbackFunction) override;
        void setFrameBufferSizeFun(GLFWframebuffersizefun callbackFunction) override;

        void releaseCallbacks();

    public:
        bool operator==(const Frame& other) {
            return mcHandle == other.mcHandle;
        }

    public:
        const std::string& getTitle();

    public:
        /// GLFW window handle
        const std::unique_ptr<GLFWwindow, GLFWwindowDeleter> mcHandle;

    private:
        /// The title displayed on the window.
        std::string mTitle;

        /// If vsync is on/off
        bool mVSync = false; // TODO

        /// Mouse captured on/off.
        bool mMouseCaptured = false; // TODO

        // Callback functions concerned with user input
        GLFWmousebuttonfun          mMouseButtonFun;
        GLFWcursorposfun            mCursorPosFun;
        GLFWcursorenterfun          mCursorEnterFun;
        GLFWscrollfun               mScrollFun;
        GLFWkeyfun                  mKeyFun;
        GLFWcharfun                 mCharFun;
        GLFWcharmodsfun             mCharModsFun;
        GLFWdropfun                 mDropFun;
        GLFWjoystickfun             mJoystickFun;

        // Callback functions concerned with the window frame
        GLFWwindowposfun            mWindowPosFun;
        GLFWwindowsizefun           mWindowSizeFun;
        GLFWwindowclosefun          mWindowCloseFun;
        GLFWwindowrefreshfun        mWindowRefreshFun;
        GLFWwindowfocusfun          mWindowFocusFun;
        GLFWwindowiconifyfun        mWindowIconifyFun;
        GLFWwindowmaximizefun       mWindowMaximizeFun;
        GLFWwindowcontentscalefun   mWindowContentScaleFun;
        GLFWframebuffersizefun      mFramebufferSizeFun;
    };
}
#endif //USIDE_SRC_FRAME_H_FRAME_H
