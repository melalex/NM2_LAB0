#include <iostream>
#include "target.h"
#include "schultz_method.h"
#include "matrix_util.h"

void task1(const __long_double_t **source, int64_t rows, int64_t cols,
           const __long_double_t *b, std::ostream &out);

int main()
{
    task1(linear_system_1::A_pointer, linear_system_1::A_ROWS, linear_system_1::A_COLS,
          linear_system_1::b, std::cout);

    return 0;
}

void task1(const __long_double_t **A, int64_t rows, int64_t cols,
           const __long_double_t *b, std::ostream &out)
{
    const __long_double_t **answer =
            const_cast<const __long_double_t **>(schultz_method::invertible_matrix(A, rows, cols, out));

    matrix_util::matrix_pretty_print(answer, rows, cols, out);

    delete[] answer;
}