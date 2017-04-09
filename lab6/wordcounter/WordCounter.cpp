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

    int Counts::GetCounts() const{
        return wordcount;
    }

    void Counts::operator++() {
        ++(this->wordcount);
    }

    void Counts::operator--() {
        --(this->wordcount);
    }

    /*bool Counts::operator<(Counts a) const
    {
        return this->wordcount < a.wordcount;
    }
    bool Counts::operator<=(Counts a) const
    {
        return this->wordcount <= a.wordcount;
    }
    bool Counts::operator>(Counts a) const
    {
        return this->wordcount > a.wordcount;
    }
    bool Counts::operator>=(Counts a) const
    {
        return this->wordcount >= a.wordcount;
    }*/
    bool Counts::operator==(Counts a) const
    {
        return this->wordcount == a.wordcount;
    }
    bool Counts::operator!=(Counts a) const
    {
        return this->wordcount != a.wordcount;
    }

    bool Counts::operator==(int a) const
    {
        return this->wordcount == a;
    }

    bool Word::operator==(Word a) const{
        if(word==a.word)
            return true;
        else
            return false;
    }
    bool Word::operator<(Word a) const{
        if(word.size()<a.word.size())
            return true;
        else
            return false;
    }

    Word::Word(std::string str) {
        word=str;
    }

    std::string Word::GetWord() const{
        return word;
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
        for(auto n:s)
        {
            bool ex=false;
            for(auto m:one_of_them)
            {
                if(m.first==n)
                {
                    ex=true;
                    ++m.second;
                    break;
                }
            }
            if(ex==false)
            {
                one_of_them.emplace(n,Counts(1));
            }
        }
    }

    Counts WordCounter::operator[](std::string a){
        return this->one_of_them[a];
    }
    std::set<Word> WordCounter::Words() {
        return std::set<Word>();
    }

    int WordCounter::TotalWords() {
        int sum=0;
        for(auto &n:one_of_them)
            sum=sum+n.second.GetCounts();
        return sum;
    }

    int WordCounter::DistinctWords() {
        return (int) one_of_them.size();
    }
    bool operator==(int a,Counts b)
    {
        return a==b.GetCounts();
    }
}

    bool WordCounter::operator<(WordCounter a) const {
        return false;
    }
};