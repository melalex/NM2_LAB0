//
// Created by melalex on 4/27/17.
//

#ifndef LAB0_SCHULTZ_METHOD_H
#define LAB0_SCHULTZ_METHOD_H

#include <iostream>
#include "../types.h"
#include "../matrix/Matrix.h"

namespace schultz_method {

    Matrix invertible_matrix(const Matrix &source, float64_t eps, std::ostream &out);

}
#endif //LAB0_SCHULTZ_METHOD_H
