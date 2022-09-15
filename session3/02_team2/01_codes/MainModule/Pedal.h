/*
 * Pedal.h
 *
 *  Created on: 2022. 9. 14.
 *      Author: user
 */

#ifndef PEDAL_H_
#define PEDAL_H_

#include "Cpu0_Main.h"

void initButton(void);
void initERUD2(void);
void initERUD3(void);
void initGTM(void);
void initBuzzer(void);
void initConnect(void);
void ERU_ISR_D2(void);
void ERU_ISR_D3(void);


#endif /* PEDAL_H_ */
