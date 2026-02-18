#include "Glfw_Window.h"
#include "Core/Window.h"
#include "GLFW/glfw3.h"

namespace Spark {

GLFWwindow* Glfw_Window::m_Window = nullptr;

Glfw_Window::Glfw_Window(const WindowProps& props) {

    WindowData.Title = props.Title;
    WindowData.Width = props.Width;
    WindowData.Height = props.Height;
    WindowData.VSync = props.VSync;

    if (!glfwInit()) {
        glfwTerminate();
    }

    m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(),
                                nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);

    glfwSetWindowUserPointer(m_Window, &WindowData);
}

Glfw_Window::~Glfw_Window() {

    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Glfw_Window::OnUpdate() {

    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Glfw_Window::IsVSync() const { return WindowData.VSync; }

void Glfw_Window::SetVSync(bool set) { WindowData.VSync = set; }

} // namespace Spark
