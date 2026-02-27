#include "Window.h"
#include "ExternalApi/GlfwWindow/Glfw_Window.h"

namespace Spark {

std::shared_ptr<Window> Window::GetWindow(const WindowProps& props) {

    return std::make_shared<Glfw_Window>(props);
}

} // namespace Spark
