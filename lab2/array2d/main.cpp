//
// Created by ktr on 07.03.2017.
//

#include <iostream>
#include "Array2d.h"
using namespace std;

int main() {
    int  n_rows=5,n_columns=5;
    //Array2D(5,5);
    PrintArray2D(Array2D(n_rows,n_columns),n_rows,n_columns);
    DeleteArray2D(Array2D(n_rows,n_columns),n_rows,n_columns);

    return 0;
}
