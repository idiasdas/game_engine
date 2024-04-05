#pragma once

extern dds::Application* dds::CreateApplication();

int main(int argc, char** argv) {

    dds::Log::Init();
    dds::Log::GetCoreLogger()->info("Engine Initialized");
    dds::Log::GetClientLogger()->info("Client Initialized");

    std::cout << "Creating Client Application" << std::endl;
    auto app = dds::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
