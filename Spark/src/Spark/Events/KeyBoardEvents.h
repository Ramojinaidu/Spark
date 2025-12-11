#pragma once
#include "Spark/Events/Event.h"


namespace Spark {

    class KeyEvent : public Event{
    public:
        KeyEvent(int key,const KeyAction& action)
            : m_Key(key),m_Action(action) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << ": " << (char)m_Key << " , Action: " << static_cast<int>(m_Action);
            return ss.str();
        }

        inline const KeyAction& GetKeyAction(){
            return m_Action;
        }

        inline int GetKey(){
            return m_Key;
        }
        EVENT_CLASS_TYPE(KeyPressed);
        EVENT_CLASS_CATEGORY(EventCategoryKeyBoard);

    private:
        int m_Key;
        KeyAction m_Action;
    };

}
