#include <dds_engine.h>

class ExampleLayer : public dds::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
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
