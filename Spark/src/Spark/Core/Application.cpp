#include "Spark/Core/Application.h"
#include "Spark/Core/Core.h"
#include "Spark/Events/ApplicationEvents.h"


#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Spark
{
    Application::Application(const ApplicationSpecs& specs)
    {
        m_Specs = specs;
        m_Window = Window::Create(m_Specs.Title);

        m_Window->SetWindowEventCallback(SP_BIND_FUNC(Application::OnEvent));

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        glViewport(0, 0, 600, 400);
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Running) {


            glClearColor(0.2,0.2,0.2,0.2);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();

        }

    }

    void Application::OnEvent(Event& e)
    {
        std::cout<<e<<"\n";
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(SP_BIND_FUNC(Application::OnWindowClose));
        dispatcher.Dispatch<WindowMinimizeEvent>(SP_BIND_FUNC(Application::OnWindowMinimize));

    }

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnWindowMinimize(WindowMinimizeEvent& event)
    {
        m_Minimized = event.IsMinimized();
        return true;
    }

}
