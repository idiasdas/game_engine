#pragma once

#include "dds_engine/Layer.h"
#include "dds_engine/Events/MouseEvent.h"
#include "dds_engine/Events/KeyEvent.h"
#include "dds_engine/Events/ApplicationEvent.h"

namespace dds {

    class DDS_ENGINE_EXPORT ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
        bool OnMouseMovedEvent(MouseMovedEvent& event);
        bool OnMouseScrolledEvent(MouseScrolledEvent& event);
        bool OnKeyPressedEvent(KeyPressedEvent& event);
        bool OnKeyReleasedEvent(KeyReleasedEvent& event);
        bool OnKeyTypedEvent(KeyTypedEvent& event);
        bool OnWindowResizeEvent(WindowResizeEvent& event);
    private:
        float m_Time = 0.0f;
    };
}
