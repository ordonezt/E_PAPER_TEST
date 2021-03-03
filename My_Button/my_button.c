/*
 * my_button.c
 *
 *  Created on: 3 mar. 2021
 *      Author: tomaso
 */

#include "main.h"

#define CANTIDAD_REPETICIONES	4

uint8_t boton_estado, boton_flanco;

void debounce_btn(void)
{
	static uint32_t tick_anterior = 0, repeticiones = CANTIDAD_REPETICIONES;
	static GPIO_PinState estado_anterior = 0;
	GPIO_PinState estado_actual;

	if(HAL_GetTick() - tick_anterior > 10)
	{
		tick_anterior = HAL_GetTick();

		estado_actual = HAL_GPIO_ReadPin(BOTON_PIN);

		if (estado_actual == estado_anterior)
		{
			if (repeticiones > 0)
			{
				repeticiones--;
				if (repeticiones == 0)
				{
					boton_estado = estado_actual;
					boton_flanco = 1;
				}
			}
		}
		else
			repeticiones = CANTIDAD_REPETICIONES;

		estado_anterior = estado_actual;
	}
}
