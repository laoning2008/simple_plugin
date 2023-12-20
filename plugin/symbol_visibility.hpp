#pragma once

#ifndef PLUGIN_API
    #ifdef _WIN32
          /* Windows - set up dll import/export decorators. */
        # if defined(BUILDING_PLUGIN_API)
            /* Building shared library. */
        #   define PLUGIN_API extern "C" __declspec(dllexport)
        # else
            /* Using shared library. */
        #   define PLUGIN_API extern "C" __declspec(dllimport)
        #endif
    #elif __GNUC__ >= 4
        # define PLUGIN_API extern "C" __attribute__((visibility("default")))
    #elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x550) /* Sun Studio >= 8 */
        # define PLUGIN_API extern "C" __global
    #else
        # define PLUGIN_API extern "C"
    #endif
#endif /* PLUGIN_API */
