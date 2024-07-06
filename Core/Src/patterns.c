/*
 * patterns.c
 *
 *  Created on: Jul 3, 2024
 *      Author: cgrubick
 */

#include "patterns.h"
#include "MatrixDriver.h"



const uint8_t heartPattern[HEART_PATTERN_SIZE][2] = {
    {2, 0},
    {1, 1}, {3, 1},
    {0, 2}, {4, 2}, {2,3},
    {0, 3}, {4, 3},
    {1, 4}, {3, 4},
    {2, 5}
};

const uint8_t spiralPattern[SPIRAL_PATTERN_SIZE][2] = {
    {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4},
    {1, 4}, {2, 4}, {3, 4}, {4, 4},
    {4, 3}, {4, 2}, {4, 1}, {4, 0},
    {3, 0}, {2, 0}, {1, 0},
    {1, 1}, {1, 2}, {1, 3},
    {2, 3}, {3, 3},
    {3, 2}, {3, 1},
    {2, 1}, {2, 2}
};

void displayPattern(const uint8_t pattern[][2], size_t size, uint32_t delay) {
    for (size_t i = 0; i < size; ++i) {
        ignite_led(pattern[i][0], pattern[i][1], delay);
    }
}

