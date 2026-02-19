#ifndef KEYBOARDEVENTS_H
#define KEYBOARDEVENTS_H

#include "Events/Events.h"

namespace Spark {

class KeyEvent : public Event {
  public:
    KeyEvent(uint32_t key, uint32_t scancode, uint32_t mods)
        : m_Key(key), m_Scancode(scancode), m_Mods(mods) {}

    inline uint32_t GetKey() const { return m_Key; }

    inline uint32_t GetScancode() const { return m_Scancode; }

    inline uint32_t GetMod() const { return m_Mods; }

  private:
    uint32_t m_Key;
    uint32_t m_Scancode;
    uint32_t m_Mods;
};

class KeyRelaseEvent : public KeyEvent {

  public:
    KeyRelaseEvent(uint32_t key, uint32_t scancode, uint32_t mods)
        : KeyEvent(key, scancode, mods) {}

    std::string ToString() const override {
        std::stringstream ss;
        ss << GetName() << ":{  " << GetKey() << " , " << GetScancode() << " , "
           << GetMod() << " }";
        return ss.str();
    }
    EVENT_CLASS_TYPE(KeyReleased);
    EVENT_CLASS_CATEGORY(KeyBoardCategory);
};

class KeyPressedEvent : public KeyEvent {

  public:
    KeyPressedEvent(uint32_t key, uint32_t scancode, uint32_t mods)
        : KeyEvent(key, scancode, mods) {}

    std::string ToString() const override {
        std::stringstream ss;
        ss << GetName() << " :{  " << GetKey() << " , " << GetScancode() << " , "
           << GetMod() << " }";
        return ss.str();
    }
    EVENT_CLASS_TYPE(KeyPressed);
    EVENT_CLASS_CATEGORY(KeyBoardCategory);
};

} // namespace Spark

#endif
