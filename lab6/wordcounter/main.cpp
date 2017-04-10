//
// Created by ktr on 08.04.2017.
//
#include "WordCounter.h"
#include "Word.h"
#include "iostream"
int main()
{
    datastructures::WordCounter counter {datastructures::Word("enigma"), datastructures::Word("puzzle"), datastructures::Word("puzzle"), datastructures::Word("puzzle"), datastructures::Word("puzzle")};
    std::cout << counter;
    int ilosc = counter["puzzle"];
    std::cout <<ilosc;
    return 0;
}
