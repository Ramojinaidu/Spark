#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H

#include "Events/Events.h"

namespace Spark {

class MouseButtonEvent : public Event {
  public:
    MouseButtonEvent(uint32_t button, uint32_t action, uint32_t mods)
        : m_Button(button), m_Action(action), m_Mods(mods) {}

    std::string ToString() const override {
        std::stringstream ss;
        ss << GetName() << ":{  " << m_Button << " , " << m_Action << " , "
           << m_Mods << " }";
        return ss.str();
    }

    inline uint32_t GetMouseButton() const { return m_Button; }
    inline uint32_t GetMod() const { return m_Mods; }
    inline uint32_t GetMouseButtonAction() const { return m_Action; }

    EVENT_CLASS_TYPE(MousePressed);
    EVENT_CLASS_CATEGORY(MouseCategory);

  private:
    uint32_t m_Button;
    uint32_t m_Action;
    uint32_t m_Mods;
};

class MouseScrollEvent : public Event {
  public:
    MouseScrollEvent(double xoffset, double yoffset)
        : m_Xoffset(xoffset), m_Yoffset(yoffset) {}

    std::string ToString() const override {
        std::stringstream ss;
        ss << GetName() << ": " << m_Xoffset << " x " << m_Yoffset;
        return ss.str();
    }

    inline double GetYoffset() { return m_Yoffset; }

    inline double getxoffset() { return m_Xoffset; }

    EVENT_CLASS_TYPE(MouseScroll);
    EVENT_CLASS_CATEGORY(MouseCategory);

  private:
    double m_Xoffset, m_Yoffset;
};

class MouseMoveEvent : public Event {
  public:
    MouseMoveEvent(double xpos, double ypos) : m_Xpos(xpos), m_Ypos(ypos) {}

    std::string ToString() const override {
        std::stringstream ss;
        ss << GetName() << ": " << m_Xpos << " x " << m_Ypos;
        return ss.str();
    }

    inline double getyposition() { return m_Ypos; }

    inline double getxposition() { return m_Xpos; }

    EVENT_CLASS_TYPE(MouseMoved);
    EVENT_CLASS_CATEGORY(MouseCategory);

  private:
    double m_Ypos, m_Xpos;
};
} // namespace Spark

#endif
