/*
 * debug.c
 *
 *  Created on: Sep 3, 2018
 *      Author: 74hc0
 */

#include "usart.h"
#include <string.h>

void debug_print(char* text)
{
	size_t len = strlen(text);
	HAL_UART_Transmit(&huart6, (uint8_t*)text, len, 1000);
}

