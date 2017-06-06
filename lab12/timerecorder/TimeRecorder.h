//
// Created by ktr on 29.05.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <utility>
#include <chrono>

using ::std::pair;

namespace profiling {
    template<class T>
    auto TimeRecorder(T cos) {
        static std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
        auto result = (cos)();
        std::chrono::duration<double, std::milli> diff = std::chrono::system_clock::now()-begin;
        return std::pair<decltype(result), double>(result, diff.count());
    };

}

#endif //JIMP_EXERCISES_TIMERECORDER_H
