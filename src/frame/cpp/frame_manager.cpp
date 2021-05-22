//
// Created by Anton on 2021-05-20.
//

#include "../h/frame_manager.h"

#include <log/include/log_include.h>
#include <assertion/include/assertion_include.h>

frame::FrameManager::FrameManager() {
    auto oldCallback = glfwSetErrorCallback(handleError);
    if (oldCallback != nullptr) {
        LOG_WRN() << "A GLFW error callback function was already set. More than 1 FrameManager has probably been created." << LOG_END;
    }

    glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_TRUE);
    auto err = glfwInit();
    if (err == GLFW_FALSE) {
        LOG_FTL() << "Unable to initialize GLFW." << LOG_END;
        ASSERT(false); // TODO: better error handling
        return;
    }

    // TODO: Remove, handle custom window hints somehow for each window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);

    LOG_TRC() << "FrameManager constructed." << LOG_END;
}

frame::FrameManager::~FrameManager() {
    mFrames.clear();
    glfwTerminate();
    LOG_TRC() << "FrameManager destructed." << LOG_END;
}

void frame::FrameManager::handleError(int errorCode, const char* errorString) {
    LOG_ERR() << "GLFW error (" << LOG_HEX << errorCode << "): " << LOG_NL << errorString << LOG_END;
}

frame::Frame& frame::FrameManager::createFrame(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share) {
    // Create a new GLFW window and save its handle
    std::unique_ptr<GLFWwindow, GLFWwindowDeleter> handle(glfwCreateWindow(width, height, title.c_str(), monitor, share));
    if (!handle) {
        LOG_FTL() << "Failed to create frame \"" << title << "\"." << LOG_END;
        ASSERT(false); // TODO: better error handling
    }

    // Center window if not fullscreen
    if(monitor == nullptr) {
        const auto* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwSetWindowPos(handle.get(), (vidMode->width - width) / 2, (vidMode->height - height) / 2);
    }

    // TODO: If icon paths exist set window icon

    auto inserted = mFrames.emplace(handle.get(), std::move(handle));
    if (!inserted.second) {
        LOG_FTL() << "Failed to insert new frame into mFrames map." << LOG_END;
        ASSERT(false); // TODO: better error handling
    }

    return inserted.first->second;
}

void frame::FrameManager::destroyFrame(frame::Frame& frame) {
    auto amountErased = mFrames.erase(frame.mcHandle.get());
    if (amountErased != 1) {
        LOG_WRN() << "Unable to destroy frame (title: \"" << frame.getTitle() << "\"). Not found in mFrames map." << LOG_END;
    }
}

void frame::FrameManager::pollEvents() {
    glfwPollEvents();
}
