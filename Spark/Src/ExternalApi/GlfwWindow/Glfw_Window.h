#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H

#include "../../Core/Window.h"
#include "../pch.h"

#include <GLFW/glfw3.h>

namespace Spark {
class Glfw_Window : public Window {
  public:
    Glfw_Window(const WindowProps& props = WindowProps());
    ~Glfw_Window();

    virtual uint32_t GetWidth() const override { return WindowData.Width; }
    virtual uint32_t GetHeight() const override { return WindowData.Height; }

    virtual void SetVSync(bool set) override;
    virtual bool IsVSync() const override;

    virtual void OnUpdate() override;

  private:
    struct WindowData {
        std::string Title;
        bool VSync;
        uint32_t Width;
        uint32_t Height;
    } WindowData;

    static GLFWwindow* m_Window;
};
} // namespace Spark

#endif
