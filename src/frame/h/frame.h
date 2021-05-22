//
// Created by Anton on 2021-05-12.
//

#ifndef USIDE_SRC_FRAME_H_FRAME_H
#define USIDE_SRC_FRAME_H_FRAME_H

#include <string>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <log/include/log_include.h>

namespace frame {
    struct GLFWwindowDeleter {
        void operator()(GLFWwindow* handle) {
            glfwDestroyWindow(handle);
            LOG_TRC() << "glfwDestroyWindow called." << LOG_END;
        }
    };

    class Frame {
    public:
        Frame(std::unique_ptr<GLFWwindow, GLFWwindowDeleter> handle);
        ~Frame();

    public:
        void makeContextCurrent();
        void freeThreadContext();
        void swapBuffers();
        double getTime();

    public: // Callback setters
        GLFWmousebuttonfun getMouseButtonFun() const;
        GLFWcursorposfun getCursorPosFun() const;
        GLFWcursorenterfun getCursorEnterFun() const;
        GLFWscrollfun getScrollFun() const;
        GLFWkeyfun getKeyFun() const;
        GLFWcharfun getCharFun() const;
        GLFWcharmodsfun getCharModsFun() const;
        GLFWdropfun getDropFun() const;
        GLFWjoystickfun getJoystickFun() const;
        GLFWwindowposfun getWindowPosFun() const;
        GLFWwindowsizefun getWindowSizeFun() const;
        GLFWwindowclosefun getWindowCloseFun() const;
        GLFWwindowrefreshfun getWindowRefreshFun() const;
        GLFWwindowfocusfun getWindowFocusFun() const;
        GLFWwindowiconifyfun getWindowIconifyFun() const;
        GLFWwindowmaximizefun getWindowMaximizeFun() const;
        GLFWwindowcontentscalefun getWindowContentScaleFun() const;
        GLFWframebuffersizefun getFrameBufferSizeFun() const;

        void setMouseButtonFun(GLFWmousebuttonfun callbackFunction);
        void setCursorPosFun(GLFWcursorposfun callbackFunction);
        void setCursorEnterFun(GLFWcursorenterfun callbackFunction);
        void setScrollFun(GLFWscrollfun callbackFunction);
        void setKeyFun(GLFWkeyfun callbackFunction);
        void setCharFun(GLFWcharfun callbackFunction);
        void setCharModsFun(GLFWcharmodsfun callbackFunction);
        void setDropFun(GLFWdropfun callbackFunction);
        void setJoystickFun(GLFWjoystickfun callbackFunction);
        void setWindowPosFun(GLFWwindowposfun callbackFunction);
        void setWindowSizeFun(GLFWwindowsizefun callbackFunction);
        void setWindowCloseFun(GLFWwindowclosefun callbackFunction);
        void setWindowRefreshFun(GLFWwindowrefreshfun callbackFunction);
        void setWindowFocusFun(GLFWwindowfocusfun callbackFunction);
        void setWindowIconifyFun(GLFWwindowiconifyfun callbackFunction);
        void setWindowMaximizeFun(GLFWwindowmaximizefun callbackFunction);
        void setWindowContentScaleFun(GLFWwindowcontentscalefun callbackFunction);
        void setFrameBufferSizeFun(GLFWframebuffersizefun callbackFunction);

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
