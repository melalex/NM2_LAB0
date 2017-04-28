#include <iostream>
#include "algorithms/schultz_method.h"
#include "matrix/Matrix.h"
#include "constants.h"

//void task1(const float64_t **source, int64_t rows, int64_t cols,
//           const float64_t *b, std::ostream &out);

int main() {
    Matrix matrix(linear_system_1::A_pointer, linear_system_1::A_ROWS, linear_system_1::A_COLS);

    std::cout << matrix;

    return 0;
}

//void task1(const float64_t **A, int64_t rows, int64_t cols,
//           const float64_t *b, std::ostream &out) {
//    const float64_t **answer =
//            const_cast<const float64_t **>(schultz_method::invertible_matrix(A, rows, cols, out));
//
//
//    delete[] answer;
//}