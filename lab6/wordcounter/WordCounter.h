//
// Created by ktr on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <memory>
#include <map>
namespace datastructures
{
    class Counts {

    private:
        int wordcount;

    };
    class Word {
    private:
        std::string word;

    };

    class WordCounter {
    public:
        //DistinctWords(); // return all unoque words
        //TotalWords();  // return int all words
        //Words();   //return set<Word> expected_words {Word("a"),Word("hi"), Word("voltage"), Word("p")};

    private:
        std::map<Word, Counts> aa;
    };

};



#endif //JIMP_EXERCISES_WORDCOUNTER_H
