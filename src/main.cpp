#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>
#include <frame/include/frame_include.h>
#include <framebuffer/include/framebuffer_include.h>
#include <windows.h>

bool gTemp = false;
void a(GLFWwindow* pWwindow) {
    gTemp = true;
}

bool gColor = false;
void b(GLFWwindow *pWindow, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        gColor = true;
    }

    if (key == GLFW_KEY_E && action == GLFW_RELEASE) {
        gColor = false;
    }
}

int main() {
    // Make ANSI colors work in clion console on some systems.
    system(("chcp " + std::to_string(CP_UTF8)).c_str());

    const int width = 480;
    const int height = 480;

    frame::FrameManager fm;
    auto& frame = fm.createFrame(width, height, "Universal Shitty IDE");
    frame.setWindowCloseFun(a);
    frame.setKeyFun(b);
    frame.makeContextCurrent();

    LOG() << "OpenGL version supported: " << glGetString(GL_VERSION) << "." << LOG_END;

    framebuffer::Framebuffer defaultFb(width, height);
    defaultFb.setBindClearColor(1.0F, 0.5F, 0.5F, 1.0F);

    while (!gTemp) {
        fm.pollEvents();
        defaultFb.bind();
        if (gColor) {
            defaultFb.modifyClearColor(0.6f, 0.5f, 1.0f, 1.0f);
        }
        defaultFb.clear(true);
        defaultFb.markUnbound();
        frame.swapBuffers();
    }

    return 0;
}
