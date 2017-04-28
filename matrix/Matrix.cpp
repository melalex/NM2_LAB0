//
// Created by melalex on 4/28/17.
//

#include <iomanip>
#include <cstring>
#include <math.h>
#include "Matrix.h"

Matrix::Matrix() : _matrix(nullptr), _cols(0), _rows(0) {}

Matrix::Matrix(const float64_t **matrix, u_int64_t rows, u_int64_t cols) :
        _matrix(_clone(matrix, rows, cols)), _rows(rows), _cols(cols) {}

Matrix::Matrix(float64_t **matrix, u_int64_t rows, u_int64_t cols) :
        _matrix(_clone(matrix, rows, cols)), _rows(rows), _cols(cols) {}

Matrix::Matrix(Matrix &other) : Matrix(other._matrix, other._rows, other._cols) {

}

Matrix::~Matrix() {
    _delete_matrix();
}

Matrix::Matrix(Matrix &&other) : Matrix(other._matrix, other._rows, other._cols) {
    other._matrix = nullptr;
    other._rows = 0;
    other._cols = 0;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        float64_t **tmp_matrix = _clone(other._matrix, other._rows, other._cols);

        _delete_matrix();

        _matrix = tmp_matrix;
        _rows = other._rows;
        _cols = other._cols;
    }
    
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) {
    if (this != &other) {
        _delete_matrix();

        _matrix = other._matrix;
        _rows = other._rows;
        _cols = other._cols;

        other._matrix = nullptr;
        other._rows = 0;
        other._cols = 0;
    }

    return *this;
}


Matrix::Matrix(u_int64_t rows, u_int64_t cols) : _rows(rows), _cols(cols) {
    _matrix = _empty_matrix(rows, cols);
}

Matrix::Matrix(const float64_t *matrix, u_int64_t cols)
        : _matrix(_clone(&matrix, 1, cols)), _rows(1), _cols(cols) {

}

Matrix::Matrix(float64_t *matrix, u_int64_t cols)
        : _matrix(_clone(&matrix, 1, cols)), _rows(1), _cols(cols) {

}

Matrix Matrix::operator*(const Matrix &other) const {
    if (_cols != other._rows) {
        throw std::invalid_argument("Invalid matrices");
    }

    float64_t **matrix = _empty_matrix(_rows, other._cols);

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            for (int r = 0; r < _cols; r++) {
                matrix[i][j] += _matrix[i][r] * other._matrix[r][j];
            }
        }
    }

    return _create_without_copy(matrix, _rows, other._cols);
}

Matrix Matrix::operator*(float64_t multiplier) const {
    float64_t **matrix = _clone(_matrix, _rows, _cols);

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            matrix[i][j] *= multiplier;
        }
    }

    return _create_without_copy(matrix, _rows, _cols);
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (other._cols != _cols || other._rows != _rows) {
        throw std::invalid_argument("Matrices has different dimensions");
    }

    float64_t **matrix = _clone(_matrix, _rows, _cols);

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            matrix[i][j] += other._matrix[i][j];
        }
    }

    return _create_without_copy(matrix, _rows, _cols);
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (other._cols != _cols || other._rows != _rows) {
        throw std::invalid_argument("Matrices has different dimensions");
    }

    float64_t **matrix = _clone(_matrix, _rows, _cols);

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            matrix[i][j] -= other._matrix[i][j];
        }
    }

    return _create_without_copy(matrix, _rows, _cols);
}

std::ostream &operator<<(std::ostream &os, const Matrix &dt) {
    for (int i = 0; i < dt._rows; i++) {
        for (int j = 0; j < dt._cols; j++) {
            os << std::setw(Matrix::COL_SIZE) << dt._matrix[i][j];
        }
        os << std::endl;
    }

    return os;
}

float64_t *Matrix::operator[](const int index) const {
    return _matrix[index];
}

u_int64_t Matrix::get_rows() const {
    return _rows;
}

u_int64_t Matrix::get_cols() const {
    return _cols;
}

Matrix Matrix::transpose() const {
    float64_t **transposed = _empty_matrix(_cols, _rows);

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            transposed[j][i] = _matrix[i][j];
        }
    }

    return _create_without_copy(_matrix, _cols, _rows);
}

Matrix Matrix::identity_matrix(u_int64_t size) {
    float64_t **matrix = new float64_t *[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new float64_t[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = i == j ? 1 : 0;
        }
    }

    return _create_without_copy(matrix, size, size);
}

Matrix Matrix::pow(u_int64_t pow) const {
    if (_cols != _rows) {
        throw std::logic_error("Matrix should be square");
    }

    float64_t **matrix = _clone(_matrix, _rows, _cols);

    for (int p = 0; p < pow; p++) {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                for (int r = 0; r < _cols; r++) {
                    matrix[i][j] += matrix[i][r] * _matrix[r][j];
                }
            }
        }
    }

    return _create_without_copy(matrix, _rows, _cols);
}

float64_t Matrix::evklid_norm() const {
    float64_t result = 0;

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            result += std::pow(_matrix[i][j], 2);
        }
    }

    return sqrt(result);
}

float64_t **Matrix::_clone(float64_t **source, u_int64_t rows, u_int64_t cols) {
    float64_t **copy = new float64_t *[rows];

    for (int i = 0; i < cols; i++) {
        memcpy(&copy[i], &source[i], (size_t) (cols * sizeof(float64_t)));
    }

    return copy;
}

float64_t **Matrix::_clone(const float64_t **source, u_int64_t rows, u_int64_t cols) {
    float64_t **copy = new float64_t *[rows];

    for (int i = 0; i < cols; i++) {
        memcpy(&copy[i], &source[i], (size_t) (cols * sizeof(float64_t)));
    }

    return copy;
}


void Matrix::_delete_matrix() {
    for (int i = 0; i < _rows; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}

float64_t **Matrix::_empty_matrix(u_int64_t rows, u_int64_t cols) {
    float64_t **matrix = new float64_t *[rows];

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new float64_t[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

Matrix Matrix::_create_without_copy(float64_t **matrix, u_int64_t rows, u_int64_t cols) {
    Matrix result;

    result._matrix = matrix;
    result._rows = rows;
    result._cols = cols;

    return result;
}