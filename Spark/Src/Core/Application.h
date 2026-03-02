#ifndef APPLICATION_H
#define APPLICATION_H

#include "../pch.h"
#include "Core/Layers.h"
#include "Events/ApplicationEvents.h"
#include "ExternalApi/Imgui_ui/ImguiLayer.h"
#include "Window.h"
namespace Spark {

struct ApplicationSpec {

    WindowProps window;
    ImguiLayerSpecs Imgui;
};

class Application {
  public:
    Application(const ApplicationSpec& spec = ApplicationSpec());
    ~Application();

    void Run();
    void stop();

    void OnEvent(Event& event);
    bool OnWindowClose(WindowCloseEvent& event);
    bool OnWindowMinimize(WindowMinimizeEvent& event);

    void PushLayer(Layer*);
    void PushOverlay(Layer*);

    void PopLayer(Layer*);
    void PopOverlay(Layer*);

    std::shared_ptr<Window> GetWindow();

    static Application& Get();
  private:
    bool m_Running = true;
    bool m_Minimized = false;
    ImguiLayer* m_ImguiLayer;
    LayerStack m_LayerStack;
    static std::shared_ptr<Window> m_Window;

  private:
    const ApplicationSpec& m_Specifications;
    static Application* s_Instance;
};

Application* Create();

} // namespace Spark

#endif
