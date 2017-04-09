//
// Created by ktr on 08.04.2017.
//
#include "WordCounter.h"
#include "iostream"
int main()
{
    datastructures::WordCounter counter {datastructures::Word("enigma"), datastructures::Word("enigma"), datastructures::Word("puzzle")};
    std::cout << counter.DistinctWords();
    return 0;
}
