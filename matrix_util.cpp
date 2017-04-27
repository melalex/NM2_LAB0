//
// Created by melalex on 4/27/17.
//

#include <cstring>
#include <iomanip>
#include "matrix_util.h"

const int64_t COL_SIZE = 11;

void matrix_util::pretty_print(const __long_double_t **matrix, int64_t rows, int64_t cols,
                               std::ostream &out)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out << std::setw(COL_SIZE) << matrix[i][j];
        }
        out << std::endl;
    }
}

__long_double_t **matrix_util::copy(const __long_double_t **source, int64_t rows, int64_t cols)
{
    __long_double_t **copy = new __long_double_t*[rows];

    for (int i = 0; i < cols; i++) {
        memcpy(&copy[i], &source[i], cols * sizeof(__long_double_t));
    }

    return copy;
}

__long_double_t **matrix_util::add(const __long_double_t **a, const __long_double_t **b,
                                   int64_t rows, int64_t cols)
{

}

__long_double_t **matrix_util::subtract(const __long_double_t **a, const __long_double_t **b,
                                        int64_t rows, int64_t cols)
{

}

__long_double_t **matrix_util::multiply(const __long_double_t **a, const __long_double_t **b,
                                        int64_t rows, int64_t cols)
{

}
