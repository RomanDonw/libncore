/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include "libncore.h"

const char *n_strerror(NError errorcode)
{
    switch (errorcode)
    {
        case NError_Success:
            return "success (no error)";

        case NError_NotInitialized:
            return "not initialized";

        case NError_AlreadyInitialized:
            return "already initialized";

        case NError_InternalUnknownError:
            return "internal unknown error (this is a bug, report about it after debugging)";

        case NError_InternalSizeMismatch:
            return "internal size mismatch (this is a bug, report about it after debugging)";
            
        case NError_InternalVariableOverflow:
            return "internal variable overflow (this is a bug, report about it after debugging)";

        case NError_MemoryAllocationFailed:
            return "memory allocation failed";

        case NError_ParsingAddressFailed:
            return "parsing address failed";

        case NError_Interrupted:
            return "operation interrupted";

        case NError_AccessDenied:
            return "access denied";

        case NError_Fault:
            return "fault";

        case NError_InsufficientBufferSize:
            return "insufficient buffer size";
        
        case NError_IncorrectArgumentValue:
            return "incorrect argument value";

        case NError_TooManyOpenedDescriptors:
            return "too many opened descriptors";

        case NError_WouldBlock:
            return "would block";

        case NError_OperationInProgress:
            return "operation in progress";

        case NError_InExecutionProcess:
            return "processing task";

        case NError_UnsupportedAddressFamily:
            return "unsupported address family";

        case NError_UnsupportedProtocol:
            return "unsupported network protocol";

        case NError_UnsupportedSocketType:
            return "unsupported socket type";

        case NError_UnsupportedProtocolOption:
            return "unsupported protocol option";

        case NError_UnsupportedOperation:
            return "unsupported operation";

        case NError_AddressInUse:
            return "address already in use";

        case NError_AddressNotAvailable:
            return "address not available";

        case NError_NetworkUnreachable:
            return "network unreachable";

        case NError_NetworkDown:
            return "network down";

        case NError_NetworkReset:
            return "network reset";

        case NError_ConnectionReset:
            return "connection reset";

        case NError_ConnectionRefused:
            return "connection refused";

        case NError_ConnectionTimedOut:
            return "connection timed out";

        case NError_NotConnected:
            return "not connected";

        case NError_InvalidDescriptor:
            return "invalid descriptor";

        case NError_NoSpaceLeft:
            return "no space left";

        case NError_SystemBufferOverflowed:
            return "system buffer overflowed";

        case NError_ConnectionAborted:
            return "connection aborted";

        case NError_CannotTranslateName:
            return "cannot translate name";

        case NError_DestinationAddressRequired:
            return "destination address required";

        case NError_AlreadyConnected:
            return "already connected";

        case NError_NameTooLong:
            return "name too long";

        case NError_TooManyProcesses:
            return "too many processes";

        case NError_NetworkSystemNotReady:
            return "network system not ready";

        case NError_WSAVersionNotSupported:
            return "WinSock version not supported";

        case NError_BadFlags:
            return "bad flags";

        case NError_DNSFailure:
            return "DNS failure";

        case NError_DNSHostNotFound:
            return "(DNS) host not found";

        case NError_DNSTemporaryError:
            return "DNS temporary error";

        case NError_DNSUnsupportedServiceName:
            return "(DNS) unsupported service name";

        case NError_MutexBusy:
            return "mutex busy";

        case NError_MutexDeadlock:
            return "mutex deadlock";

        case NError_OperationNotPermitted:
            return "operation not permitted";

        case NError_DependencyNotInitialized:
            return "dependency not initialized";

        case NError_ElementAlreadyExist:
            return "element already exist";

        case NError_ElementNotExist:
            return "element not exist";

        case NError_InvalidIndex:
            return "invalid index";

        default:
            return NULL;
    }
}