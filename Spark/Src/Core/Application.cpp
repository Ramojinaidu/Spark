#include "Application.h"
#include "../Utils/Assert.h"
#include "Core/Window.h"
#include <GLFW/glfw3.h>
#include <memory>

namespace Spark {

Application* Application::s_Instance = nullptr;
std::unique_ptr<Window> Application::m_Window = nullptr;

Application::Application(const ApplicationSpec& specs)
    : m_Specifications(specs) {

    SPARK_ASSERT(s_Instance == nullptr, "Appplication already initialized")
    s_Instance = this;

    m_Running = true;

    m_Window = Window::GetWindow(m_Specifications.Title);
    SPARK_ASSERT(m_Window, "window creation failed")
}

Application::~Application() {}

void Application::Run() {

    while (m_Running) {
        m_Window->OnUpdate();
    }
}

void Application::stop() { m_Running = false; }

} // namespace Spark
