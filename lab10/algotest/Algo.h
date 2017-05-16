//
// Created by ktr on 16.05.2017.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <vector>
#include <string>
#include <map>

namespace algo
{
    class CopyInto
    {
    public:
        CopyInto( std::vector<int> arg, int buffer, std::vector<int>* expected);
    };
    class Contains
    {
    public:
        Contains(std::vector<int> arg,bool element);
        bool operator==(const bool);
    };
    class InitializeWith
    {
    public:
        InitializeWith(int value, std::vector<int>* arg);
    };
    class InitializedVectorOfLength
    {
    public:
        InitializedVectorOfLength(int a, int b);
    };
    class MapToString
    {
    public:
        MapToString(double a, double b);
    };
    class Keys
    {
    public:
        Keys(std::initializer_list<std::string> a ,std::initializer_list<std::string> b);

    };
    class ContainsKey
    {
    public:
        ContainsKey(std::map<std::string, int> arg, std::string str);
    };
    class Values
    {
    public:
        Values(std::initializer_list<std::string> a ,std::initializer_list<std::string> b);
    };
    class ContainsValue
    {
    public:
        ContainsValue(std::map<std::string, int> arg,int a);
    };
    class DivisableBy
    {
    public:
        DivisableBy( std::vector<int> arg,int a);
    };
}


#endif //JIMP_EXERCISES_ALGO_H
