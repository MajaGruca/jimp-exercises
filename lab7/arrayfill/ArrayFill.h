//
// Created by ktr on 11.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <vector>
namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

}

#endif //JIMP_EXERCISES_ARRAYFILL_H
