/*
 * Ultrasonic.h
 *
 *  Created on: 2022. 9. 15.
 *      Author: user
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "Cpu0_Main.h"
#include "Unlock.h"

void initERURight();
void initERULeft();
void initCCU60();
void initCCU61();
void initUsonic();

void usonicTriggerRight();
void usonicTriggerLeft();


#endif /* ULTRASONIC_H_ */
