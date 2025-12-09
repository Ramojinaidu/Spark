#pragma once

#include <cassert>
#include <string>

namespace Spark {

#define BIT(x) (1 << x)

    enum class EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
    };

    enum class EventType {
        None = 0,
        WindowClose,
        WindowResize,
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
        bool Handled = false;

    };

   	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
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
