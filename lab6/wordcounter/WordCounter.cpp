//
// Created by ktr on 08.04.2017.
//


#include <fstream>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <utility>
#include "WordCounter.h"

namespace datastructures
{
    WordCounter::WordCounter(std::string str) {
        std::ifstream file(str);
        if(!file)
            return;


        std::string word1;
        while (file >> word1) {
            bool ex = false;
            for (int i=0; i < all_words.size();i++) {
                if (all_words[i].first == Word(word1)) {
                    ex = true;
                    ++all_words[i].second;
                }
            }
            if (!ex) {
                all_words.push_back(std::pair<Word, Counts>(Word(word1), Counts(1)));
            }
        }
        file.close();
    }
    WordCounter::WordCounter(std::initializer_list<Word> s) {
        for(auto n:s)
        {
            bool ex=false;
            for(int i=0;i<all_words.size();i++)
            {
                if(all_words[i].first==n)
                {
                    ex=true;
                    ++all_words[i].second;
                }
            }
            if(!ex)
            {
                all_words.push_back(std::pair<Word,Counts>(n,Counts(1)));
            }
        }
    }


    std::set<Word> WordCounter::Words() {
        std::vector<Word> cp;
        for(int i=0;i<all_words.size();i++)
            cp.push_back(all_words[i].first);
        std::set<Word> s(cp.begin(), cp.end());
        return s;
    }

    int WordCounter::TotalWords() {
        int sum=0;
        for(auto &n:all_words)
            sum=sum+n.second.GetCounts();
        return sum;
    }

    int WordCounter::DistinctWords() {
        return (int) all_words.size();
    }
    std::vector<std::pair<Word,Counts>> WordCounter::GetIT() const {
        return all_words;
    }
    bool check(std::pair<Word,Counts> pair1, std::pair<Word,Counts> pair2){
        return pair1.second.GetCounts() >= pair2.second.GetCounts();
    }
    std::ostream& operator<<(std::ostream & output,WordCounter& p){
        std::vector<std::pair<Word,Counts>> cos = p.GetIT();
        std::sort(cos.begin(),cos.end(),check);
        for(auto &n:cos)
        {
            output<<'{'<<n.first.GetWord()<<','<<std::to_string(n.second.GetCounts())<<"}\n";
        }
        return output;
    }
    int WordCounter::operator[](std::string a){
        for(int i=0;i<all_words.size();i++)
        {
            if(all_words[i].first==Word(a))
                return all_words[i].second.GetCounts();
        }
        return 0;
    }

    WordCounter WordCounter::FromInputStream(std::istream *input) {
        std::string str="";
        char temp;

        while (*input)
        {
            temp= char((*input).get());
            if(isalpha(temp))
                str=str+temp;

             else
            {
                if(str.length())
                {
                    bool ex=false;
                    for(int i=0;i<all_words.size();i++)
                    {
                        if(all_words[i].first==str)
                        {
                            ex=true;
                            ++all_words[i].second;
                        }
                    }
                    if(!ex)
                    {
                        all_words.push_back(std::pair<Word,Counts>(str,Counts(1)));
                    }

                }
                str="";
            }
        }
        return WordCounter();
    }
};