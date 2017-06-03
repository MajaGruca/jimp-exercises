//
// Created by ktr on 29.05.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <iostream>
namespace profiling
{
    template <class TestStruct>
    class TimeRecorder {

    public:
        TimeRecorder(TestStruct(*)()){};
        TimeRecorder(TestStruct one){};
        //std::pair<TestStruct, double> operator =(){return record};
        TimeRecorder& operator=(std::pair<TestStruct, double> arg) noexcept // copy/move constructor is called to construct arg
        {
            swap(arg,this->record); // resources are exchanged between *this and arg
            return *this;
        }
        void operator()(TestStruct a){ std::cout<<1;};
    private:
        std::pair<TestStruct, double> record;
    };
}



#endif //JIMP_EXERCISES_TIMERECORDER_H
