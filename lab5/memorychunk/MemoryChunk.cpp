//
// Created by ktr on 28.03.2017.
//

#include "MemoryChunk.h"
#include <stdio.h>
#include <string.h>
namespace memorychunk
{
    MemoryChunk::MemoryChunk(size_t sz) {

        ptr = new int8_t[sz];
        siz=sz;
    }
    MemoryChunk::~MemoryChunk(){
        delete [] ptr;
        siz=0;
    }

    MemoryChunk::MemoryChunk(const MemoryChunk& memorychunk) {
        ptr = new int8_t[memorychunk.siz];
        siz = memorychunk.siz;
        memcpy(ptr,memorychunk.ptr,siz);
    }
    MemoryChunk & MemoryChunk::operator=(const MemoryChunk& memorychunk) {
        if (this == &memorychunk) {
            return *this;
        }

        delete[] ptr;

        ptr = new int8_t[memorychunk.siz];
        ptr = memorychunk.ptr;
        siz=memorychunk.siz;
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&memorychunk) : ptr{nullptr}, siz{0} {
        std::swap(ptr,memorychunk.ptr);
        std::swap(siz,memorychunk.siz);
    }

    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&memorychunk) {
        if (this == &memorychunk) {
            return memorychunk;
        }
        delete[] ptr;
        ptr = nullptr;
        siz=0;
        std::swap(ptr,memorychunk.ptr);
        std::swap(siz,memorychunk.siz);
    }


    int8_t *MemoryChunk::MemoryAt(size_t offset) const
    {
        if(offset>=0 && offset<siz)
            return ptr+offset;
        else
            return nullptr;
    }
    size_t MemoryChunk::ChunkSize() const
    {
        if(ptr)
        {
            return siz;
        }
        else
            return 0;
    }
}