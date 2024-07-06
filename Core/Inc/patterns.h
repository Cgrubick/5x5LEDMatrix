/*
 * patterns.h
 *
 *  Created on: Jul 3, 2024
 *      Author: cgrubick
 */

#ifndef INC_PATTERNS_H_
#define INC_PATTERNS_H_

#include "stm32f0xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SPIRAL_PATTERN_SIZE 25
#define HEART_PATTERN_SIZE 11

extern const uint8_t heartPattern[HEART_PATTERN_SIZE][2];

extern const uint8_t spiralPattern[SPIRAL_PATTERN_SIZE][2];

void spiral(uint32_t delay);
void displayPattern(const uint8_t pattern[][2], size_t size, uint32_t delay);



#ifdef __cplusplus
}
#endif


#endif /* INC_PATTERNS_H_ */
