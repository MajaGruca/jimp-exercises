//
// Created by ktr on 08.04.2017.
//
#include "WordCounter.h"
#include "Word.h"
#include <iostream>
#include <fstream>
int main()
{
    datastructures::WordCounter counter {datastructures::Word("enigma"), datastructures::Word("puzzle"), datastructures::Word("puzzle"), datastructures::Word("puzzle"), datastructures::Word("pazzle")};
    std::cout << counter;
    int ilosc = counter["puzzle"];
    std::cout <<ilosc<<std::endl;


    std::filebuf fb;
    if (fb.open ("C:\\Users\\ktr\\Desktop\\test.txt",std::ios::in))
    {
        std::istream is(&fb);
        counter.FromInputStream(&is);
        fb.close();
    }

    std::cout<<counter;


    return 0;
}
