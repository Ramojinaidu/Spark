#ifndef Window_H
#define Window_H

#include "../defines.h"
#include "../pch.h"

namespace Spark {

struct WindowProps {

    uint32_t Width;
    uint32_t Height;
    std::string Title;
    bool VSync;

    WindowProps(const std::string& title = "Spark Window", uint32_t width = 900,
                uint32_t height = 600, bool vsync = true)
        : Width(width), Height(height), Title(title), VSync(vsync) {}
};

class Window {

  public:
    virtual ~Window() = default;

    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;

    virtual void SetVSync(bool set) = 0;
    virtual bool IsVSync() const = 0;

    virtual void OnUpdate() = 0;

    static std::unique_ptr<Window>
    GetWindow(const WindowProps& props = WindowProps());
};

} // namespace Spark

#endif
