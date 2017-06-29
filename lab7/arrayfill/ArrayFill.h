//
// Created by ktr on 11.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <vector>

#include <memory>
#include <random>
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

    //int UniformFillWithZero(int index);

    //int UniformFillWith77(int index);

    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill( int b=0,int a=1) : a_{a}, b_{b}{}
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };
    class SquaredFill : public ArrayFill{
    public:
        SquaredFill( int a=1,int b=0) : a_{a}, b_{b}{}
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };
    class RandomFill : public ArrayFill{
    public:
        RandomFill( std::unique_ptr<std::default_random_engine> a,std::unique_ptr<std::uniform_int_distribution<int>> b) : a_{move(a)}, b_{move(b)}{}
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::default_random_engine> a_;
        std::unique_ptr<std::uniform_int_distribution<int>> b_;
    };

}

#endif //JIMP_EXERCISES_ARRAYFILL_H
