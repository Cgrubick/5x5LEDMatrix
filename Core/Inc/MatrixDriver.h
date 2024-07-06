/*
 * MatrixDriver.h
 *
 *  Created on: Jul 1, 2024
 *      Author: cgrubick
 */

#ifndef INC_MATRIXDRIVER_H_
#define INC_MATRIXDRIVER_H_


#include "stm32f0xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

void enable_row(uint8_t row);
int ignite_led(uint8_t x, uint8_t y, uint32_t delay);
void init_matrix(void);
void display_matrix_array(uint8_t led_array[5][5], uint32_t delay);


#ifdef __cplusplus
}
#endif

#endif /* INC_MATRIXDRIVER_H_ */
