#pragma once

#ifdef DDS_BUILD_LIB
    #define DDS_API __attribute__((visibility("default")))
#else
    #define DDS_API
#endif
