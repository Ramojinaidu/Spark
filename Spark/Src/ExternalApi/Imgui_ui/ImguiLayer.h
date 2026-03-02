#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H
#include "Core/Layers.h"
#include "imgui.h"

namespace Spark {

struct ImguiLayerSpecs {
    bool EnableImgui = true;
    bool EnableViewports = false;
    bool EnableDockSpace = true;
};

class ImguiLayer : public Layer {
  public:
    ImguiLayer(const ImguiLayerSpecs& specs = ImguiLayerSpecs());
    ~ImguiLayer();
    void Begin();
    void End();
    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override;
    virtual void OnImGuiRender() override;
    virtual void OnEvent(Event& e) override;

  private:
    bool m_EnableViewPorts;
    bool m_EnableDocking;
};
} // namespace Spark
#endif
