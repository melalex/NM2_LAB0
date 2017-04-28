//
// Created by melalex on 4/28/17.
//

#ifndef LAB0_MATRIX_H
#define LAB0_MATRIX_H

#include <iostream>
#include "../constants.h"


class Matrix {
private:
    static const int64_t COL_SIZE = 11;

    int64_t _rows;
    int64_t _cols;
    float64_t **_matrix;

    static float64_t **clone(float64_t **matrix, int64_t rows, int64_t cols);
    static float64_t **clone(const float64_t **matrix, int64_t rows, int64_t cols);

    void delete_matrix();

public:
    static Matrix identity_matrix(int64_t size);

    template<int64_t row, int64_t col>
    static Matrix create(const float64_t matrix[row][col]);

    Matrix(const float64_t **matrix, int64_t rows, int64_t cols);

    Matrix(int64_t rows, int64_t cols);

    Matrix(Matrix &other);

    ~Matrix();

    Matrix(Matrix &&other);

    int64_t get_rows() const;

    int64_t get_cols() const;

    Matrix transpose() const;

    float64_t norm() const;

    Matrix &operator=(const Matrix &other);

    Matrix &operator=(Matrix &&other);

    Matrix operator*(const Matrix &other) const;

    Matrix operator+(const Matrix &other) const;

    Matrix operator-(const Matrix &other) const;

    float64_t *operator[](const int index) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &dt);
};

#endif //LAB0_MATRIX_H
