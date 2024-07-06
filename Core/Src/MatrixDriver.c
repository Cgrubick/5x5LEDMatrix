/*
 * MatrixDriver.c
 *
 *  Created on: Jul 1, 2024
 *      Author: cgrubick
 */


#include "MatrixDriver.h"
#include "main.h"
#include "SN74HC595.h"


int ignite_led(uint8_t x, uint8_t y, uint32_t delay) {

	shift_register_write(0x00);
    // Reset all rows to avoid residual lighting
    HAL_GPIO_WritePin(R_1_GPIO_Port, R_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_2_GPIO_Port, R_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_3_GPIO_Port, R_3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_4_GPIO_Port, R_4_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_5_GPIO_Port, R_5_Pin, GPIO_PIN_RESET);


    // Enable the specific row
    enable_row(y);


    // Set the specific column
    shift_register_write(1 << x);

    // Delay for a short period to allow the LED to be visible
    HAL_Delay(delay);

    // Clear the shift register to turn off the LED
    shift_register_write(0);

    // Reset all rows to avoid residual lighting
    HAL_GPIO_WritePin(R_1_GPIO_Port, R_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_2_GPIO_Port, R_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_3_GPIO_Port, R_3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_4_GPIO_Port, R_4_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(R_5_GPIO_Port, R_5_Pin, GPIO_PIN_RESET);

    return 1; // Returns 1 for success
}

void enable_row(uint8_t row){
	init_matrix();

	    // Set the selected row
	switch(row) {
		case 0:
			HAL_GPIO_WritePin(R_1_GPIO_Port, R_1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
	        HAL_GPIO_WritePin(R_2_GPIO_Port, R_2_Pin, GPIO_PIN_RESET);
	        break;
	    case 2:
	        HAL_GPIO_WritePin(R_3_GPIO_Port, R_3_Pin, GPIO_PIN_RESET);
	        break;
	    case 3:
	        HAL_GPIO_WritePin(R_4_GPIO_Port, R_4_Pin, GPIO_PIN_RESET);
	        break;
	    case 4:
	        HAL_GPIO_WritePin(R_5_GPIO_Port, R_5_Pin, GPIO_PIN_RESET);
	        break;
	}
}

void init_matrix(void){
	HAL_GPIO_WritePin(R_1_GPIO_Port, R_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R_2_GPIO_Port, R_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R_3_GPIO_Port, R_3_Pin, GPIO_PIN_SET); // Assume active low SRCLK
	HAL_GPIO_WritePin(R_4_GPIO_Port, R_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R_5_GPIO_Port, R_5_Pin, GPIO_PIN_SET);
}

void display_matrix_array(uint8_t led_array[5][5], uint32_t delay){

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(led_array[i][j] == 1){
				ignite_led(j, i, delay);
			}
		}
	}
}


