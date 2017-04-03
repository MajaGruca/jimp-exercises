//
// Created by maj3 on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <string>
#include <complex>
#include <vector>
namespace algebra {
    class Matrix {
    public:
        Matrix();

        Matrix(int r, int c);

        Matrix(const char *a);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> a);

        ~Matrix();

        Matrix Add(Matrix a) const;

        Matrix Sub(Matrix a) const;

        Matrix Mul(Matrix a) const;

        Matrix Div(Matrix a);

        Matrix Pow(int a);

        std::string Print() const;

        Matrix(const Matrix &a);

        Matrix & operator=(const Matrix& a);

        std::pair<size_t, size_t> Size();

    private:
        int col, row;
        std::complex<double> **mat;
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
