//
// Created by ktr on 13.03.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <algorithm>
#include <string>
#include <vector>
using std::find;
using std::vector;
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
