/*
 * GPIO_Button.c
 *
 *  Created on: 2022. 9. 7.
 *      Author: user
 */
#include "GPIO_Button.h"


void init_Button(void)
{
    P02_IOCR0.B.PC0 = 0x02;
    P02_IOCR0.B.PC1 = 0x02;
}


