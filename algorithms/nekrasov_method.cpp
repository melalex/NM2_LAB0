//
// Created by melalex on 4/29/17.
//

#include "nekrasov_method.h"
#include "schultz_method.h"

using namespace schultz_method;

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

inline Matrix get_left(const Matrix &matrix) {
    Matrix L(matrix.get_rows(), matrix.get_cols());

    for (int i = 0; i < L.get_rows(); i++) {
        for (int j = 0; j < i; j++) {
            L[i][j] = matrix[i][j];
        }
    }

    return L;
}

inline Matrix get_right(const Matrix &matrix) {
    Matrix R(matrix.get_rows(), matrix.get_cols());

    for (int i = 0; i < R.get_rows(); i++) {
        for (int j = i + 1; j < R.get_cols(); j++) {
            R[i][j] = matrix[i][j];
        }
    }

    return R;
}

inline Matrix get_diagonal(const Matrix &matrix) {
    Matrix D(matrix.get_rows(), matrix.get_cols());

    for (int i = 0; i < D.get_rows(); i++) {
        D[i][i] = matrix[i][i];
    }

    return D;
}

Matrix nekrasov_method::solve(const Matrix &A, const Matrix &b, float64_t eps, std::ostream &out) {
    out << "A is:" << std::endl;
    out << A << std::endl;
    out << "b is:" << std::endl;
    out << b << std::endl;

    u_int64_t n = b.get_rows();

    Matrix L = get_left(A);
    Matrix R = get_right(A);
    Matrix D = get_diagonal(A);
    Matrix T = invertible_matrix(L + D, eps, out, false);
    Matrix X(n, 1);
    Matrix prev_X(n, 1);

    for (int k = 1; k < 10; k++) {
        X = (T * R * prev_X) * (-1) + T * b;

        out << k << " X is:" << std::endl;
        out << X << std::endl;
        prev_X = X;
    }

    return X;
}
