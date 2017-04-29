//
// Created by melalex on 4/28/17.
//

#ifndef LAB0_MATRIX_H
#define LAB0_MATRIX_H

#include <iostream>
#include "../types.h"

class Matrix {
private:
    Matrix();

    Matrix(float64_t **matrix, u_int64_t rows, u_int64_t cols);

    static const u_int64_t COL_SIZE = 15;

    u_int64_t _rows;
    u_int64_t _cols;
    float64_t **_matrix;

    static float64_t **_empty_matrix(u_int64_t rows, u_int64_t cols);
    static Matrix _create_without_copy(float64_t **matrix, u_int64_t rows, u_int64_t cols);

    static float64_t **_clone(float64_t **matrix, u_int64_t rows, u_int64_t cols);
    static float64_t **_clone(const float64_t **matrix, u_int64_t rows, u_int64_t cols);

    void _delete_matrix();

public:
    static Matrix identity_matrix(u_int64_t size);

    Matrix(const float64_t **matrix, u_int64_t rows, u_int64_t cols);

    Matrix(const float64_t *matrix, u_int64_t cols);
    Matrix(float64_t *matrix, u_int64_t cols);

    Matrix(u_int64_t rows, u_int64_t cols);

    Matrix(Matrix &other);

    ~Matrix();

    Matrix(Matrix &&other);

    u_int64_t get_rows() const;

    u_int64_t get_cols() const;

    Matrix transpose() const;

    float64_t norm() const;

    Matrix round(u_int64_t digits) const;

    Matrix &operator=(const Matrix &other);

    Matrix &operator=(Matrix &&other);

    Matrix operator*(const Matrix &other) const;

    Matrix operator*(float64_t multiplier) const;

    Matrix operator/(float64_t divider) const;

    Matrix operator+(const Matrix &other) const;

    Matrix operator-(const Matrix &other) const;

    float64_t *operator[](const int index) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &dt);
};

#endif //LAB0_MATRIX_H
