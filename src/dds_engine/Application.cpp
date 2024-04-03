#include "Application.h"
#include <iostream>

namespace dds{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        std::cout << "Hello, DDS Engine! Application is running..." << '\n';
        while(true);
    }
}
