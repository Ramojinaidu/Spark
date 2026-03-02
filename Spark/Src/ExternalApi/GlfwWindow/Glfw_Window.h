#ifndef GLFWWINDOW_H
#define GLFWWINDOW_H

#include "Core/Window.h"
#include "../pch.h"
#include <GLFW/glfw3.h>

namespace Spark {
class Glfw_Window : public Window {
  public:
    Glfw_Window(const WindowProps& props = WindowProps());
    ~Glfw_Window();

    virtual uint32_t GetWidth() const override { return m_WindowData.Width; }
    virtual uint32_t GetHeight() const override { return m_WindowData.Height; }

    virtual void SetVSync(bool set) override;
    virtual bool IsVSync() const override;

    virtual void SetWindowCallBacksFunc(const WindowCallbackFunc& func) override;

    virtual void OnUpdate() override;

    virtual void* GetNativeWindow() override;

  private:
    struct WindowData {
        std::string Title;
        bool Minimized;
        bool VSync;
        uint32_t Width;
        uint32_t Height;
        WindowCallbackFunc callbackfunc;
    } m_WindowData;

    static GLFWwindow* m_Window;
};

} // namespace Spark

#endif
