//
// Created by Anton on 2021-06-04.
//

#include "../h/input_manager.h"

#include <assertion/include/assertion_include.h>

input::InputManager::InputManager() {

}

void input::InputManager::addFrame(const frame::Frame& frame) {
    setFrameInputCallbacks(frame.mcHandle.get());
    glfwSetInputMode(frame.mcHandle.get(), GLFW_LOCK_KEY_MODS, GLFW_TRUE); // Sets so that num lock and caps lock can be identified
}

bool input::InputManager::removeFrame(const frame::Frame& frame) {
    auto found = mInputListeners.find(frame.mcHandle.get());
    ASSERT(found != mInputListeners.end());

}

void input::InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

void input::InputManager::setFrameInputCallbacks(GLFWwindow* window) {
    bool alreadyHasCallback = false;
    alreadyHasCallback = glfwSetMouseButtonCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCursorPosCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCursorEnterCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetScrollCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetKeyCallback(window, keyCallback) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCharCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCharModsCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetDropCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetJoystickCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowPosCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowSizeCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowCloseCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowRefreshCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowFocusCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowIconifyCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowMaximizeCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowContentScaleCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetFrameBufferSizeCallback(window, ) != nullptr;
    ASSERT(!alreadyHasCallback);
}

void input::InputManager::clearFrameInputCallbacks(GLFWwindow* window) {
    bool alreadyHasCallback = false;
    alreadyHasCallback = glfwSetMouseButtonCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetCursorPosCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetCursorEnterCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetScrollCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetKeyCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetCharCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetCharModsCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetDropCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetJoystickCallback(nullptr) != nullptr; // TODO
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowPosCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowSizeCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowCloseCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowRefreshCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowFocusCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowIconifyCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowMaximizeCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowContentScaleCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
    alreadyHasCallback = glfwSetFrameBufferSizeCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
}
