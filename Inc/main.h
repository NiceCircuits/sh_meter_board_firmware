/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define ADE_REVP_Pin GPIO_PIN_13
#define ADE_REVP_GPIO_Port GPIOC
#define CAN_LED_G_Pin GPIO_PIN_14
#define CAN_LED_G_GPIO_Port GPIOC
#define CAN_LED_R_Pin GPIO_PIN_15
#define CAN_LED_R_GPIO_Port GPIOC
#define DEBUG_TXD_Pin GPIO_PIN_0
#define DEBUG_TXD_GPIO_Port GPIOC
#define DEBUG_RXD_Pin GPIO_PIN_1
#define DEBUG_RXD_GPIO_Port GPIOC
#define OUT2_LED_R_Pin GPIO_PIN_2
#define OUT2_LED_R_GPIO_Port GPIOC
#define OUT2_LED_G_Pin GPIO_PIN_3
#define OUT2_LED_G_GPIO_Port GPIOC
#define ADE_CS_Pin GPIO_PIN_1
#define ADE_CS_GPIO_Port GPIOA
#define REL1_SET_Pin GPIO_PIN_2
#define REL1_SET_GPIO_Port GPIOA
#define OUT1_LED_R_Pin GPIO_PIN_3
#define OUT1_LED_R_GPIO_Port GPIOA
#define THERM_Pin GPIO_PIN_4
#define THERM_GPIO_Port GPIOA
#define OUT1_LED_RA5_Pin GPIO_PIN_5
#define OUT1_LED_RA5_GPIO_Port GPIOA
#define MEAS_5V_Pin GPIO_PIN_1
#define MEAS_5V_GPIO_Port GPIOB
#define REL2_RST_Pin GPIO_PIN_15
#define REL2_RST_GPIO_Port GPIOA
#define REL2_SET_Pin GPIO_PIN_10
#define REL2_SET_GPIO_Port GPIOC
#define REL2_RSTC11_Pin GPIO_PIN_11
#define REL2_RSTC11_GPIO_Port GPIOC
#define ADE_RESET_Pin GPIO_PIN_12
#define ADE_RESET_GPIO_Port GPIOC
#define ADE_ZX_Pin GPIO_PIN_2
#define ADE_ZX_GPIO_Port GPIOD
#define ADE_SCLK_Pin GPIO_PIN_3
#define ADE_SCLK_GPIO_Port GPIOB
#define ADE_MISO_Pin GPIO_PIN_4
#define ADE_MISO_GPIO_Port GPIOB
#define ADE_MOSI_Pin GPIO_PIN_5
#define ADE_MOSI_GPIO_Port GPIOB
#define ADE_CF2_Pin GPIO_PIN_6
#define ADE_CF2_GPIO_Port GPIOB
#define ADE_CF1_Pin GPIO_PIN_7
#define ADE_CF1_GPIO_Port GPIOB
#define ADE_IRQ_Pin GPIO_PIN_8
#define ADE_IRQ_GPIO_Port GPIOB
#define ADE_ZX_I_Pin GPIO_PIN_9
#define ADE_ZX_I_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
