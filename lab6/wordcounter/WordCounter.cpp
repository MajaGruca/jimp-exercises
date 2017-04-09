//
// Created by ktr on 08.04.2017.
//

#include "WordCounter.h"
#include <string>
#include <memory>
#include <utility>
#include <map>
#include <set>
#include <initializer_list>
#include <fstream>
#include <iostream>

namespace datastructures
{



   // product1 = std::make_pair(std::string("lightbulbs"),0.99);
    Counts::Counts(int count) {
        wordcount=count;
    }

    Word::Word(std::string str) {
        word=str;
    }

    WordCounter::WordCounter(std::string str) {
        std::ifstream file;
        file.open (str);
        if (!file.is_open()) return;

        std::string word1;
Word ww {"ana"};
        while (file >> word1)
        {

        }
    }
    WordCounter::WordCounter(std::initializer_list<Word> s) {

    }
    std::set<Word> WordCounter::Words() {
        return std::set<Word>();
    }

    int WordCounter::TotalWords() {
        return 0;
    }

    int WordCounter::DistinctWords() {
        return 0;
    }




};