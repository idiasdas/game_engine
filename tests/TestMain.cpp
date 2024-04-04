#include <dds_engine.h>

class TestApp : public dds::Application
{
public:
    TestApp()
    {

    }
    ~TestApp()
    {

    }
};

dds::Application* dds::CreateApplication()
{
    return new TestApp();
}
