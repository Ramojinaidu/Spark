#pragma once
#include "Spark/Events/Event.h"

namespace Spark{

    class MouseButtonEvent : public Event{
    public:
        MouseButtonEvent(const MouseButton& button, const KeyAction& action)
            :m_Button(button),m_Action(action){}

        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << ": " << static_cast<int>(m_Button) << " , Action: " << static_cast<int>(m_Action);
            return ss.str();
        }

        inline const MouseButton& GetMouseButton(){
            return m_Button;
        }

        inline const KeyAction& GetMouseButtonAction(){
            return m_Action;
        }

        EVENT_CLASS_TYPE(MouseButtonPress);
        EVENT_CLASS_CATEGORY(EventCategoryMouse);

    private:
        MouseButton m_Button;
        KeyAction m_Action;
    };

    class MouseScrollEvent : public Event{
    public:
        MouseScrollEvent(double xoffset, double yoffset)
            :m_Xoffset(xoffset),m_Yoffset(yoffset){}

        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << ": " << m_Xoffset << " X " << m_Yoffset;
            return ss.str();
        }

        inline double GetYoffset(){
            return m_Yoffset;
        }

        inline double GetXoffset(){
            return m_Xoffset;
        }

        EVENT_CLASS_TYPE(MouseScroll);
        EVENT_CLASS_CATEGORY(EventCategoryMouse);

    private:
        double m_Xoffset,m_Yoffset;
    };

    class MouseMoveEvent : public Event{
    public:
        MouseMoveEvent(double xpos, double ypos)
            :m_Xpos(xpos),m_Ypos(ypos){}

        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << ": " << m_Xpos << " X " << m_Ypos;
            return ss.str();
        }

        inline double GetYposition(){
            return m_Ypos;
        }

        inline double GetXposition(){
            return m_Xpos;
        }

        EVENT_CLASS_TYPE(MouseMove);
        EVENT_CLASS_CATEGORY(EventCategoryMouse);

    private:
        double m_Xpos,m_Ypos;
    };
}
