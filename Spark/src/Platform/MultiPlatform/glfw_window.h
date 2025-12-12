#pragma once
#include "Spark/Core/Window.h"
#include "Spark/Events/Event.h"
#include <GLFW/glfw3.h>

namespace Spark {

    static inline KeyAction GlfwtoSpKeyAction(const int& action);

    class GlfwWindow : public Window {
    public:
        GlfwWindow(const WindowProps& props);
        virtual ~GlfwWindow() override;

        virtual void OnUpdate() override;

        virtual inline void SetVSync(bool enabled) override;
        virtual inline bool IsVSync() const override;

        virtual inline uint32_t GetWidth() const override;
        virtual inline uint32_t GetHeight() const override;

        virtual inline bool IsMinimized() const override;

        virtual void SetWindowEventCallback(WindowEventCallbackFunc callback) override;

    private:
        GLFWwindow* m_Window;

        struct WindowData {
            std::string title;
            uint32_t width;
            uint32_t height;
            bool vsync;
            bool minimzed;
            WindowEventCallbackFunc callback;
        };

        WindowData m_Data;
    };
}
