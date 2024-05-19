#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "dds_engine/ImGui/ImGuiLayer.h"

#include "dds_engine/Renderer/Buffer.h"
#include "dds_engine/Renderer/Shader.h"
#include "dds_engine/Renderer/VertexArray.h"
#include "Renderer/Cameras.h"

namespace dds
{

    class DDS_ENGINE_EXPORT Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);

        inline Window &GetWindow() { return *m_Window; }

        inline static Application &Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer *m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;

        std::shared_ptr<Shader> m_Shader_nocolor;
        std::shared_ptr<VertexArray> m_SquareVA;

        OrthographicCamera m_Camera;
    private:
        static Application *s_Instance;
    };

    // Defined in the client application
    Application *CreateApplication();

}
