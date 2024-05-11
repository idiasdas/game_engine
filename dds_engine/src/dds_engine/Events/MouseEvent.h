#pragma once

#include "Event.h"

namespace dds {

    class DDS_ENGINE_EXPORT MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };


    class DDS_ENGINE_EXPORT MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_xOffset(xOffset), m_yOffset(yOffset) {}

        inline float GetXOffset() const { return m_xOffset; }
        inline float GetYOffset() const { return m_yOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_xOffset, m_yOffset;
    };


    class DDS_ENGINE_EXPORT MouseButtomEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtomEvent(int button)
            : m_Button(button) {}

        int m_Button;
    };


    class DDS_ENGINE_EXPORT MouseButtonPressedEvent : public MouseButtomEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtomEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };


    class DDS_ENGINE_EXPORT MouseButtonReleasedEvent : public MouseButtomEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtomEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}
