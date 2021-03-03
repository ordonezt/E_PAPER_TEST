/*
 * my_led.c
 *
 *  Created on: 3 mar. 2021
 *      Author: tomaso
 */

#include "main.h"

void toggle_led(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	static uint32_t tick_anterior = 0;

	if(HAL_GetTick() - tick_anterior > 300)
	{
		tick_anterior = HAL_GetTick();

		HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	}
}
