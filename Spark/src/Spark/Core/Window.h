#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <functional>
#include "Spark/Events/Event.h"


namespace Spark
{
    struct WindowProps
    {
        std::string Title;
        int Width;
        int Height;

        WindowProps(const std::string& title = "Spark Engine",
                    uint32_t width = 1280,
                    uint32_t height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    using WindowEventCallbackFunc = std::function<void(Event&)>;

    class Window
    {
    public:
        virtual ~Window()=default;

        virtual void OnUpdate()=0;

        virtual inline void SetVSync(bool enabled) = 0;
        virtual inline bool IsVSync() const = 0;

        virtual void SetWindowEventCallback(WindowEventCallbackFunc callback) = 0;

        virtual inline uint32_t GetWidth() const = 0;
        virtual inline uint32_t GetHeight() const = 0;

        virtual inline bool IsMinimized() const = 0;

        static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
    };
}
