#include "glfw_window.h"
#include "Spark/Events/ApplicationEvents.h"
#include <GLFW/glfw3.h>

namespace Spark {
    GlfwWindow::GlfwWindow(const WindowProps& props) {

        m_Data.title = props.Title;
        m_Data.width = props.Width;
        m_Data.height = props.Height;
        m_Data.callback = nullptr;

        if (!glfwInit()) {
            glfwTerminate();
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);

        glfwSetWindowUserPointer(m_Window,&m_Data);

        glfwMakeContextCurrent(m_Window);
        SetVSync(true);

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.callback(event);
		});

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.callback(event);
		});
    }

    GlfwWindow::~GlfwWindow() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
    void GlfwWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void GlfwWindow::SetVSync(bool enabled) {
        glfwSwapInterval(enabled ? 1 : 0);
        m_Data.vsync = enabled;
    }

    uint32_t GlfwWindow::GetWidth() const {
        return m_Data.width;
    }

    uint32_t GlfwWindow::GetHeight() const {
        return m_Data.height;
    }

    bool GlfwWindow::IsVSync() const {
        return m_Data.vsync;
    }

    void GlfwWindow::SetWindowEventCallback(WindowEventCallbackFunc callback) {
        m_Data.callback = callback;
    }

}
