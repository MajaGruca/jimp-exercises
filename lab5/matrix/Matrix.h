//
// Created by maj3 on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <string>
#include <complex>
#include <vector>
class Matrix{
public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const char* a);
    ~Matrix();
    Matrix add(Matrix a);
    Matrix sub(Matrix a);
    Matrix mul(Matrix a);
    Matrix div(Matrix a);
    Matrix pow(int a);
    std::string print();
    Matrix(const Matrix& a);
private:
    int col, row;
    std::complex<double> **mat;
};

#endif //JIMP_EXERCISES_MATRIX_H
