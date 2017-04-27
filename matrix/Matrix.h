//
// Created by melalex on 4/28/17.
//

#ifndef LAB0_MATRIX_H
#define LAB0_MATRIX_H

#include <bits/types.h>
#include <iostream>

class Matrix {
private:
    __int64_t _rows;
    __int64_t _cols;
    __long_double_t **_matrix;
public:
    Matrix(const __long_double_t **matrix, __int64_t rows, __int64_t cols);

    template<__int64_t row, __int64_t col>
    Matrix(const __long_double_t[row][col]);

    Matrix(const Matrix &other);

    ~Matrix();

    Matrix(Matrix &&other);

    __int64_t get_rows() const;

    __int64_t get_cols() const;

    Matrix transpose() const;

    // TODO: add norm

    Matrix &operator=(const Matrix &other);

    Matrix &operator=(Matrix &&other);

    Matrix operator*(const Matrix &other) const;

    Matrix operator+(const Matrix &other) const;

    Matrix operator-(const Matrix &other) const;

    __long_double_t *operator[](const int index);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &dt);
};


#endif //LAB0_MATRIX_H
