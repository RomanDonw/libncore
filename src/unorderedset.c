/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include "libncore.h"

#include <stdlib.h>
#include <string.h>

struct NUnorderedSet
{
    NMemoryAllocators allocs;
    void *data;
    size_t len;
    size_t elsize;
};

NError n_unorderedset_create(NUnorderedSet **set, const NMemoryAllocators *allocators, size_t elementsize)
{
    static const NMemoryAllocators defaultallocs =
    {
        .malloc = malloc,
        .realloc = realloc,
        .free = free
    };
    register const NMemoryAllocators *allocs = allocators ? allocators : &defaultallocs;

    NUnorderedSet *ret = allocs->malloc(sizeof(NUnorderedSet));
    if (!ret) return NError_MemoryAllocationFailed;

    ret->allocs = *allocs;
    ret->data = NULL;
    ret->len = 0;
    ret->elsize = elementsize;

    *set = ret;
    return NError_Success;
}

bool n_unorderedset_copy(NUnorderedSet **newset, const NUnorderedSet *sourceset, const NMemoryAllocators *allocators)
{
    register const NMemoryAllocators *allocs = allocators ? allocators : &sourceset->allocs;

    NUnorderedSet *ret = allocs->malloc(sizeof(NUnorderedSet));
    if (!ret) return NError_MemoryAllocationFailed;

    ret->data = allocs->malloc(sourceset->elsize * sourceset->len);
    if (!ret->data) { allocs->free(ret); return NError_MemoryAllocationFailed; }

    ret->allocs = *allocs;
    ret->len = sourceset->len;
    ret->elsize = sourceset->elsize;

    *newset = ret;
    return NError_Success;
}

void n_unorderedset_destroy(NUnorderedSet *set)
{ set->allocs.free(set->data); set->allocs.free(set); }

bool n_unorderedset_haselement(const NUnorderedSet *set, const void *element)
{
    for (size_t i = 0; i < set->len; i++) if (!memcmp((unsigned char *)set->data + set->elsize * i, element, set->elsize)) return true;
    return false;
}

NError n_unorderedset_getelement(const NUnorderedSet *set, size_t index, void *element)
{
    if (index >= set->len) return NError_InvalidIndex;
    memcpy(element, (unsigned char *)set->data + set->elsize * index, set->elsize);
    return NError_Success;
}

NError n_unorderedset_addelement(NUnorderedSet *set, const void *element)
{
    for (size_t i = 0; i < set->len; i++) if (!memcmp((unsigned char *)set->data + set->elsize * i, element, set->elsize)) return NError_ElementAlreadyExist;

    {
        void *new_data = set->allocs.realloc(set->data, (set->len + 1) * set->elsize);
        if (!new_data) return NError_MemoryAllocationFailed;
        set->data = new_data;
    }

    memcpy((unsigned char *)set->data + (set->len++) * set->elsize, element, set->elsize);
    
    return NError_Success;
}

NError n_unorderedset_removeelement(NUnorderedSet *set, const void *element)
{
    size_t index = 0;
    bool found = false;
    for (; index < set->len; index++) if (!memcmp((unsigned char *)set->data + set->elsize * index, element, set->elsize)) { found = true; break; }
    if (!found) return NError_ElementNotExist;
    
    if (index != (--set->len)) memcpy((unsigned char *)set->data + set->elsize * index, (unsigned char *)set->data + set->elsize * set->len, set->elsize);

    if (set->len)
    {
        void *new_data = set->allocs.realloc(set->data, set->len * set->elsize);
        if (new_data) set->data = new_data;
    }
    else { set->allocs.free(set->data); set->data = NULL; }

    return NError_Success;
}

void n_unorderedset_clear(NUnorderedSet *set)
{
    set->allocs.free(set->data);
    set->data = NULL;
    set->len = 0;
}

NMemoryAllocators n_unorderedset_getallocators(const NUnorderedSet *set) { return set->allocs; }
size_t n_unorderedset_getelementsize(const NUnorderedSet *set) { return set->elsize; }
size_t n_unorderedset_getlength(const NUnorderedSet *set) { return set->len; }