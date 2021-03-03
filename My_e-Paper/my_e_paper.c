/*
 * my_e_paper.c
 *
 *  Created on: 3 mar. 2021
 *      Author: tomaso
 */

#include "EPD_1in02d.h"
#include "cruz.h"
#include "logo.h"
#include "tilde.h"

#define 	EPD_WIDTH 		EPD_1IN02_WIDTH
#define 	EPD_HEIGHT 		EPD_1IN02_HEIGHT
#define 	IMAGE_SIZE		1280

UBYTE old_Image[IMAGE_SIZE];

uint8_t EPD_Init(void)
{
    if(DEV_Module_Init()!=0){
        return -1;
    }

	EPD_1IN02_Init();
	EPD_1IN02_Clear();
//	DEV_Delay_ms(500);

//	EPD_1IN02_Display(logo);
//	DEV_Delay_ms(2000);

//	EPD_1IN02_Part_Init();
//
//	memcpy(old_Image, logo, IMAGE_SIZE);
//	EPD_1IN02_DisplayPartial(old_Image, BlackImage);
//	memcpy(old_Image, BlackImage, IMAGE_SIZE);
	return 0;
}


void EPD_dibujar_imagen(uint8_t numero_imagen)
{
  switch(numero_imagen)
  {
	default:
	case 0:
		EPD_1IN02_Display(logo);
	  break;
	case 1:
		EPD_1IN02_Display(cruz);
	  break;
	case 2:
		EPD_1IN02_Display(tilde);
	  break;
	case 3:
		EPD_1IN02_Display(logo);
	  break;
  }
}
