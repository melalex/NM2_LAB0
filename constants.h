//
// Created by melalex on 4/27/17.
//

#ifndef LAB0_CONSTANTS_H
#define LAB0_CONSTANTS_H

typedef long double float64_t;

namespace linear_system_1 {
    const float64_t A[9][9] = {
            { 57, -69,   3,  81, -11,  17, -50,  80,  14},
            {  3,  26,  47,  87,  43, -22,  23,  14,   4},
            {-89,  53,  -8,  95, -93,  70,  77, -71,   2},
            { 65, -78,  27,  23,  45,  -5, -58,  32, -77},
            { 38,  76,  12, -16, -88,  62, -99, -84, -75},
            {  3,  15,  50, -44,  38,  32,  44,  43,  -9},
            {-54, -73, -62, -45,  35,  41, -23,  39,  -6},
            { 80, -21, -83,  87, -14,  28, -96, -77,  34},
            { 6,   99, -76,  38,  25, -11,  31, -72,  34}
    };

    const int64_t A_ROWS = sizeof A / sizeof A[0];
    const int64_t A_COLS = sizeof A[0] / sizeof(float64_t);

    const float64_t *A_rows[9] = {A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8]};
    const float64_t **A_pointer = A_rows;

    const float64_t b[9] = {10, -21, -94, 93, 87, 68, -100, 37, 55};
}

#endif //LAB0_CONSTANTS_H
