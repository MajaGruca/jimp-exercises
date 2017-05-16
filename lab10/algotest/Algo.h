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

        void CopyInto( std::vector<int> arg, int buffer, std::vector<int>* expected);

        bool Contains(std::vector<int> arg,bool element);

        std::vector<int> InitializeWith(int value, std::vector<int>* arg);

        std::vector<int> InitializedVectorOfLength(int a, int b);

        std::vector<std::string> MapToString(const std::vector<double> &v);

        std::vector<std::string> Keys(std::initializer_list<std::string> a ,std::initializer_list<std::string> b);

        bool ContainsKey(std::map<std::string, int> arg, std::string str);

        std::vector<int> Values(std::initializer_list<std::string> a ,std::initializer_list<std::string> b);

        bool ContainsValue(std::map<std::string, int> arg,int a);

        std::vector<int> DivisableBy( std::vector<int> arg,int a);
        void SortInPlace(std::vector<int> *v);
    std::vector<int> Sort(const std::vector<int> &v);
    void SortByFirstInPlace(std::vector<std::pair<int,int>> *v);
    void SortBySecondInPlace(std::vector<std::pair<int,int>> *v);
    void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v);
    std::string Join(const std::string &joiner, const std::vector<double> &v);
    int Sum(const std::vector<int> &v);
    int Product(const std::vector<int> &v);
    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v);
    void RemoveDuplicatesInPlace(std::vector<std::string> *v);
    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length);

}


#endif //JIMP_EXERCISES_ALGO_H
