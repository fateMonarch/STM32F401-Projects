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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <math.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */
uint32_t adcData[2], tiksay, potValue, adcValue;
int sayi, uyg;
double temperature;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_ADC1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);

  lcdInit();
  writeStr(1,0,"Gomulu Sistemler");
  writeStr(2,0,"Final Odevi");
  HAL_Delay(5000);
  clearLcd2();

  sayi=0; uyg=0; tiksay=0;
  writeStr(1,0,"Secim Yapiniz");
  writeStr(2,0,"Seciminiz: ");
  displayInt(2,11,sayi);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (uyg == 0) {
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);

	  	  clearLcd2();
	  	  writeStr(1,0,"Secim Yapiniz");
	  	  writeStr(2,0,"Seciminiz: ");
	  	  displayInt(2,11,sayi);
	  }
	  else if (uyg == 1) {
		  clearLcd2();
		  writeStr(1,0,"Projeyi Yapanlar:");
		  writeStr(2,0,"Ahmet Asfour");
	  }
	  else if (uyg == 15) {
		  clearLcd2();
		  writeStr(1,0,"Mert Kurt");
		  writeStr(2,0,"Yunus Delibas");
	  }
	  else if (uyg == 2) {
		  clearLcd2();
		  writeStr(1,0,"LED'ler yaniyor.");

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		  HAL_Delay(500);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		  HAL_Delay(500);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
	  }
	  else if (uyg == 3) {
		  clearLcd2();

		  ADC_ChannelConfTypeDef sConfig = {0};
		  sConfig.Channel = ADC_CHANNEL_5;
		  sConfig.Rank = 1;
		  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
		  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		  {
		      Error_Handler();
		  }

		  HAL_ADC_Start(&hadc1);
		  HAL_ADC_PollForConversion(&hadc1, 100);
		  potValue = HAL_ADC_GetValue(&hadc1);
		  HAL_ADC_Stop(&hadc1);
		  float voltage = (potValue / 4096.0) * 5.0;

		  writeStr(1, 0, "POT: ");
		  displayFloat(1, 5, voltage);
		  writeStr(1, 9, "V");

		  sConfig.Channel = ADC_CHANNEL_4;
		  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		  {
		      Error_Handler();
		  }

		  HAL_ADC_Start(&hadc1);
		  HAL_ADC_PollForConversion(&hadc1, 100);
		  adcValue = HAL_ADC_GetValue(&hadc1);
		  HAL_ADC_Stop(&hadc1);

		  float Rntc;
		  float Temperature;
		  float Vout = (adcValue / 4096.0) * 3.3;
		  Rntc = (10000.0 * Vout) / (3.3 - Vout);

		  float A = 1.009249522e-03;
		  float B = 2.378405444e-04;
		  float C = 2.019202697e-07;

		  Temperature = 1.0 / (A + B * log(Rntc) + C * pow(log(Rntc), 3));
		  Temperature = -(Temperature - 273.15);

		  writeStr(2, 0, "Sicaklik: ");
		  displayFloat(2, 10, Temperature);
		  writeStr(2, 15, "C");
	  }
	  else if (uyg == 4) {
		  clearLcd2();
	  }
	  else if (uyg == 5) {
		  clearLcd2();
		  writeStr(1,0,"1-4 arasi sayi");
		  writeStr(2,0,"giriniz lutfen!");
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 64;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 3;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA6 PA7 PA8 PA9
                           PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB13 PB14 PB15 PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB4 PB5 PB6
                           PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA11 PA12 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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
