//
// Created by melalex on 4/27/17.
//

#ifndef LAB0_SCHULTZ_METHOD_H
#define LAB0_SCHULTZ_METHOD_H

#include <iostream>
#include "../types.h"

namespace schultz_method {

    float64_t **invertible_matrix(const float64_t **source, int64_t rows, int64_t cols,
                                        std::ostream &out);

}
#endif //LAB0_SCHULTZ_METHOD_H
