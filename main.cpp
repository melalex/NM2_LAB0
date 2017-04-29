#include <iostream>
#include "algorithms/schultz_method.h"
#include "matrix/Matrix.h"
#include "constants.h"

void task_1();

void task_2();

void task_3();

int main() {
    task_1();
    task_2();
    task_3();

    return 0;
}

void task_1() {
    Matrix a_matrix(linear_system_1::A_POINTER, linear_system_1::A_ROWS, linear_system_1::A_COLS);
    Matrix b_vector(linear_system_1::B, linear_system_1::A_ROWS);

    Matrix inverted_a = schultz_method::invertible_matrix(a_matrix, linear_system_1::eps, std::cout);

    std::cout << "A^-1:" << std::endl;
    std::cout << inverted_a.round(linear_system_1::digits) << std::endl;

    std::cout << "X:" << std::endl;
    std::cout << inverted_a * b_vector.transpose() << std::endl;
}

void task_2() {

}

void task_3() {

}
