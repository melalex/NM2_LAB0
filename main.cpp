#include <iostream>
#include <iomanip>
#include "algorithms/schultz_method.h"
#include "algorithms/nekrasov_method.h"
#include "constants.h"

const int HEADER_WIDTH = 50;

void task_1(std::ostream &out);

void task_2(std::ostream &out);

void task_3(std::ostream &out);

int main() {
    task_1(std::cout);
    task_2(std::cout);
    task_3(std::cout);

    return 0;
}

inline void write_header(std::ostream &out, std::string message) {
    int message_margin = HEADER_WIDTH / 2;

    out << "|" << std::string(HEADER_WIDTH, '=') << "|" << std::endl;

    out << "|" << std::setw(message_margin  + 1) << message << std::setw(HEADER_WIDTH - message_margin)
        << "|" << std::endl;

    out << "|" << std::string(HEADER_WIDTH, '=') << "|" << std::endl << std::endl;
}

void task_1(std::ostream &out) {
    Matrix A(linear_system_1::A_POINTER, linear_system_1::A_ROWS, linear_system_1::A_COLS);
    Matrix b(linear_system_1::B, linear_system_1::A_ROWS);
    std::clock_t start;
    double duration;

    write_header(out, "Task 1:");

    start = std::clock();

    Matrix inverted_a = schultz_method::invertible_matrix(A, linear_system_1::eps, out);

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    out << "A^-1:" << std::endl;
    out << inverted_a.round(linear_system_1::digits) << std::endl;
    out << "Time duration: " << duration << std::endl << std::endl;

    out << "X:" << std::endl;
    out << inverted_a * b.transpose() << std::endl;
}

void task_2(std::ostream &out) {
    Matrix A(linear_system_1::A_POINTER, linear_system_1::A_ROWS, linear_system_1::A_COLS);
    Matrix b = Matrix(linear_system_1::B, linear_system_1::A_ROWS).transpose();
    std::clock_t start;
    double duration;

    write_header(out, "Task 2:");

    start = std::clock();

    Matrix X = nekrasov_method::solve(A, b, 0, out);

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    out << "X:" << std::endl;
    out << X << std::endl;
    out << "Time duration: " << duration << std::endl << std::endl;
}

void task_3(std::ostream &out) {

}
