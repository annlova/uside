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

    public: // Functions to be connected to GLFW callbacks
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    private:
        void setFrameInputCallbacks(GLFWwindow* window);
        void clearFrameInputCallbacks(GLFWwindow* window);

    private:
        std::unordered_map<GLFWwindow*, std::vector<InputListener*>> mInputListeners;
    };
}
#endif //USIDE_SRC_INPUT_H_INPUT_MANAGER_H
