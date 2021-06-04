//
// Created by Anton on 2021-06-04.
//

#ifndef USIDE_SRC_FRAME_H_FRAME_INPUT_CALLBACK_INTERFACE_H
#define USIDE_SRC_FRAME_H_FRAME_INPUT_CALLBACK_INTERFACE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace frame {
    struct FrameInputCallbackInterface {
        [[nodiscard]] virtual GLFWmousebuttonfun getMouseButtonFun() const = 0;
        [[nodiscard]] virtual GLFWcursorposfun getCursorPosFun() const = 0;
        [[nodiscard]] virtual GLFWcursorenterfun getCursorEnterFun() const = 0;
        [[nodiscard]] virtual GLFWscrollfun getScrollFun() const = 0;
        [[nodiscard]] virtual GLFWkeyfun getKeyFun() const = 0;
        [[nodiscard]] virtual GLFWcharfun getCharFun() const = 0;
        [[nodiscard]] virtual GLFWcharmodsfun getCharModsFun() const = 0;
        [[nodiscard]] virtual GLFWdropfun getDropFun() const = 0;
        [[nodiscard]] virtual GLFWjoystickfun getJoystickFun() const = 0;
        [[nodiscard]] virtual GLFWwindowposfun getWindowPosFun() const = 0;
        [[nodiscard]] virtual GLFWwindowsizefun getWindowSizeFun() const = 0;
        [[nodiscard]] virtual GLFWwindowclosefun getWindowCloseFun() const = 0;
        [[nodiscard]] virtual GLFWwindowrefreshfun getWindowRefreshFun() const = 0;
        [[nodiscard]] virtual GLFWwindowfocusfun getWindowFocusFun() const = 0;
        [[nodiscard]] virtual GLFWwindowiconifyfun getWindowIconifyFun() const = 0;
        [[nodiscard]] virtual GLFWwindowmaximizefun getWindowMaximizeFun() const = 0;
        [[nodiscard]] virtual GLFWwindowcontentscalefun getWindowContentScaleFun() const = 0;
        [[nodiscard]] virtual GLFWframebuffersizefun getFrameBufferSizeFun() const = 0;

        virtual void setMouseButtonFun(GLFWmousebuttonfun callbackFunction) = 0;
        virtual void setCursorPosFun(GLFWcursorposfun callbackFunction) = 0;
        virtual void setCursorEnterFun(GLFWcursorenterfun callbackFunction) = 0;
        virtual void setScrollFun(GLFWscrollfun callbackFunction) = 0;
        virtual void setKeyFun(GLFWkeyfun callbackFunction) = 0;
        virtual void setCharFun(GLFWcharfun callbackFunction) = 0;
        virtual void setCharModsFun(GLFWcharmodsfun callbackFunction) = 0;
        virtual void setDropFun(GLFWdropfun callbackFunction) = 0;
        virtual void setJoystickFun(GLFWjoystickfun callbackFunction) = 0;
        virtual void setWindowPosFun(GLFWwindowposfun callbackFunction) = 0;
        virtual void setWindowSizeFun(GLFWwindowsizefun callbackFunction) = 0;
        virtual void setWindowCloseFun(GLFWwindowclosefun callbackFunction) = 0;
        virtual void setWindowRefreshFun(GLFWwindowrefreshfun callbackFunction) = 0;
        virtual void setWindowFocusFun(GLFWwindowfocusfun callbackFunction) = 0;
        virtual void setWindowIconifyFun(GLFWwindowiconifyfun callbackFunction) = 0;
        virtual void setWindowMaximizeFun(GLFWwindowmaximizefun callbackFunction) = 0;
        virtual void setWindowContentScaleFun(GLFWwindowcontentscalefun callbackFunction) = 0;
        virtual void setFrameBufferSizeFun(GLFWframebuffersizefun callbackFunction) = 0;
    };
}
#endif //USIDE_SRC_FRAME_H_FRAME_INPUT_CALLBACK_INTERFACE_H
