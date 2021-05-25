#include <windows.h>

#include <logs/include/log_include.h>
#include <assertion/include/assertion_include.h>
#include <frame/include/frame_include.h>
#include <framebuffer/include/framebuffer_include.h>
#include <file/include/file_include.h>
#include <shader/include/shader_include.h>
#include <string/include/string_hash_include.h>
#include <parser/include/parser_include.h>

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
//    (void) system(("chcp " + std::to_string(CP_UTF8)).c_str());

    parser::Parser p;
    return 0;

    const int width = 480;
    const int height = 480;

    frame::FrameManager fm;
    auto& frame = fm.createFrame(width, height, "Universal Shitty IDE");
    frame.setWindowCloseFun(a);
    frame.setKeyFun(b);
    frame.makeContextCurrent();

    LOG() << "OpenGL version supported: " << glGetString(GL_VERSION) << "." << LOG_END;

    framebuffer::Framebuffer defaultFb(width, height);

    auto vertexSource = file::FileLoader::readText("res/shaders/simple.vsh");
    auto fragmentSource = file::FileLoader::readText("res/shaders/simple.fsh");
    shader::ShaderProgram simpleShader;
    shader::ShaderProgramFactory::createShaderProgram(vertexSource.c_str(), fragmentSource.c_str(), simpleShader);
    auto& uniform = simpleShader.getUniform("uniColor"_sid);

    const std::array<float, 12> vData = {
            0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    const int indicesCount = 6;
    const std::array<unsigned int, indicesCount> iData = {
            0, 1, 2,
            0, 2, 3
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    ASSERT_GL();
    glBindVertexArray(vao);
    ASSERT_GL();
    GLuint vBuf;
    glGenBuffers(1, &vBuf);
    ASSERT_GL();
    glBindBuffer(GL_ARRAY_BUFFER, vBuf);
    ASSERT_GL();
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vData.size(), vData.data(), GL_STATIC_DRAW);
    ASSERT_GL();
    glVertexAttribPointer(
            simpleShader.getAttribute("pos"_sid).mLocation,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            nullptr);
    ASSERT_GL();
    GLuint iBuf;
    glGenBuffers(1, &iBuf);
    ASSERT_GL();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuf);
    ASSERT_GL();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * iData.size(), iData.data(), GL_STATIC_DRAW);
    ASSERT_GL();

    GLfloat r = 0.0F;

    while (!gTemp) {
        fm.pollEvents();
        defaultFb.bind();
        if (gColor) {
            r += 0.01F;
            r = r > 1.0F ? 1.0F : r;
        }
        defaultFb.clear(true);

        simpleShader.bind();
        glUniform4f(uniform.mLocation, r, 0.5f, 0.5f, 1.0f);
        ASSERT_GL();
        glEnableVertexAttribArray(simpleShader.getAttribute("pos"_sid).mLocation);
        ASSERT_GL();
        glDrawElements(GL_TRIANGLES, iData.size(), GL_UNSIGNED_INT, nullptr);
        ASSERT_GL();
        simpleShader.unbind();

        defaultFb.markUnbound();
        frame.swapBuffers();
    }

    return 0;
}
