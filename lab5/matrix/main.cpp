//
// Created by maj3 on 03.04.17.
//

#include <iostream>
#include "Matrix.h"
using namespace std;
int main(int argc, char* argv[]){
    Matrix m1("[1i3 2i5 3; 3 4 5; 6 7 8]");
    Matrix m2("[1i3 2i5 0; 3 4 5; 6 7 8]");

    cout << "Macierz pierwsza: " << m1.print() << endl;
    cout << "Macierz druga: " << m2.print() << endl;

    cout << "Dodawanie" << (m1.add(m2)).print() << endl;
    //cout << "Odejmowanie" << (m1.sub(m2)).print() << endl;
    //cout << "Mnożenie" << (m1.mul(m2)).print() << endl;
    //cout << "Dzielenie" << (m1.div(m2)).print() << endl;
    //cout << "Potęgowanie" << (m1.pow(2)).print() << endl;
    //cout << "Potęgowanie" << (m2.pow(2)).print() << endl;
    return 0;
}