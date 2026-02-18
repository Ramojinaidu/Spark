#include "Window.h"
#include "../ExternalApi/GlfwWindow/Glfw_Window.h"

namespace Spark {

std::unique_ptr<Window> Window::GetWindow(const WindowProps& props) {

    return std::make_unique<Glfw_Window>(props);
}

} // namespace Spark
