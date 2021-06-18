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
    clearFrameInputCallbacks(found->first);
}

void input::InputManager::onMouseButton(GLFWwindow* window, int button, int action, int mods) {
    // TODO
}

void input::InputManager::onCursorPos(GLFWwindow* window, double x, double y) {
    // TODO
}

void input::InputManager::onCursorEnter(GLFWwindow* window, int entered) {
    // TODO
}

void input::InputManager::onScroll(GLFWwindow* window, double xOffset, double yOffset) {
    // TODO
}

void input::InputManager::onKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // TODO
}

void input::InputManager::onChar(GLFWwindow* window, unsigned int codepoint) {
    // TODO
}

void input::InputManager::onCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {
    // TODO
}

void input::InputManager::onDrop(GLFWwindow* window, int pathCount, const char** paths) {
    // TODO
}

void input::InputManager::onJoystick(int jid, int event) {
    // TODO
}

void input::InputManager::onWindowPos(GLFWwindow* window, int xPos, int yPos) {
    // TODO
}

void input::InputManager::onWindowSize(GLFWwindow* window, int width, int height) {
    // TODO
}

void input::InputManager::onWindowClose(GLFWwindow* window) {
    // TODO
}

void input::InputManager::onWindowRefresh(GLFWwindow* window) {
    // TODO
}

void input::InputManager::onWindowFocus(GLFWwindow* window, int focused) {
    // TODO
}

void input::InputManager::onWindowIconify(GLFWwindow* window, int iconified) {
    // TODO
}

void input::InputManager::onWindowMaximize(GLFWwindow* window, int maximized) {
    // TODO
}

void input::InputManager::onWindowContentScale(GLFWwindow* window, float xScale, float yScale) {
    // TODO
}

void input::InputManager::onFramebufferSize(GLFWwindow* window, int width, int height) {
    // TODO
}

void input::InputManager::setFrameInputCallbacks(GLFWwindow* window) {
    bool alreadyHasCallback = false;
    alreadyHasCallback = glfwSetMouseButtonCallback(window, onMouseButton) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCursorPosCallback(window, onCursorPos) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCursorEnterCallback(window, onCursorEnter) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetScrollCallback(window, onScroll) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetKeyCallback(window, onKey) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCharCallback(window, onChar) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetCharModsCallback(window, onCharMods) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetDropCallback(window, onDrop) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetJoystickCallback(onJoystick) != nullptr; // TODO
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowPosCallback(window, onWindowPos) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowSizeCallback(window, onWindowSize) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowCloseCallback(window, onWindowClose) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowRefreshCallback(window, onWindowRefresh) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowFocusCallback(window, onWindowFocus) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowIconifyCallback(window, onWindowIconify) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowMaximizeCallback(window, onWindowMaximize) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetWindowContentScaleCallback(window, onWindowContentScale) != nullptr;
    ASSERT(!alreadyHasCallback);
    alreadyHasCallback = glfwSetFramebufferSizeCallback(window, onFramebufferSize) != nullptr;
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
    alreadyHasCallback = glfwSetFramebufferSizeCallback(window, nullptr) != nullptr;
    ASSERT(alreadyHasCallback);
}
