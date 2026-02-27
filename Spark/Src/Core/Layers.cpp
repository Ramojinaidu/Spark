#include "Layers.h"

namespace Spark {
Layer::Layer(std::string_view name) : m_Name(name) {}

LayerStack::~LayerStack() {
    for (Layer* t : m_Layers) {

        t->OnDetach();
        delete t;
    }
}

void LayerStack::PushLayer(Layer* layer) { m_Layers.emplace_back(layer); }

void LayerStack::PushOverlay(Layer* overlay) {
    m_Layers.emplace(m_Layers.begin(), overlay);
}

void LayerStack::PopLayer(Layer* layer) {
    auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
    if (it != m_Layers.end()) {
        m_Layers.erase(it);
    }
}

void LayerStack::PopOverlay(Layer* overlay) {
    auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
    if (it != m_Layers.end()) {
        m_Layers.erase(it);
    }
}
} // namespace Spark
