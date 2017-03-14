//
// Created by ktr on 07.03.2017.
//

#include <iostream>
#include "Array2D.h"
using namespace std;

int main() {
    int  n_rows=5,n_columns=5;
    //NewArray2D(5,5);
    PrintArray2D(NewArray2D(n_rows, n_columns),n_rows,n_columns);
    DeleteArray2D(NewArray2D(n_rows, n_columns),n_rows,n_columns);

    return 0;
}
