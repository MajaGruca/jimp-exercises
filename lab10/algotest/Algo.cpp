//
// Created by ktr on 16.05.2017.
//

#include "Algo.h"

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <numeric>
#include <set>
namespace algo
{


   void CopyInto(std::vector<int> arg, int elements, std::vector<int> *buffer) {
        std::copy(arg.begin(), arg.begin()+elements,
                  std::back_inserter(*buffer));
    }

    bool Contains(std::vector<int> arg, int element) {
        return  std::find(std::begin(arg), std::end(arg), element) != std::end(arg);
    }
    std::vector<int> InitializeWith(int value, std::vector<int> *arg) {

        std::fill(arg->begin(), arg->end(), value);
        return *arg;
    }
    std::vector<int> InitializedVectorOfLength(int a, int b) {
        std::vector<int> vec(a);
        std::fill(vec.begin(), vec.end(), b);
        return vec;
    }
    std::vector<std::string> MapToString(const std::vector<double> &v)
    {
        std::vector<std::string> vec;
        std::transform(v.begin(), v.end(), std::back_inserter(vec),
                       [](double a) { return std::to_string(a); });
        return vec;
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m)
    {
        std::set<std::string> a;
        std::transform(m.begin(),m.end(),std::inserter(a,a.begin()),[](std::pair<std::string,int> z){return z.first;});
        return a;
    }
    bool ContainsKey(std::map<std::string, int> arg, std::string str) {
        return  arg.find(str)!= std::end(arg);
    }
    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> a;
        std::transform(m.begin(),m.end(),std::back_inserter(a),[](std::pair<std::string,int> z){return z.second;});
        return a;

    }
    bool ContainsValue(std::map<std::string, int> arg, int a) {
       for(auto &n:arg)
       {
           if(n.second==a)
               return true;
       }
        return false;
    }

    std::vector<int> DivisableBy(std::vector<int> arg, int a) {
        return  std::vector<int>{0};
    }
}