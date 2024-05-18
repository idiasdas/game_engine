#include "dds_enginepch.h"
#include "Application.h"
#include <glad/glad.h>
#include "Input.h"
#include "glm/glm.hpp"
namespace dds
{

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        DDS_CORE_ASSERT(!s_Instance, "Application already exists");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallBack(BIND_EVENT_FN(&Application::OnEvent));

        m_ImGuiLayer = new dds::ImGuiLayer();
        PushOverlay(m_ImGuiLayer);

        m_VertexArray.reset(VertexArray::Create());

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.1f, 0.1f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.1f, 0.8f, 0.1f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.1f, 0.1f, 0.8f, 1.0f,
        };

        std::shared_ptr<VertexBuffer> m_VertexBuffer;
        m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

        m_VertexBuffer->SetLayout({
            {ShaderDataType::Float3, "a_Position"},
            {ShaderDataType::Float4, "a_Color"},
            // {ShaderDataType::Float3, "a_Normal"}
        });

        m_VertexArray->AddVertexBuffer(m_VertexBuffer);

        uint32_t indices[3] = {0, 1, 2};
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
        m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(m_IndexBuffer);

        m_SquareVA.reset(VertexArray::Create());

        float squareVertices[3 * 4] = {
            -0.75f, -0.75f, 0.0f,
             0.75f, -0.75f, 0.0f,
             0.75f,  0.75f, 0.0f,
            -0.75f,  0.75f, 0.0f,
        };

        std::shared_ptr<VertexBuffer> m_SquareVB;
        m_SquareVB.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
        m_SquareVB->SetLayout({
            {ShaderDataType::Float3, "a_Position"}
        });
        m_SquareVA->AddVertexBuffer(m_SquareVB);

        uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};
        std::shared_ptr<IndexBuffer> m_SquareIB;
        m_SquareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

        m_SquareVA->SetIndexBuffer(m_SquareIB);

        const std::string vertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            out vec4 v_Color;

            void main(){
                v_Color = a_Color;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        const std::string fragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;
            in vec4 v_Color;
            void main(){
                color = v_Color;
            }
        )";

        const std::string vertexSrc_nocolor = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;
            out vec3 v_Position;

            void main(){
                gl_Position = vec4(a_Position, 1.0);
                v_Position = a_Position;
            }
        )";

        const std::string fragmentSrc_nocolor = R"(
            #version 330 core

            layout(location = 0) out vec4 color;
            in vec3 v_Position;
            void main(){
                color = vec4(0.5, 0.3, 0.5, 1.0);
            }
        )";

        m_Shader.reset(Shader::Create(vertexSrc, fragmentSrc));
        m_Shader_nocolor.reset(Shader::Create(vertexSrc_nocolor, fragmentSrc_nocolor));
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(&Application::OnWindowClose));

        DDS_CORE_TRACE("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled) // TODO
                break;
        }
    }

    void Application::Run()
    {
        DDS_TRACE("Application running");

        while (m_Running)
        {
            glClearColor(0.1f, 0.1f, 0.5f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Shader_nocolor->Bind();
            m_SquareVA->Bind();
            glDrawElements(GL_TRIANGLES, m_SquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

            m_Shader->Bind();
            m_VertexArray->Bind();
            glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

            for (Layer *layer : m_LayerStack)
                layer->OnUpdate();

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();

            // auto[x, y] = Input::GetMousePosition();
            // DDS_CORE_TRACE("{0}, {1}",x , y);
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

}
