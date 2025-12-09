#define GLFW_INCLUDE_NONE
#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Spark
{
    Application::Application()
    {
        if (!glfwInit()) {
            glfwTerminate();
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(600, 400, "Spark", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glViewport(0, 0, 600, 400);
    }

    Application::~Application()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Application::Run()
    {
        while (!glfwWindowShouldClose(window)) {

            glClearColor(0.2,0.2,0.2,0.2);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();

        }

    }

    void Application::OnEvent(Event& e)
    {

    }
}
