#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace dds{

    class DDS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // Defined in the client application
    Application*  CreateApplication();

}
