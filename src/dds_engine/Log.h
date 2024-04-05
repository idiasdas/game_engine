#pragma once

#include <memory>
#include <iostream>
#include "Core.h"

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>
#include "spdlog/sinks/stdout_color_sinks.h"


namespace dds {
    class DDS_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };
}

// Core log macros
#define DDS_CORE_TRACE(...)    ::dds::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DDS_CORE_INFO(...)     ::dds::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DDS_CORE_WARN(...)     ::dds::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DDS_CORE_ERROR(...)    ::dds::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DDS_CORE_FATAL(...)    ::dds::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DDS_TRACE(...)         ::dds::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DDS_INFO(...)          ::dds::Log::GetClientLogger()->info(__VA_ARGS__)
#define DDS_WARN(...)          ::dds::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DDS_ERROR(...)         ::dds::Log::GetClientLogger()->error(__VA_ARGS__)
#define DDS_FATAL(...)         ::dds::Log::GetClientLogger()->fatal(__VA_ARGS__)
