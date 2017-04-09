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
#include <numeric>
#include <ostream>
namespace datastructures
{

   // product1 = std::make_pair(std::string("lightbulbs"),0.99);
    Counts::Counts(int count) {
        wordcount=count;
    }

    Counts::Counts() {
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
        if(!word.compare(a.word))
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
        while (file >> word1) {
            bool ex = false;
            for (int i=0; i < one_of_them.size();i++) {
                if (one_of_them[i].first == Word(word1)) {
                    ex = true;
                    ++one_of_them[i].second;
                }
            }
            if (ex == false) {
                one_of_them.push_back(std::pair<Word, Counts>(Word(word1), Counts(1)));
            }
        }
    }
    WordCounter::WordCounter(std::initializer_list<Word> s) {
        for(auto n:s)
        {
            bool ex=false;
            for(int i=0;i<one_of_them.size();i++)
            {
                if(one_of_them[i].first==n)
                {
                    ex=true;
                    ++one_of_them[i].second;
                }
            }
            if(ex==false)
            {
                one_of_them.push_back(std::pair<Word,Counts>(n,Counts(1)));
            }
        }
    }

    Counts WordCounter::operator[](std::string a){
        for(int i=0;i<one_of_them.size();i++)
        {
            if(one_of_them[i].first==Word(a))
                return one_of_them[i].second;
        }

    }

    std::set<Word> WordCounter::Words() {
        std::vector<Word> cp;
        for(int i=0;i<one_of_them.size();i++)
            cp.push_back(one_of_them[i].first);
        std::set<Word> s(cp.begin(), cp.end());
        return s;
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

    bool WordCounter::operator<(WordCounter a) const {
        return false;
    }
    std::vector<std::pair<Word,Counts>> WordCounter::GetIT() const {
        return one_of_them;
    }

    std::ostream& operator<<(std::ostream & output,WordCounter& p){
        for(auto &n:p.GetIT())
            output<<'{'<<n.first.GetWord()<<','<<std::to_string(n.second.GetCounts())<<"}, ";

        return output;
    }
};