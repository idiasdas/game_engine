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

#define BIT(x) (1 << x)
