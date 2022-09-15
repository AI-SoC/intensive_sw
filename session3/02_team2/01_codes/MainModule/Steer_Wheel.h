/*
 * Steer_Wheel.h
 *
 *  Created on: 2022. 9. 14.
 *      Author: user
 */

#ifndef STEER_WHEEL_H_
#define STEER_WHEEL_H_

#include "Cpu0_Main.h"

void VADC_startConversion(void);
unsigned int VADC_readResult(void);
void initPWM_LED(void);
void initVADC(void);



#endif /* STEER_WHEEL_H_ */
