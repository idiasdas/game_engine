#pragma once
#ifdef DDS_PLATFORM_WINDOWS
    #ifdef DDS_BUILD_LIB
        #define DDS_API __declspec(dllexport)
    #else
        #define DDS_API __declspec(dllimport)
    #endif
#else
    #ifdef DDS_PLATFORM_LINUX
        #ifdef DDS_BUILD_LIB
            #define DDS_API __attribute__((visibility("default")))
        #else
            #define DDS_API
        #endif
    #else
        #error "Platform not supported"
    #endif
#endif


#ifdef DDS_ENABLE_ASSERTS
    #define DDS_ASSERT(x, ...) { if(!(x)) { DDS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __asm__ __volatile__("int3"); } }
    #define DDS_CORE_ASSERT(x, ...) { if(!(x)) { DDS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __asm__ __volatile__("int3"); } }
#else
    #define DDS_ASSERT(x, ...)
    #define DDS_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)
