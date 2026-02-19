#include "Application.h"
#include "../Utils/Assert.h"
#include "Core/Window.h"
#include "Utils/Logger.h"
#include "defines.h"
#include <GLFW/glfw3.h>

namespace Spark {

Application* Application::s_Instance = nullptr;
std::unique_ptr<Window> Application::m_Window = nullptr;

Application::Application(const ApplicationSpec& specs)
    : m_Specifications(specs) {

    SPARK_ASSERT(s_Instance == nullptr, "Appplication already initialized")
    s_Instance = this;

    m_Window = Window::GetWindow(m_Specifications.Title);
    SPARK_ASSERT(m_Window, "window creation failed")

    m_Window->SetWindowCallBacksFunc(SP_BIND_FUNC(Application::OnEvent));
}

Application::~Application() {}

void Application::Run() {

    while (m_Running) {
        m_Window->OnUpdate();
    }
}

void Application::OnEvent(Event& e) {
    SPARK_DBUG(e.ToString())
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(
        SP_BIND_FUNC(Application::OnWindowClose));
    dispatcher.Dispatch<WindowMinimizeEvent>(
        SP_BIND_FUNC(Application::OnWindowMinimize));
}

bool Application::OnWindowClose(WindowCloseEvent& event) {
    m_Running = false;
    return true;
}

bool Application::OnWindowMinimize(WindowMinimizeEvent& event) {
    m_Minimized = event.IsMinimized();
    return true;
}

void Application::stop() { m_Running = false; }

} // namespace Spark
