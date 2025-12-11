#pragma once
#include "Spark/Events/Event.h"
#include "Spark/Core/Window.h"
#include "Spark/Events/ApplicationEvents.h"
#include "Spark/Core/Core.h"

namespace Spark
{
    struct ApplicationSpecs{
        std::string Title;
        ApplicationSpecs(std::string title = "Spark") : Title(title) {}
    };

    class Application {

    public:
        Application(const ApplicationSpecs& specs = ApplicationSpecs());
        ~Application();
        void Run();
        void OnEvent(Event& event);
        bool OnWindowClose(WindowCloseEvent& event);
        bool OnWindowMinimize(WindowMinimizeEvent& event);

    private:
        ApplicationSpecs m_Specs;
        bool m_Running = true;
        bool m_Minimized = false;
        std::unique_ptr<Window> m_Window = nullptr;

    };

    Application* CreateApplication();

}
