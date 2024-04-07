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
    }

    void OnEvent(dds::Event& event) override
    {
        DDS_TRACE("{0}", event);
    }

};

class TestApp : public dds::Application
{
public:
    TestApp()
    {
        PushLayer(new ExampleLayer());
    }
    ~TestApp()
    {

    }
};

dds::Application* dds::CreateApplication()
{
    return new TestApp();
}
