#include <dds_engine.h>
#include "imgui.h"

class ExampleLayer : public dds::Layer
{
public:
    ExampleLayer()
        : Layer("ExampleLayer")
    {
    }

    void OnUpdate() override
    {
        DDS_INFO("ExampleLayer::Update");
        if(dds::Input::IsKeyPressed(DDS_KEY_TAB))
        {
            DDS_INFO("Tab key is pressed");
        }
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    void OnEvent(dds::Event& event) override
    {
        DDS_TRACE("{0}", event);
    }

};


class SandboxApp : public dds::Application
{
public:
    SandboxApp()
    {
        PushLayer(new ExampleLayer());
    }

    ~SandboxApp()
    {

    }
};

dds::Application* dds::CreateApplication()
{
    return new SandboxApp();
}
