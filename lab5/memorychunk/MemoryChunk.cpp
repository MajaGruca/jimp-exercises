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

    MemoryChunk::MemoryChunk(MemoryChunk &&xxx) : ptr{nullptr}, siz{0} {
        std::swap(ptr,xxx.ptr);
        std::swap(siz,xxx.siz);
    }

    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&xxx) {
        if (this == &xxx) {
            return xxx;
        }
        delete[] ptr;
        ptr = nullptr;
        siz=0;
        std::swap(ptr,xxx.ptr);
        std::swap(siz,xxx.siz);
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