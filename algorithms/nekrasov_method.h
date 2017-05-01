//
// Created by melalex on 4/29/17.
//

#ifndef LAB0_NEKRASOV_METHOD_H
#define LAB0_NEKRASOV_METHOD_H

#include "../matrix/Matrix.h"

namespace nekrasov_method {

    Matrix solve(const Matrix &A, const Matrix &b, float64_t eps, std::ostream &out);

}
#endif //LAB0_NEKRASOV_METHOD_H
