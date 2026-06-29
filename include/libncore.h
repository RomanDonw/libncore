/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#ifndef LIBNCORE_H
#define LIBNCORE_H

#ifdef __cplusplus
    extern "C"
    {
#endif

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64)
    #define LIBNCORE_OS_WINDOWS
#endif

#ifdef LIBNCORE_OS_WINDOWS
    #ifdef LIBNCORE_STATIC
        #ifdef _MSC_VER
            #define LIBNCORE_API
        #else
            #define LIBNCORE_API __attribute__((visibility("default")))
        #endif
    #else
        #ifdef _MSC_VER
            #ifdef LIBNCORE_EXPORT
                #define LIBNCORE_API __declspec(dllexport)
            #else
                #define LIBNCORE_API __declspec(dllimport)
            #endif
        #else
            #define LIBNCORE_API __attribute__((visibility("default")))
        #endif
    #endif
#else
    #define LIBNCORE_API __attribute__((visibility("default")))
#endif

#define LIBNCORE_ABI



#ifdef __cplusplus
    }
#endif

#endif