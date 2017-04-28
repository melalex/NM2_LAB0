//
// Created by melalex on 4/28/17.
//

#include <iomanip>
#include "Matrix.h"

Matrix::Matrix(float64_t **matrix, int64_t rows, int64_t cols) :
        _matrix(clone(matrix, rows, cols)), _rows(rows), _cols(cols) {}

Matrix::Matrix(Matrix &other) : Matrix(other._matrix, other._rows, other._cols) {
    Matrix(other._matrix, other._rows, other._cols);
}

Matrix::~Matrix() {
    delete_matrix();
}

Matrix::Matrix(Matrix &&other) : Matrix(other._matrix, other._rows, other._cols) {
    other._matrix = nullptr;
    other._rows = 0;
    other._cols = 0;
}

Matrix &Matrix::operator=(const Matrix &other) {
    float64_t **tmp_matrix = clone(other._matrix, other._rows, other._cols);

    delete_matrix();

    _matrix = tmp_matrix;
    _rows = other._rows;
    _cols = other._cols;

    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) {
    delete_matrix();

    _matrix = other._matrix;
    _rows = other._rows;
    _cols = other._cols;

    other._matrix = nullptr;
    other._rows = 0;
    other._cols = 0;

    return *this;
}


Matrix::Matrix(int64_t rows, int64_t cols) : _rows(rows), _cols(cols) {
    float64_t **matrix = new float64_t *[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float64_t[cols];
    }

    _matrix = matrix;
}

template<int64_t row, int64_t col>
Matrix::Matrix(float64_t matrix[row][col]) : _rows(row), _cols(col) {
    _matrix = new float64_t *[row];

    for (int i = 0; i < row; i++) {
        _matrix[i] = matrix[i];
    }
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
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            os << std::setw(COL_SIZE) << _matrix[i][j];
        }
        os << std::endl;
    }

    return os;
}

float64_t *Matrix::operator[](const int index) const {
    return _matrix[index];
}

int64_t Matrix::get_rows() const {
    return _rows;
}

int64_t Matrix::get_cols() const {
    return _cols;
}

Matrix Matrix::transpose() const {
    return Matrix(nullptr, 0, 0);
}

Matrix Matrix::identity_matrix(int64_t size) {
    return Matrix(nullptr, 0, 0);
}

float64_t Matrix::norm() const {
    return 0;
}

float64_t **Matrix::clone(float64_t **source, int64_t rows, int64_t cols) {
    float64_t **copy = new float64_t *[rows];

    for (int i = 0; i < cols; i++) {
        memcpy(&copy[i], &source[i], (size_t) (cols * sizeof(float64_t)));
    }

    return copy;
}

void Matrix::delete_matrix() {
    for (int i = 0; i < _rows; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}