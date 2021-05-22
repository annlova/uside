#include <log/include/log_include.h>
#include <assertion/include/assertion_include.h>
#include <frame/include/frame_include.h>
#include <framebuffer/include/framebuffer_include.h>

bool gTemp = false;
void a(GLFWwindow* pWwindow) {
    gTemp = true;
}

int main() {
    const int width = 480;
    const int height = 480;

    frame::FrameManager fm;
    auto& frame = fm.createFrame(width, height, "Frame Name Goes Here");
    frame.setWindowCloseFun(a);
    frame.makeContextCurrent();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    framebuffer::Framebuffer defaultFb(width, height);
//    defaultFb.bind();
//    defaultFb.setBindClearColor(1.0F, 0.5F, 0.5F, 1.0F);
//
//    while (!gTemp) {
//        fm.pollEvents();
//        defaultFb.clear(true);
//        frame.swapBuffers();
//    }

    return 0;
}
