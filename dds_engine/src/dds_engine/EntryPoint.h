#pragma once

extern dds::Application* dds::CreateApplication();

int main(int argc, char** argv) {
    dds::Log::Init();

    DDS_CORE_INFO("Engine Initialized");
    DDS_INFO("Client Initialized");

    auto app = dds::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
