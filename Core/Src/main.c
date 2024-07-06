/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "SN74HC595.h"
#include "MatrixDriver.h"
#include "patterns.h"


void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
	uint8_t enable = 1;
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	shift_register_init(enable);

	uint8_t led_array[5][5] = 	{
								{0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0},
								{0, 0, 0, 0, 0}
								};

	uint32_t delay = 150;
	uint32_t min = 0;
	uint32_t max = 4;
	while (1)
	{
		// patterns
		// heartPattern, HEART_PATTERN_SIZE
		// spiralPattern, SPIRAL_PATTERN_SIZE
		//display_matrix_array(led_array, delay);
		//HAL_delay(100);
		displayPattern(spiralPattern, SPIRAL_PATTERN_SIZE, 100);
//		uint32_t random_y = PRNG_GetRandomNumber() % (max - min + 1) + min; //generate rand numb and get between range of 0-4
//		uint32_t random_x = PRNG_GetRandomNumber() % (max - min + 1) + min;
//		ignite_led(random_x, random_y, delay);
	}
}

uint32_t seed = 0x12345678;

void PRNG_Init(uint32_t s) {
    seed = s;
}

uint32_t PRNG_GetRandomNumber(void) {
    // LCG parameters
    const uint32_t a = 1664525;
    const uint32_t c = 1013904223;
    seed = (a * seed + c);
    return seed;
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}
/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, OE_NOT_Pin|RCLK_Pin|SRCLK_NOT_Pin|SRCLK_Pin
                          |SER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : OE_NOT_Pin RCLK_Pin SRCLK_NOT_Pin SRCLK_Pin
                           SER_Pin */
  GPIO_InitStruct.Pin = OE_NOT_Pin|RCLK_Pin|SRCLK_NOT_Pin|SRCLK_Pin
                          |SER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Col_1_Anode_Pin Col_2_Anode_Pin Col_3_Anode_Pin Col_4_Anode_Pin
                           Col_5_Anode_Pin */
  GPIO_InitStruct.Pin = R_1_Pin|R_2_Pin|R_3_Pin|R_4_Pin|R_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
