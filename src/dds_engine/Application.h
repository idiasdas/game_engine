#pragma once

namespace dds{

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // Defined in the client application
    Application*  CreateApplication();

}
