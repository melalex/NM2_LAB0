//
// Created by melalex on 4/27/17.
//

#include <limits>
#include <math.h>
#include "schultz_method.h"

//const float64_t test_initial_approximation[3][3] = {
//        {0.6, -0.5, -0.4},
//        {0.1, 0.6,  0.2},
//        {0.1, -0.5, 0.5},
//};
//
//const float64_t *TEST_A_BUFF[3] = {
//        test_initial_approximation[0],
//        test_initial_approximation[1],
//        test_initial_approximation[2]
//};
//const float64_t **TEST_A_POINTER = TEST_A_BUFF;


inline bool end_condition(const Matrix &psi, float64_t eps) {
    return psi.evklid_norm() >= eps;
};

Matrix initial_approximation(const Matrix &A) {
    return A.transpose() / (A * A.transpose()).evklid_norm();
//    return A.transpose() * 1.0E-10;
//    return Matrix(TEST_A_POINTER, 3, 3);
}

Matrix schultz_method::invertible_matrix(const Matrix &A, float64_t eps, std::ostream &out) {
    out << "A is:" << std::endl;
    out << A << std::endl;

    Matrix U = initial_approximation(A);
    out << "Initial approximation is:" << std::endl;
    out << U << std::endl;


    Matrix E = Matrix::identity_matrix(A.get_cols());
    Matrix psi = E - A * U;

    for (int i = 1; end_condition(psi, eps) && i < 20; i++) {
        U = U * (E + psi);
        psi = E - A * U;

        out << i << " approximation is:" << std::endl;
        out << U << std::endl;

        out << i << " psi is:" << std::endl;
        out << psi << std::endl;
    }

    return U;
}
