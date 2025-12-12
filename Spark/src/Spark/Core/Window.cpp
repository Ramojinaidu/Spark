#include "Spark/Core/Window.h"
#include <MultiPlatform/glfw_window.h>

namespace Spark {
    std::unique_ptr<Window> Window::Create(const WindowProps& props) {
        return std::make_unique<GlfwWindow>(props);
    }
}
