#pragma once

#ifdef ORI_PLATFORM_MAC
    #ifdef ORI_BUILD_DLL
        #define ORION_API
    #else
        #define ORION_API
    #endif
#else
    #error Orion only supports Mac
#endif

#ifdef ORI_ENABLE_ASSERTS
    #define ORI_ASSERT(x, ...) { if(!(x)) { ORI_ERROR("Assertion Failed: {0}", __VA_ARGS__);  __debugbreak(); }}
    #define ORI_CORE_ASSERT(x, ...) { if(!(x)) { ORI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);  __debugbreak(); }}
#else
    #define ORI_ASSERT(x, ...)
    #define ORI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
