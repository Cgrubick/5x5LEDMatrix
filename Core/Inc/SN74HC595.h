#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f0xx_hal.h"



void shift_register_init(uint8_t enable);
void pulse_pin(GPIO_TypeDef* GPIO_Port, uint16_t GPIO_Pin);
void shift_register_write(uint8_t data);
void shift_register_clear(void);
void shift_register_enable_output(uint8_t enable);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
