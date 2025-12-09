#pragma once
#include "Spark/Core/Window.h"
#include <GLFW/glfw3.h>

namespace Spark {


    class GlfwWindow : public Window {
    public:
        GlfwWindow(const WindowProps& props);
        virtual ~GlfwWindow() override;

        virtual void OnUpdate() override;

        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;

        virtual uint32_t GetWidth() const override;
        virtual uint32_t GetHeight() const override;

        virtual void SetWindowEventCallback(WindowEventCallbackFunc callback) override;

    private:
        GLFWwindow* m_Window;

        struct WindowData {
            std::string title;
            uint32_t width;
            uint32_t height;
            bool vsync;
            WindowEventCallbackFunc callback;
        };

        WindowData m_Data;
    };
}
