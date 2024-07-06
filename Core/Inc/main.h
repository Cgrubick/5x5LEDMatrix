/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void PRNG_Init(uint32_t s);
uint32_t PRNG_GetRandomNumber(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OE_NOT_Pin GPIO_PIN_0
#define OE_NOT_GPIO_Port GPIOA
#define RCLK_Pin GPIO_PIN_1
#define RCLK_GPIO_Port GPIOA
#define SRCLK_NOT_Pin GPIO_PIN_2
#define SRCLK_NOT_GPIO_Port GPIOA
#define SRCLK_Pin GPIO_PIN_3
#define SRCLK_GPIO_Port GPIOA
#define SER_Pin GPIO_PIN_4
#define SER_GPIO_Port GPIOA
#define R_5_Pin GPIO_PIN_5
#define R_5_GPIO_Port GPIOA
#define R_4_Pin GPIO_PIN_6
#define R_4_GPIO_Port GPIOA
#define R_3_Pin GPIO_PIN_7
#define R_3_GPIO_Port GPIOA
#define R_2_Pin GPIO_PIN_9
#define R_2_GPIO_Port GPIOA
#define R_1_Pin GPIO_PIN_10
#define R_1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
