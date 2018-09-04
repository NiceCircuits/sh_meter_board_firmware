/*
 * ade.c
 *
 *  Created on: Sep 3, 2018
 *      Author: 74hc0
 */

#include "stm32f0xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "spi.h"
#include "debug.h"

HAL_StatusTypeDef adeInit();
HAL_StatusTypeDef adeWrite(uint16_t addr, uint32_t data, size_t len);
HAL_StatusTypeDef adeRead(uint16_t addr, uint32_t *data, size_t len);

HAL_StatusTypeDef adeWrite(uint16_t addr, uint32_t data, uint_fast8_t len)
{
	uint8_t buf[] =
	{ 0, 0, 0, 0, 0, 0, 0 };
	HAL_StatusTypeDef ret;
	buf[0] = (uint8_t) (addr >> 8);
	buf[1] = (uint8_t) (addr);
	for (uint_fast8_t i = 7 - len; i > 2; i--)
	{
		buf[i] = (uint8_t) data;
		data >>= 8;
	}
	len += 3;
	HAL_GPIO_WritePin(ADE_CS_GPIO_Port, ADE_CS_Pin, GPIO_PIN_RESET);
	ret = HAL_SPI_Transmit(&hspi1, buf, len, 100);
	HAL_GPIO_WritePin(ADE_CS_GPIO_Port, ADE_CS_Pin, GPIO_PIN_SET);
	return ret;
}

HAL_StatusTypeDef adeRead(uint16_t addr, uint32_t *data, uint_fast8_t len)
{
	len += 3;
	uint8_t buf[] =
	{ 0, 0, 0x80, 0, 0, 0, 0 };
	uint8_t buf_in[] =
	{ 0, 0, 0, 0, 0, 0, 0 };
	HAL_StatusTypeDef ret;
	buf[0] = (uint8_t) (addr >> 8);
	buf[1] = (uint8_t) (addr);
	HAL_GPIO_WritePin(ADE_CS_GPIO_Port, ADE_CS_Pin, GPIO_PIN_RESET);
	ret = HAL_SPI_TransmitReceive(&hspi1, buf, buf_in, len, 100);
	HAL_GPIO_WritePin(ADE_CS_GPIO_Port, ADE_CS_Pin, GPIO_PIN_SET);
	(*data) = 0;
	for (uint_fast8_t i = 3; i < len; i++)
	{
		(*data) <<= 8;
		(*data) += buf_in[i];
	}
	return ret;
}

HAL_StatusTypeDef adeInit()
{
	HAL_GPIO_WritePin(ADE_RESET_GPIO_Port, ADE_RESET_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ADE_CS_GPIO_Port, ADE_CS_Pin, GPIO_PIN_SET);
	vTaskDelay(1);
	HAL_GPIO_WritePin(ADE_RESET_GPIO_Port, ADE_RESET_Pin, GPIO_PIN_SET);
	vTaskDelay(100);
	adeWrite(0xFE, 0xAD, 1);
	vTaskDelay(1);
	adeWrite(0x120, 0x30, 2);
	return HAL_OK;
}

void vAdeTask(void *pvParameters)
{

//	uint8_t i = 0, j = 0, k = 0;
	char temp[30];
	uint32_t data;
	const uint16_t addr[] =
	{ 0x000, 0x001, 0x004, 0x007, 0x008, 0x009, 0x040, 0x0FD, 0x0FF, 0x702, 0x800,
			0x100, 0x101, 0x102, 0x103, 0x104, 0x107, 0x108, 0x109, 0x10A, 0x10B,
			0x10C, 0x10D, 0x10E, 0x110, 0x1FE, 0x1FF, 0x120 };
	adeInit();
	for (int i = 0; i < 28; i++)
	{
		adeRead(addr[i], &data, 2);
		snprintf(temp, 30, "0x%08lX 0x%08lX\r\n", addr[i], data);
		debug_print(temp);
	}
	for (;;)
	{
		//		i++;
		//		j += 2;
		//		k += 3;
		vTaskDelay(1000);
	}

	vTaskDelete(NULL);
}
