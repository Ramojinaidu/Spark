#pragma once
#include <cstdint>
#include <memory>
#include <string>

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

    class Window
    {
    public:
        virtual ~Window()=default;

        virtual void OnUpdate()=0;
        virtual bool IsClosed() const = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());

    };
}
