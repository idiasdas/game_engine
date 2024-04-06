#include "dds_enginepch.h"
#include "Application.h"
#include "dds_engine/Events/ApplicationEvent.h"


namespace dds{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        DDS_TRACE("Application running");
        WindowResizeEvent e(1280, 720);
        if(e.IsInCategory(EventCategoryApplication))
        {
            DDS_TRACE(e);
        }
        if(e.IsInCategory(EventCategoryInput))
        {
            DDS_TRACE(e);
        }
        while(true);
    }
}
