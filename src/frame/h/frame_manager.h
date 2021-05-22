//
// Created by Anton on 2021-05-20.
//

#ifndef USIDE_SRC_FRAME_H_FRAME_MANAGER_H
#define USIDE_SRC_FRAME_H_FRAME_MANAGER_H

#include <string>
#include <memory>
#include <unordered_map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "frame.h"

namespace frame {

    class FrameManager {
    public:
        FrameManager();
        ~FrameManager();

    private:
        static void handleError(int i, const char* string);

    public:
        Frame& createFrame(int width, int height, const std::string& title, GLFWmonitor* monitor = nullptr, GLFWwindow* share = nullptr);
        void destroyFrame(Frame& frame);

    public:
        void pollEvents();

    private:
        std::unordered_map<GLFWwindow*, Frame> mFrames;
    };
}

#endif //USIDE_SRC_FRAME_H_FRAME_MANAGER_H
