#include "SN74HC595.h"
#include "main.h"
#include <stdbool.h>



// Initialize the GPIO pins

void shift_register_init(uint8_t enable) {
    // Set initial pin states
	shift_register_enable_output(enable);
	HAL_GPIO_WritePin(SER_GPIO_Port, SER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SRCLK_GPIO_Port, SRCLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RCLK_GPIO_Port, RCLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SRCLK_NOT_GPIO_Port, SRCLK_NOT_Pin, GPIO_PIN_SET); // Normal operation (not clearing)
}

void shift_register_write(uint8_t data) {
    for (uint8_t i = 0; i < 8; i++) {
        // Set the SER pin to the value of the current bit
        HAL_GPIO_WritePin(SER_GPIO_Port, SER_Pin, (data & (1 << (7 - i))) ? GPIO_PIN_SET : GPIO_PIN_RESET);

        // Pulse the SRCLK pin
        pulse_pin(SRCLK_GPIO_Port, SRCLK_Pin);
    }

    // Pulse the RCLK pin to latch the data
    pulse_pin(RCLK_GPIO_Port, RCLK_Pin);
}

void shift_register_clear(void) {
    // Clear function implementation if needed
}

void shift_register_enable_output(uint8_t enable) {
    if (enable) {
        HAL_GPIO_WritePin(OE_NOT_GPIO_Port, OE_NOT_Pin, GPIO_PIN_RESET); // Enable output
    } else {
        HAL_GPIO_WritePin(OE_NOT_GPIO_Port, OE_NOT_Pin, GPIO_PIN_SET); // Disable output
    }
}

void pulse_pin(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin) {
    HAL_GPIO_WritePin(GPIO_Port, GPIO_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIO_Port, GPIO_Pin, GPIO_PIN_RESET);
}
