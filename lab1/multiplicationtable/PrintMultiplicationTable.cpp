//
// Created by Paulina Kapłon on 06.03.2017.
//

#include "PrintMultiplicationTable.h"

#include <iostream>
//#include <stdlib.h>
using namespace std;

void PrintMultiplicationTable(int tab[][10])
{
    for(int i =0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            cout.width( 4 );
            cout<<tab[i][j];
        }

        cout<<endl;
    }
}