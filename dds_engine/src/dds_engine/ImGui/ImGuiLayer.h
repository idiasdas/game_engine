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

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}
