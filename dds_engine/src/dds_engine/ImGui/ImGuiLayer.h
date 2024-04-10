#pragma once

#include "dds_engine/Layer.h"

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
        float m_Time = 0.0f;
    };
}
