//
// Created by melalex on 4/29/17.
//

#include "nekrasov_method.h"

inline float64_t sum(int i, int begin, int end, const Matrix &A, const Matrix &X) {
    float64_t result = 0;

    for (int j = begin; j <= end; j++) {
        result += A[i][j] * X[j][0];
    }

    return result;
}

inline bool condition(Matrix x, Matrix prev_x, float64_t eps) {
    return (x - prev_x).max() >= eps;
}

Matrix nekrasov_method::solve(const Matrix &A, const Matrix &b, float64_t eps, std::ostream &out) {
    out << "A is:" << std::endl;
    out << A << std::endl;
    out << "b is:" << std::endl;
    out << b << std::endl;

    u_int64_t n = b.get_rows();

    Matrix X(n, 1);
    Matrix prev_X;

    float64_t sum_1;
    float64_t sum_2;

    for (int k = 1; k == 1 || condition(X, prev_X, eps) && k < 10; k++) {
        for (int i = 0; i < n; i++) {
            sum_1 = sum(i, 0, i - 1, A, X);
            sum_2 = sum(i, i + 1, n - 1, A, prev_X);

            X[i][0] = (-1 / A[i][i]) * (sum_1 + sum_2 - b[i][0]);
        }
        out << k << " X is:" << std::endl;
        out << X << std::endl;
        prev_X = X;
    }

    return X;
}
