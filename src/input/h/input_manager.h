//
// Created by Anton on 2021-06-04.
//

#ifndef USIDE_SRC_INPUT_H_INPUT_MANAGER_H
#define USIDE_SRC_INPUT_H_INPUT_MANAGER_H

#include <vector>
#include <unordered_map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <frame/include/frame_include.h>

#include "input_listener.h"

namespace input {
    class InputManager {
    public:
        InputManager();

    public:
        void addFrame(const frame::Frame& frame);
        bool removeFrame(const frame::Frame& frame);

    public:
        static void onMouseButton(GLFWwindow* window, int button, int action, int mods);
        static void onCursorPos(GLFWwindow* window, double x, double y);
        static void onCursorEnter(GLFWwindow* window, int entered);
        static void onScroll(GLFWwindow* window, double xOffset, double yOffset);
        static void onKey(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void onChar(GLFWwindow* window, unsigned int codepoint);
        static void onCharMods(GLFWwindow* window, unsigned int codepoint, int mods);
        static void onDrop(GLFWwindow* window, int pathCount, const char* paths[]);
        static void onJoystick(int jid, int event);
        static void onWindowPos(GLFWwindow* window, int xPos, int yPos);
        static void onWindowSize(GLFWwindow* window, int width, int height);
        static void onWindowClose(GLFWwindow* window);
        static void onWindowRefresh(GLFWwindow* window);
        static void onWindowFocus(GLFWwindow* window, int focused);
        static void onWindowIconify(GLFWwindow* window, int iconified);
        static void onWindowMaximize(GLFWwindow* window, int maximized);
        static void onWindowContentScale(GLFWwindow* window, float xScale, float yScale);
        static void onFramebufferSize(GLFWwindow* window, int width, int height);

    private:
        void setFrameInputCallbacks(GLFWwindow* window);
        static void clearFrameInputCallbacks(GLFWwindow* window);

    private:
        std::unordered_map<GLFWwindow*, std::vector<InputListener*>> mInputListeners;
    };
}
#endif //USIDE_SRC_INPUT_H_INPUT_MANAGER_H
