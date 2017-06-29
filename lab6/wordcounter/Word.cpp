//
// Created by ktr on 10.04.2017.
//

#include "Word.h"
namespace datastructures
{
    Word::Word(std::string str) {
        word=str;
    }
    std::string Word::GetWord() const{
        return word;
    }
    bool Word::operator==(Word a) const{
        return !word.compare(a.word);
    }
    bool Word::operator<(Word a) const{
        return word.size() < a.word.size();
    }
}