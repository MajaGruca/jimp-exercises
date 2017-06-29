//
// Created by ktr on 23.05.2017.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <vector>
#include <ostream>

namespace factoryMethod
{
    class MyType {
    public:
        std::string SayHello();

    };

    template <class T>
    T Create()
    {
        return T();
    }

    template <class A>
    A SumUp(A one, A two)
    {
        return one+two;
    }

    template <class B>
    auto Value(B one)
    {
        return *one;
    }

    template <class C>
    class Repository
    {
    public:
       int Size(){ return static_cast<int> (cos.size());};
        C operator [] (int it) const { return cos[it];};
        int NextID() { return id++;};

    private:
        std::vector<C> cos;
        int id;
    };


    template <class D>
    D Mean(std::vector<D> one)
    {
        D sum=0;
        for(auto a : one)
        {
            sum=sum+a;
        }
        return sum/one.size();
    }

    template <class F>
    class Logger{
    public:
        Logger(std::ostream s) : stream(s){}
        ~Logger(){}

        std::ostream& Debug(F it){ return stream<<it;};
        std::ostream& Info(F it){ return stream<<it;};
        std::ostream& Warning(F it){ return stream<<it;};
        std::ostream& Error(F it){ return stream<<it;};

    private:
        std::ostream& stream;
    };




}




#endif //JIMP_EXERCISES_FACTORYMETHOD_H
