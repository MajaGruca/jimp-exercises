//
// Created by ktr on 08.04.2017.
//
#include "WordCounter.h"
#include "Word.h"
#include "iostream"
int main()
{
    datastructures::WordCounter counter {datastructures::Word("enigma"), datastructures::Word("puzzle"), datastructures::Word("puzzle"), datastructures::Word("puzzle"), datastructures::Word("pazzle")};
    std::cout << counter;
    int ilosc = counter["puzzle"];
    std::cout <<ilosc<<std::endl;

    datastructures::WordCounter ss {"C:\\Users\\ktr\\Desktop\\test.txt"};
    std::cout<<ss;
    return 0;
}
