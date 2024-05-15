#include "dds_enginepch.h"
#include "Application.h"
#include <glad/glad.h>
#include "Input.h"
#include "glm/glm.hpp"
namespace dds
{

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

    Application *Application::s_Instance = nullptr;

    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType Type)
    {
        switch (Type)
        {
        case ShaderDataType::Float:     return GL_FLOAT;
        case ShaderDataType::Float2:    return GL_FLOAT;
        case ShaderDataType::Float3:    return GL_FLOAT;
        case ShaderDataType::Float4:    return GL_FLOAT;
        case ShaderDataType::Mat3:      return GL_FLOAT;
        case ShaderDataType::Mat4:      return GL_FLOAT;
        case ShaderDataType::Int:       return GL_INT;
        case ShaderDataType::Int2:      return GL_INT;
        case ShaderDataType::Int3:      return GL_INT;
        case ShaderDataType::Int4:      return GL_INT;
        case ShaderDataType::Bool:      return GL_BOOL;
        }

        DDS_CORE_ASSERT(false, "Unknown Shader Data Type.");

        return 0;
    }

    Application::Application()
    {
        DDS_CORE_ASSERT(!s_Instance, "Application already exists");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallBack(BIND_EVENT_FN(&Application::OnEvent));

        m_ImGuiLayer = new dds::ImGuiLayer();
        PushOverlay(m_ImGuiLayer);

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.1f, 0.1f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.1f, 0.8f, 0.1f, 1.0f,
            0.0f, 0.5f, 0.0f, 0.1f, 0.1f, 0.8f, 1.0f,
        };

        m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));


        m_VertexBuffer->SetLayout({
            {ShaderDataType::Float3, "a_Position"},
            {ShaderDataType::Float4, "a_Color"},
            // {ShaderDataType::Float3, "a_Normal"}
        });

        uint32_t index = 0;
        const auto& layout = m_VertexBuffer->GetLayout();
        for( BufferElement element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.GetElementCount(), ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE,  layout.GetStride() , (void*) element.Offset);
            index++;
        }



        uint32_t indices[3] = {0, 1, 2};
        m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

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

        m_Shader.reset(Shader::Create(vertexSrc, fragmentSrc));
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

            m_Shader->Bind();
            glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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
