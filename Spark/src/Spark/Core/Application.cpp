#include "Spark/Core/Application.h"
#include "Spark/Events/Event.h"
#include "Spark/Events/ApplicationEvents.h"
#include "Spark/Core/Window.h"

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Spark
{
    Application::Application(const ApplicationSpecs& specs)
    {
        m_Specs = specs;
        m_Window = Window::Create(m_Specs.Title);

        m_Window->SetWindowEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

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
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

    }

    bool Application::OnWindowClose(WindowCloseEvent& event)
    {
        m_Running = false;
        return true;
    }

}
