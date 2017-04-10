//
// Created by ktr on 10.04.2017.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H


#include "Word.h"
#include <string>
#include <memory>
#include <map>
#include <set>
#include "vector"
#include <initializer_list>
namespace datastructures {
    class Word {
    public:
        Word() = default;

        Word(std::string str);

        bool operator<(Word a) const;

        bool operator==(Word a) const;

        std::string GetWord() const;


    private:

        std::string word;
    };
}


#endif //JIMP_EXERCISES_WORD_H
