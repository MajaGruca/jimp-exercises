//
// Created by ktr on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Word.h"
#include "Counts.h"
#include <string>
#include <memory>
#include <map>
#include <set>
#include "vector"
#include <initializer_list>
namespace datastructures
{
    class WordCounter {
    public:

        WordCounter()= default;

        WordCounter(std::string str);

        WordCounter(std::initializer_list<Word> s);


        WordCounter FromInputStream(std::istream *input);

        int operator[](std::string a);


        int DistinctWords();

        int TotalWords();

        std::set<Word> Words();

        std::vector<std::pair<Word,Counts>> GetIT() const;

    private:

        std::vector<std::pair<Word,Counts>> all_words;
    };

    bool operator==(int a,Counts b);

    std::ostream& operator<<(std::ostream & output,WordCounter& p);
};


#endif //JIMP_EXERCISES_WORDCOUNTER_H
