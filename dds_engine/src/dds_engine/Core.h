#pragma once
#include "dds_export.h"

#ifdef DDS_ENABLE_ASSERTS
    #define DDS_ASSERT(x, ...) { if(!(x)) { DDS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __asm__ __volatile__("int3"); } }
    #define DDS_CORE_ASSERT(x, ...) { if(!(x)) { DDS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __asm__ __volatile__("int3"); } }
#else
    #define DDS_ASSERT(x, ...)
    #define DDS_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define DDS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
