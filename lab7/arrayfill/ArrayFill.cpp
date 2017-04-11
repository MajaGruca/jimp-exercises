//
// Created by ktr on 11.04.2017.
//

#include <vector>
#include "ArrayFill.h"

namespace arrays{

    void FillArray(std::size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (std::size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const{
        return a_*index + b_;
    }


}