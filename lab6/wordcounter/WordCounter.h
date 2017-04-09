//
// Created by ktr on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <memory>
#include <map>
#include <set>
#include <initializer_list>
namespace datastructures
{
    class Counts {
    public:
        Counts();
        Counts(int count);
        int operator+(Counts a) const ;
        int operator+(int a) const ;
    private:
        int wordcount;

    };
    class Word {
    public:
        Word()= default;
        Word(std::string str);
        bool operator<(Word a) const ;


    private:
        std::string word;

    };

    class WordCounter {
    public:
        WordCounter()= default;
        WordCounter(std::string str);
        //WordCounter(std::string str);
        WordCounter(std::initializer_list<Word> s);

        int DistinctWords(); // return all unoque words
        int TotalWords();  // return int all words
        std::set<Word> Words();   //return
        //set<Word> expected_words {Word("a"),Word("hi"), Word("voltage"), Word("p")};
        void operator++();
        void operator--();
        bool operator<(WordCounter a) const ;
        bool operator<=(WordCounter a) const ;
        bool operator>(WordCounter a) const ;
        bool operator>=(WordCounter a) const ;
        bool operator==(WordCounter a) const ;
        bool operator!=(WordCounter a) const ;

    private:
        std::map<Word,Counts> one_of_them;
    };

};



#endif //JIMP_EXERCISES_WORDCOUNTER_H
