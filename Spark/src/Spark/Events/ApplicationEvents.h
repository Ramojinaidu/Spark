#pragma once

#include "Spark/Events/Event.h"
#include <string>
#include <sstream>
#include <cstdint>

namespace Spark {

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(uint32_t width, uint32_t height)
            : m_Width(width), m_Height(height) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << ": " << m_Width << "x" << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);
    private:
        uint32_t m_Width;
        uint32_t m_Height;
    };

    class WindowCloseEvent : public Event {
    public:
        EVENT_CLASS_TYPE(WindowClose);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };


}
