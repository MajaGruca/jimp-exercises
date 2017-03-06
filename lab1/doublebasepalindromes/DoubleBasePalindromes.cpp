//
// Created by Paulina Kapłon on 06.03.2017.
//

#include "DoubleBasePalindromes.h"
#include <iostream>

using namespace std;

string DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}


uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t suma=0;

    int i,j;
    string str;
    int size;
    int flaga=0;

    for(int it=0;it<=max_vaule_exculsive;it++)
    {
        flaga=0;
        str = to_string(it);
        size= (int) str.size();
        for(i=0, j=size-1;i<=size/2;i++)
        {
            if(str[i]!=str[j]) {
                flaga=1;
                break;
            }
            j--;
        }
        if(flaga)
        {
            continue;
        }
        if (i-1 == size / 2)
        {
            str = DecToBin(it);
            size= (int) str.size();
            for(i=0, j=size-1; i <= size / 2; i++)
            {
                if(str[i]!=str[j]) {

                    flaga=1;
                    break;
                }
                j--;
            }
            if(flaga)
            {
                continue;
            }
            if (i-1 == size / 2)
            {
                suma=suma+it;
            }
        }
    }
    return suma;
}