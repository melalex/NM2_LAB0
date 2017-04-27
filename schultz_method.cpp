//
// Created by melalex on 4/27/17.
//

#include "schultz_method.h"
#include "matrix_util.h"

__long_double_t **schultz_method::invertible_matrix(const __long_double_t **matrix, int64_t rows, int64_t cols,
                                                    std::ostream &out)
{
    __long_double_t **result = matrix_util::matrix_copy(matrix, rows, cols);

    return result;
}
