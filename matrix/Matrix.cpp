//
// Created by melalex on 4/28/17.
//

#include "Matrix.h"

Matrix::Matrix(const __long_double_t **matrix, __int64_t rows, __int64_t cols) {

}

Matrix::Matrix(const Matrix &other) {

}

Matrix::~Matrix() {

}

Matrix::Matrix(Matrix &&other) {

}

Matrix &Matrix::operator=(const Matrix &other) {
    return <#initializer#>;
}

Matrix &Matrix::operator=(Matrix &&other) {
    return <#initializer#>;
}

Matrix Matrix::operator*(const Matrix &other) const {
    return Matrix(nullptr, 0, 0);
}

Matrix Matrix::operator+(const Matrix &other) const {
    return Matrix(nullptr, 0, 0);
}

Matrix Matrix::operator-(const Matrix &other) const {
    return Matrix(nullptr, 0, 0);
}

std::ostream &operator<<(std::ostream &os, const Matrix &dt) {
    return <#initializer#>;
}

long double *Matrix::operator[](const int index) {
    return nullptr;
}

__int64_t Matrix::get_rows() const {
    return _rows;
}

__int64_t Matrix::get_cols() const {
    return _cols;
}

template<__int64_t row, __int64_t col>
Matrix::Matrix(const long double (*)[]) {

}

Matrix Matrix::transpose() const {
    return Matrix(nullptr, 0, 0);
}
