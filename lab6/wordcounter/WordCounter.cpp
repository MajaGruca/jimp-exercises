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
#include <numeric>t

namespace datastructures
{



   // product1 = std::make_pair(std::string("lightbulbs"),0.99);
    Counts::Counts(int count) {
        wordcount=count;
    }

    Counts::Counts() {
if(wordcount>=0)
    wordcount++;
else
    wordcount=0;
    }

    int Counts::operator+(Counts a) const {
        return this->wordcount+a.wordcount;
    }

    int Counts::operator+(int a) const {
        return this->wordcount+a;
    }

    Word::Word(std::string str) {
        word=str;
    }

    bool Word::operator<(Word a) const {
        return false;
    }



    WordCounter::WordCounter(std::string str) {
        std::ifstream file;
        file.open (str);
        if (!file.is_open()) return;

        std::string word1;
        while (file >> word1)
        {
            one_of_them.emplace(word1,1 );
        }
    }
    WordCounter::WordCounter(std::initializer_list<Word> s) {

    }
    std::set<Word> WordCounter::Words() {
        return std::set<Word>();
    }

    int WordCounter::TotalWords() {


        return std::accumulate(std::begin(one_of_them)
                , std::end(one_of_them)
                , 0
                , [] (int value, const std::map<Word, Counts>::value_type& p)
                               { return value + p.second; }
        );;
    }

    int WordCounter::DistinctWords() {
        return (int) one_of_them.size();
    }

    bool WordCounter::operator<(WordCounter a) const {
        return false;
    }


};