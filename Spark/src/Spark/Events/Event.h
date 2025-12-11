#pragma once

#include <cassert>
#include <string>
#include <functional>
#include <sstream>


#include "Spark/Core/Core.h"


namespace Spark {

    enum class KeyAction{
        KeyPressed=0,
        KeyReleased,
        KeyHold,
    };

    enum class MouseButton{
        LeftButton=0,
        RightButton,
        MiddleButton,
    };

    enum class EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryKeyBoard = BIT(1),
        EventCategoryMouse = BIT(2),
    };

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowMinimize,
        KeyPressed,
        MouseButtonPress,MouseScroll,MouseMove,

    };

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                  virtual EventType GetType() const override { return GetStaticType(); }\
                                  virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual EventCategory GetCategory() const override { return EventCategory::category; }

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

    class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(const std::function<bool(T&)>& func)
		{
			if (m_Event.GetType() == T::GetStaticType())
			{
				m_Event.SetHandled(func(static_cast<T&>(m_Event)));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
