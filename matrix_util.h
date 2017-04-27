//
// Created by melalex on 4/27/17.
//

#ifndef LAB0_MATRIX_UTIL_H
#define LAB0_MATRIX_UTIL_H

#include <iostream>

namespace matrix_util {

    void pretty_print(const __long_double_t **matrix, int64_t rows, int64_t cols, std::ostream &out);

    __long_double_t **copy(const __long_double_t **source, int64_t rows, int64_t cols);

    __long_double_t **add(const __long_double_t **a, const __long_double_t **b, int64_t rows, int64_t cols);

    __long_double_t **subtract(const __long_double_t **a, const __long_double_t **b, int64_t rows, int64_t cols);

    __long_double_t **multiply(const __long_double_t **a, const __long_double_t **b, int64_t rows, int64_t cols);
}
#endif //LAB0_MATRIX_UTIL_H
