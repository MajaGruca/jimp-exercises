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

        std::iota(arg->begin(), arg->end(), value);
    }

    std::vector<int> InitializedVectorOfLength(int a, int b) {
        std::vector<int> from_vector((unsigned long) a);
        std::iota(from_vector.begin(), from_vector.end(), b);
    }

    std::vector<std::string> MapToString(const std::vector<double> &v)
    {

    }

    std::set<std::string> Keys(const std::map<std::string, int> &m)
    {


    }

    bool ContainsKey(std::map<std::string, int> arg, std::string str) {
        return  arg.find(str)!= std::end(arg);

    }

    std::vector<int> Values(const std::map<std::string, int> &m) {


    }

    bool ContainsValue(std::map<std::string, int> arg, int a) {

    }

    std::vector<int> DivisableBy(std::vector<int> arg, int a) {

    }
}