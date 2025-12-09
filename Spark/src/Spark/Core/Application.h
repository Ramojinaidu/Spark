#pragma once
#include "Event.h"
#include "GLFW/glfw3.h"

namespace Spark
{

    class Application {

    public:
        Application();
        ~Application();
        void Run();
        void OnEvent(Event& event);
        void OnStop(){m_Running = false;}

    private:
        bool m_Running = true;
        GLFWwindow* window = nullptr;

    };

    Application* CreateApplication();

}
