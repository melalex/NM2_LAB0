//
// Created by melalex on 4/27/17.
//

#include <limits>
#include <math.h>
#include "schultz_method.h"

inline bool end_condition(const Matrix &psi, float64_t eps) {
    return psi.norm() >= eps;
};

Matrix initial_approximation(const Matrix &A) {
    return A.transpose() / (A * A.transpose()).norm();
}




Matrix schultz_method::invertible_matrix(const Matrix &A, float64_t eps, std::ostream &out, bool enable_logging) {
    if (enable_logging) {
        out << "A is:" << std::endl;
        out << A << std::endl;
    }

    Matrix U = initial_approximation(A);
    if (enable_logging) {
        out << "Initial approximation is:" << std::endl;
        out << U << std::endl;
    }

    Matrix E = Matrix::identity_matrix(A.get_cols());
    Matrix psi = E - A * U;

    for (int i = 1; end_condition(psi, eps) && i < 20; i++) {
        U = U * (E + psi + psi * psi);
        psi = E - A * U;

        if (enable_logging) {
            out << i << " approximation is:" << std::endl;
            out << U << std::endl;

            out << i << " psi is:" << std::endl;
            out << psi << std::endl;
        }
    }

    return U;
}
