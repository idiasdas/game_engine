#pragma once

extern dds::Application* dds::CreateApplication();

int main(int argc, char** argv) {
    std::cout << "Creating Client Application" << std::endl;
    auto app = dds::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
