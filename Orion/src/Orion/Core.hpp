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

#define BIT(x) (1 << x)
