//
// Created by melalex on 4/27/17.
//

#ifndef LAB0_CONSTANTS_H
#define LAB0_CONSTANTS_H

#include "types.h"

namespace linear_system_1 {
    const float64_t TEST_A[4][4] = {
            {1,  5,  3, -4},
            {3,  1, -2,  0},
            {5, -7, 10,  0},
            {0,  3,  0, -5},
    };

    const u_int64_t TEST_ROWS = sizeof TEST_A / sizeof TEST_A[0];
    const u_int64_t TEST_COLS = sizeof TEST_A[0] / sizeof(float64_t);

    const float64_t *TEST_POINTER[4] = {TEST_A[0], TEST_A[1], TEST_A[2], TEST_A[3]};

    const float64_t TEST_B[4] = {20, 9, -9, 1};


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

    const u_int64_t A_ROWS = sizeof A / sizeof A[0];
    const u_int64_t A_COLS = sizeof A[0] / sizeof(float64_t);

    const float64_t eps = 1.0E-5;
    const u_int64_t digits = 5;

    const float64_t *A_POINTER[9] = {A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8]};

    const float64_t B[9] = {10, -21, -94, 93, 87, 68, -100, 37, 55};
}

namespace linear_system_2 {
    const float64_t A[10][10] = {
            { 20, -12, -11,  4,  1,  10, -10,  -2,  -1,  7},
            {-12,  20,  16,  6,  2, -16,   7,   2,  -1, -7},
            {-11,  16,  24,  1,  5, -11,  11,   2,   2, -2},
            {  4,   6,   1,  9,  0,  -5,   1,  -1,   2, -1},
            {  1,   2,   5,  0, 10,   6,  -2,   4,  -6,  0},
            { 10, -16, -11, -5,  6,  28,  -5,  11,  -3, 12},
            {-10,   7,  11,  1, -2,  -5,  19,  -1,  11, -6},
            { -2,   2,   2, -1,  4,  11,  -1,  22, -15, 14},
            { -1,  -1,   2,  2, -6,  -3,  11, -15,  30, -4},
            {  7,  -7,  -2, -1,  0,  12,  -6,  14,  -4, 30}
    };

    const u_int64_t A_ROWS = sizeof A / sizeof A[0];
    const u_int64_t A_COLS = sizeof A[0] / sizeof(float64_t);

    const float64_t eps = 1.0E-5;
    const u_int64_t digits = 5;

    const float64_t *A_POINTER[10] = {A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8], A[9]};

    const float64_t B[10] = {-27, 15, 8, -20, 28, -13, 30, -35, 14, 1};
}

namespace linear_system_3 {
    const float64_t A[10][10] = {
            {-304, -230,    0,   0,    0,    0,    0,    0,   0,   0},
            {-312,  769,  331,   0,    0,    0,    0,    0,   0,   0},
            {   0,  -91, -202, -32,    0,    0,    0,    0,   0,   0},
            {   0,    0,  139, 472,   21,    0,    0,    0,   0,   0},
            {   0,    0,    0, 147,  373, -166,    0,    0,   0,   0},
            {   0,    0,    0,   0, -178, -393, -120,    0,   0,   0},
            {   0,    0,    0,   0,    0,   98,  441,  167,   0,   0},
            {   0,    0,    0,   0,    0,    0,  -71,  165,  70,   0},
            {   0,    0,    0,   0,    0,    0,    0, -129, 601,  26},
            {   0,    0,    0,   0,    0,    0,    0,    0, 418, 970}
    };

    const u_int64_t A_ROWS = sizeof A / sizeof A[0];
    const u_int64_t A_COLS = sizeof A[0] / sizeof(float64_t);

    const float64_t eps = 1.0E-5;
    const u_int64_t digits = 5;

    const float64_t *A_POINTER[10] = {A[0], A[1], A[2], A[3], A[4], A[5], A[6], A[7], A[8], A[9]};

    const float64_t B[10] = {678, -134, -59, 121, -462, 498, 8, 294, -385, -723};
}

#endif //LAB0_CONSTANTS_H
