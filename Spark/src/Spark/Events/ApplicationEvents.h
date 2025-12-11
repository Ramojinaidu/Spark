#pragma once

#include <string>
#include <sstream>
#include <cstdint>

#include "Spark/Events/Event.h"

namespace Spark {

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(uint32_t width, uint32_t height)
            : m_Width(width), m_Height(height) {}

        inline int GetWidth(){
            return m_Width;
        }

        inline int GetHeight(){
            return m_Height;
        }

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

    class WindowMinimizeEvent : public Event{
    public:
        WindowMinimizeEvent(bool minimized):m_Minimized(minimized){}

        std::string ToString() const override{

            std::stringstream ss;
            ss << GetName() << ": " << m_Minimized;
            return ss.str();
        }

        inline bool IsMinimized(){
            return m_Minimized;
        }

        EVENT_CLASS_TYPE(WindowMinimize);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);

    private:
        bool m_Minimized;
    };


}
