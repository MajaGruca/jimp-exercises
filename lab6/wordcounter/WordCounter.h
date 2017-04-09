//
// Created by ktr on 08.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <memory>
#include <map>
#include <set>
#include "vector"
#include <initializer_list>
namespace datastructures
{
    class Counts {
    public:
        int GetCounts() const;
        Counts();
        Counts(int count);
        void operator++();
        void operator--();
        //bool operator<(Counts a) const ;
        //bool operator<=(Counts a) const ;
        //bool operator>(Counts a) const ;
        //bool operator>=(Counts a) const ;
        bool operator==(Counts a) const ;
        bool operator!=(Counts a) const ;
        bool operator==(int a) const ;
        int operator+(Counts a) const ;
        int operator+(int a) const ;
    private:
        int wordcount;

    };
    class Word {
    public:
        Word()= default;
        Word(std::string str);
        bool operator<(Word a) const;
        bool operator==(Word a) const;
        std::string GetWord() const;


    private:
        std::string word;

    };

    class WordCounter {
    public:
        WordCounter()= default;
        WordCounter(std::string str);
        WordCounter(std::initializer_list<Word> s);
        Counts operator[](std::string a);
        int DistinctWords(); // return all unoque words
        int TotalWords();  // return int all words
        std::set<Word> Words();   //return
        std::vector<std::pair<Word,Counts>> GetIT() const;
        //set<Word> expected_words {Word("a"),Word("hi"), Word("voltage"), Word("p")};
        //void operator++();
        //void operator--();
        bool operator<(WordCounter a) const ;
        //bool operator<=(WordCounter a) const ;
        //bool operator>(WordCounter a) const ;
        //bool operator>=(WordCounter a) const ;
        //bool operator==(WordCounter a) const ;
        //bool operator!=(WordCounter a) const ;

    private:
        std::vector<std::pair<Word,Counts>> one_of_them;
    };
    bool operator==(int a,Counts b);

    std::ostream& operator<<(std::ostream & output,WordCounter& p);
};


#endif //JIMP_EXERCISES_WORDCOUNTER_H
