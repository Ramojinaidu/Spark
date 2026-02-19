#ifndef EVENTS_H
#define EVENTS_H

#include "../pch.h"

namespace Spark {

enum class EventCategory {
    ApplicationCategory = 0,
    KeyBoardCategory,
    MouseCategory,
};

enum class EventType {
    //--- Application Events ---
    WindowClose,
    WindowResize,
    WindowMinimize,
    //--- KeyBoard Events ---
    KeyPressed,
    KeyReleased,
    //---Mouse Events ---
    MousePressed,
    MouseScroll,
    MouseMoved,

};

#define EVENT_CLASS_TYPE(type)                                                 \
    static EventType GetStaticType() { return EventType::type; }               \
    virtual EventType GetType() const override { return GetStaticType(); }     \
    virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)                                         \
    virtual EventCategory GetCategory() const override {                       \
        return EventCategory::category;                                        \
    }

class Event {
  public:
    virtual ~Event() = default;

    virtual EventType GetType() const = 0;
    virtual EventCategory GetCategory() const = 0;
    virtual const char* GetName() const = 0;
    virtual std::string ToString() const { return GetName(); };

    inline bool IsHandled() const { return m_Handled; }
    inline void SetHandled(bool handled) { m_Handled = handled; }

  private:
    bool m_Handled = false;
};

class EventDispatcher {
  public:
    EventDispatcher(Event& event) : m_Event(event) {}

    template <typename T> bool Dispatch(const std::function<bool(T&)>& func) {
        if (m_Event.GetType() == T::GetStaticType()) {
            m_Event.SetHandled(func(static_cast<T&>(m_Event)));
            return true;
        }
        return false;
    }

  private:
    Event& m_Event;
};

} // namespace Spark

#endif
