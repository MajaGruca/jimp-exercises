//
// Created by ktr on 07.03.2017.
//

#include "Array2d.h"
#include <iostream>
using namespace std;

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for ( int i(0); i < n_rows; ++i )
        delete [] array[i];
    delete [] array;
    array = NULL;
}
void  PrintArray2D(int **array,int n_rows, int n_columns)
{
    for ( int i = 0; i < n_rows; ++i, cout<<endl )
        for ( int j = 0; j < n_columns; ++j)
            cout<<array[i][j]<<'\t';
}
int **Array2D(int n_rows, int n_columns)
{

    if (n_rows>0 && n_columns>0)
    {
        int **array = new int *[n_rows];
        for ( int i = 0; i < n_rows; ++i )
        {
            array[i] = new int [n_columns];
            for ( int j = 0; j < n_columns; ++j)
                array[i][j]=i*n_columns+j+1 ;
        }
        return array;
    }
    else
    {
        return NULL;
    }


}
