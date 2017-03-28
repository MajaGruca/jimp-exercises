//
// Created by ktr on 28.03.2017.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>
namespace memorychunk
{
    class MemoryChunk{
    public:
        MemoryChunk(size_t sz);
        ~MemoryChunk();
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
        MemoryChunk(const MemoryChunk& memorychunk);
        MemoryChunk & operator=(const MemoryChunk& memorychunk);
        MemoryChunk & operator=(MemoryChunk &&xxx);
        MemoryChunk(MemoryChunk &&xxx);
    private:
        int8_t *ptr;
        size_t siz;
    };
}



#endif //JIMP_EXERCISES_MEMORYCHUNK_H
