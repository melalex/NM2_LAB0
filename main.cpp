#include <iostream>
#include "constants.h"
#include "algorithms/schultz_method.h"

void task1(const float64_t **source, int64_t rows, int64_t cols,
           const float64_t *b, std::ostream &out);

int main() {
    task1(linear_system_1::A_pointer, linear_system_1::A_ROWS, linear_system_1::A_COLS,
          linear_system_1::b, std::cout);

    return 0;
}

void task1(const float64_t **A, int64_t rows, int64_t cols,
           const float64_t *b, std::ostream &out) {
    const float64_t **answer =
            const_cast<const float64_t **>(schultz_method::invertible_matrix(A, rows, cols, out));


    delete[] answer;
}