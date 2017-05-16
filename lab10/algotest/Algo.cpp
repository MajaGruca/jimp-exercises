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
namespace algo
{


    CopyInto::CopyInto(std::vector<int> arg, int buffer, std::vector<int> *expected) {

    }

    Contains::Contains(std::vector<int> arg, bool element) {

    }

    bool Contains::operator==(const bool) {
        return false;
    }


    InitializeWith::InitializeWith(int value, std::vector<int> *arg) {

        std::iota(arg->begin(), arg->end(), value);
    }

    InitializedVectorOfLength::InitializedVectorOfLength(int a, int b) {
        std::vector<int> from_vector((unsigned long) a);
        std::iota(from_vector.begin(), from_vector.end(), b);
    }

    MapToString::MapToString(double a, double b) {

    }

    Keys::Keys(std::initializer_list<std::string> a, std::initializer_list<std::string> b) {

    }

    ContainsKey::ContainsKey(std::map<std::string, int> arg, std::string str) {

    }

    Values::Values(std::initializer_list<std::string> a, std::initializer_list<std::string> b) {

    }

    ContainsValue::ContainsValue(std::map<std::string, int> arg, int a) {

    }

    DivisableBy::DivisableBy(std::vector<int> arg, int a) {

    }
}