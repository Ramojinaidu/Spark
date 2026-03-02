#ifndef LAYERS_H
#define LAYERS_H
#include "../pch.h"
#include "Events/Events.h"
namespace Spark {

class Layer {
  public:
    Layer(std::string_view name = "Layer");
    virtual ~Layer() = default;

    virtual void OnAttach() = 0;
    virtual void OnDetach() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnImGuiRender() = 0;
    virtual void OnEvent(Event& e) = 0;

    const std::string& GetName() const { return m_Name; }

  private:
    std::string m_Name;
};

class LayerStack {
  public:
    LayerStack() = default;
    ~LayerStack();

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);
    void PopLayer(Layer* layer);
    void PopOverlay(Layer* overlay);

    std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
    std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
    std::vector<Layer*>::iterator end() { return m_Layers.end(); }
    std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

  private:
    std::vector<Layer*> m_Layers;
    unsigned int m_LayerInsertIndex = 0;
};
} // namespace Spark

#endif // LAYERS_H
