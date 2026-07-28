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
    #ifdef _MSC_VER
        #ifdef LIBNCORE_STATIC
            #define LIBNCORE_API
        #else
            #ifdef LIBNCORE_EXPORT
                #define LIBNCORE_API __declspec(dllexport)
            #else
                #define LIBNCORE_API __declspec(dllimport)
            #endif
        #endif
    #else
        #define LIBNCORE_API __attribute__((visibility("default")))
    #endif
#else
    #define LIBNCORE_API __attribute__((visibility("default")))
#endif

#include <stddef.h>
#include <stdbool.h>

#define LIBNCORE_ABI

enum NError
{
    NError_Success = 0,

    NError_NotInitialized,
    NError_AlreadyInitialized,
    NError_InternalUnknownError,
    NError_InternalSizeMismatch,
    NError_InternalVariableOverflow,
    NError_ParsingAddressFailed,
    NError_DependencyNotInitialized,
    NError_ElementAlreadyExist,
    NError_ElementNotExist,
    NError_InvalidIndex,

    NError_MemoryAllocationFailed, // ENOMEM/EAI_MEMORY
    NError_Interrupted, // EINTR
    NError_AccessDenied, // EACCES
    NError_OperationNotPermitted, // EPERM
    NError_Fault, // EFAULT
    NError_InsufficientBufferSize, // ERANGE
    NError_IncorrectArgumentValue, // EINVAL
    NError_TooManyOpenedDescriptors, // EMFILE
    NError_WouldBlock, // EAGAIN/EWOULDBLOCK
    NError_OperationInProgress, // EINPROGRESS
    NError_InExecutionProcess, // EALREADY
    NError_UnsupportedAddressFamily, // EAFNOSUPPORT
    NError_UnsupportedProtocol, // EPROTONOSUPPORT
    NError_UnsupportedSocketType, // ESOCKTNOSUPPORT
    NError_UnsupportedProtocolOption, // ENOPROTOOPT
    NError_UnsupportedOperation, // EOPNOTSUPP
    NError_AddressInUse, // EADDRINUSE
    NError_AddressNotAvailable, // EADDRNOTAVAIL
    NError_NetworkUnreachable, // ENETUNREACH
    NError_NetworkDown, // ENETDOWN
    NError_NetworkReset, // ENETRESET
    NError_ConnectionReset, // ECONNRESET
    NError_ConnectionRefused, // ECONNREFUSED
    NError_ConnectionAborted, // ECONNABORTED
    NError_ConnectionTimedOut, // ETIMEDOUT
    NError_NotConnected, // ENOTCONN
    NError_AlreadyConnected, // EISCONN
    NError_InvalidDescriptor, // EBADF
    NError_NoSpaceLeft, // ENOSPC
    NError_SystemBufferOverflowed, // ENOBUFS
    NError_CannotTranslateName, // ELOOP
    NError_DestinationAddressRequired, // EDESTADDRREQ
    NError_NameTooLong, // ENAMETOOLONG
    NError_BadFlags, // (EAI_BADFLAGS)
    NError_TooManyProcesses, // EPROCLIM
    NError_DNSTemporaryError, // EAI_AGAIN
    NError_DNSHostNotFound, // EAI_NONAME
    NError_DNSUnsupportedServiceName, // EAI_SERVICE
    NError_DNSFailure, // EAI_FAIL
    NError_MutexBusy, // EBUSY
    NError_MutexDeadlock, // EDEADLOCK

    // Windows-specific:
    NError_NetworkSystemNotReady, // WSASYSNOTREADY
    NError_WSAVersionNotSupported, // WSAVERNOTSUPPORTED
} typedef NError;

// memory allocators must work same as in <stdlib.h>. 
struct NMemoryAllocators
{
    void *(*malloc)(size_t);
    void *(*realloc)(void *, size_t); // must be safe for NULL.
    void (*free)(void *); // must be safe for NULL.
} typedef NMemoryAllocators;

// 'error' parameter is optional (equals NError_Success if 'true' value not present).
typedef void NPanicHandler(const char *module, const char *file, long long line, const char *function, const char *description, NError error);
typedef void NAlertHandler(const char *module, const char *file, long long line, const char *function, const char *format, ...);

LIBNCORE_API const char * LIBNCORE_ABI n_strerror(NError errorcode);

typedef struct NUnorderedSet NUnorderedSet;

// [n_unorderedset_create]: set allocators to NULL to use default allocators (from <stdlib.h>).
LIBNCORE_API NError LIBNCORE_ABI n_unorderedset_create(NUnorderedSet **set, const NMemoryAllocators *allocators, size_t elementsize);
// [n_unorderedset_copy]: 'allocators' can be NULL to copy allocators from 'sourceset' and used only copy of value pointed by allocators.
LIBNCORE_API bool LIBNCORE_ABI n_unorderedset_copy(NUnorderedSet **newset, const NUnorderedSet *sourceset, const NMemoryAllocators *allocators);
LIBNCORE_API void LIBNCORE_ABI n_unorderedset_destroy(NUnorderedSet *set);

LIBNCORE_API bool LIBNCORE_ABI n_unorderedset_haselement(const NUnorderedSet *set, const void *element);
LIBNCORE_API NError LIBNCORE_ABI n_unorderedset_getelement(const NUnorderedSet *set, size_t index, void *element);
LIBNCORE_API NError LIBNCORE_ABI n_unorderedset_addelement(NUnorderedSet *set, const void *element);
LIBNCORE_API NError LIBNCORE_ABI n_unorderedset_removeelement(NUnorderedSet *set, const void *element);
LIBNCORE_API void LIBNCORE_ABI n_unorderedset_clear(NUnorderedSet *set);

LIBNCORE_API NMemoryAllocators LIBNCORE_ABI n_unorderedset_getallocators(const NUnorderedSet *set);
LIBNCORE_API size_t LIBNCORE_ABI n_unorderedset_getlength(const NUnorderedSet *set);
LIBNCORE_API size_t LIBNCORE_ABI n_unorderedset_getelementsize(const NUnorderedSet *set);

extern const char *n_panicmsg_mutexlock, *n_panicmsg_mutexunlock, *n_panicmsg_mutexdestroyduringlibrarycleanup;

#ifdef __cplusplus
    }
#endif

#endif