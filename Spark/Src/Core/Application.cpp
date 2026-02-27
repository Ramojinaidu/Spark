#include "Application.h"
#include "Core/Layers.h"
#include "Core/Window.h"
#include "ExternalApi/Imgui_ui/ImguiLayer.h"
#include "Utils/Assert.h"
#include "Utils/Logger.h"
#include "defines.h"

namespace Spark {

Application* Application::s_Instance = nullptr;
std::shared_ptr<Window> Application::m_Window = nullptr;

Application::Application(const ApplicationSpec& specs)
    : m_Specifications(specs) {

    SPARK_ASSERT(s_Instance == nullptr, "Appplication already initialized")
    s_Instance = this;

    m_Window = Window::GetWindow(m_Specifications.window);
    SPARK_ASSERT(m_Window, "window creation failed")

    m_Window->SetWindowCallBacksFunc(SP_BIND_FUNC(Application::OnEvent));

    if (m_Specifications.Imgui.EnableImgui) {

        m_ImguiLayer = new ImguiLayer(m_Specifications.Imgui);
        m_LayerStack.PushOverlay(m_ImguiLayer);
        m_ImguiLayer->OnAttach();
    }
}

Application::~Application() {}

void Application::Run() {

    while (m_Running) {
        m_Window->OnUpdate();
        if (!m_Minimized) {

            for (Layer* it : m_LayerStack) {
                (*it).OnUpdate();
            }

            if (m_Specifications.Imgui.EnableImgui) {
                m_ImguiLayer->Begin();
                for (Layer* it : m_LayerStack) {
                    (*it).OnImGuiRender();
                }
                m_ImguiLayer->End();
            }
        }
    }
}

void Application::OnEvent(Event& e) {
    SPARK_DBUG(e.ToString())

    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(
        SP_BIND_FUNC(Application::OnWindowClose));
    dispatcher.Dispatch<WindowMinimizeEvent>(
        SP_BIND_FUNC(Application::OnWindowMinimize));

    for (std::vector<Layer*>::reverse_iterator it = m_LayerStack.rbegin();
         it != m_LayerStack.rend(); ++it) {

        (*it)->OnEvent(e);
        if (e.IsHandled())
            break;
    }
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

std::shared_ptr<Window> Application::GetWindow() { return m_Window; }

} // namespace Spark
