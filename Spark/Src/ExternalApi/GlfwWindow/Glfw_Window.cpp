#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Core/Window.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyBoardEvents.h"
#include "Events/MouseEvents.h"
#include "Glfw_Window.h"


namespace Spark {

GLFWwindow* Glfw_Window::m_Window = nullptr;

Glfw_Window::Glfw_Window(const WindowProps& props) {

    m_WindowData.Title = props.Title;
    m_WindowData.Width = props.Width;
    m_WindowData.Height = props.Height;
    m_WindowData.VSync = props.VSync;
    m_WindowData.callbackfunc = nullptr;
    m_WindowData.Minimized = false;

    if (!glfwInit()) {
        glfwTerminate();
    }

    m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(),
                                nullptr, nullptr);
    SetVSync(true);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);         // 3.0+ only

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_WindowData);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glfwSetWindowSizeCallback(
        m_Window, [](GLFWwindow* window, int width, int height) {
            WindowData& data =
                *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.callbackfunc(event);
        });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
        WindowData& data =
            *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
        WindowCloseEvent event;
        data.callbackfunc(event);
    });

    glfwSetWindowIconifyCallback(
        m_Window, [](GLFWwindow* window, int minimized) {
            WindowData& data =
                *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            data.Width = 0;
            data.Height = 0;
            data.Minimized = minimized;

            WindowMinimizeEvent event(minimized);
            data.callbackfunc(event);
        });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode,
                                    int action, int mods) {
        WindowData& data =
            *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
        switch (action) {

        case GLFW_PRESS: {
            KeyPressedEvent event(key, scancode, mods);
            data.callbackfunc(event);
            break;
        }

        case GLFW_RELEASE: {
            KeyRelaseEvent event(key, scancode, mods);
            data.callbackfunc(event);
            break;
        }
        }
    });

    glfwSetMouseButtonCallback(
        m_Window, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data =
                *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            MouseButtonEvent event(button, action, mods);
            data.callbackfunc(event);
        });

    glfwSetScrollCallback(
        m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
            WindowData& data =
                *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            MouseScrollEvent event(xoffset, yoffset);
            data.callbackfunc(event);
        });

    glfwSetCursorPosCallback(
        m_Window, [](GLFWwindow* window, double xpos, double ypos) {
            WindowData& data =
                *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            MouseMoveEvent event(xpos, ypos);
            data.callbackfunc(event);
        });
}

Glfw_Window::~Glfw_Window() {

    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Glfw_Window::OnUpdate() {

    glfwPollEvents();

    glfwSwapBuffers(m_Window);
}

bool Glfw_Window::IsVSync() const { return m_WindowData.VSync; }

void Glfw_Window::SetVSync(bool set) {
    m_WindowData.VSync = set;
    glfwSwapInterval(set ? 1 : 0);
}

void Glfw_Window::SetWindowCallBacksFunc(const WindowCallbackFunc& func) {
    m_WindowData.callbackfunc = func;
}

void* Glfw_Window::GetNativeWindow() { return m_Window; }

} // namespace Spark
