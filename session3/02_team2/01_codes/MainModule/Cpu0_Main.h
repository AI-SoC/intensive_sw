/*
 * Cpu0_Main.h
 *
 *  Created on: 2022. 9. 14.
 *      Author: user
 */

#ifndef CPU0_MAIN_H_
#define CPU0_MAIN_H_

#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxCcu6_reg.h"
#include "IfxVadc_reg.h"
#include "IfxGtm_reg.h"

#include "Unlock.h"
#include "Traffic_Light.h"
#include "Pedal.h"
#include "Steer_Wheel.h"
#include "Ultrasonic.h"

// Port registers
#define PC0_BIT_LSB_IDX             3
#define PC1_BIT_LSB_IDX             11
#define PC2_BIT_LSB_IDX             19
#define PC3_BIT_LSB_IDX             27
#define PC4_BIT_LSB_IDX             3
#define PC5_BIT_LSB_IDX             11
#define PC6_BIT_LSB_IDX             19
#define PC7_BIT_LSB_IDX             27
#define PC10_BIT_LSB_IDX            19
#define P0_BIT_LSB_IDX              0
#define P1_BIT_LSB_IDX              1
#define P2_BIT_LSB_IDX              2
#define P3_BIT_LSB_IDX              3
#define P4_BIT_LSB_IDX              4
#define P5_BIT_LSB_IDX              5
#define P6_BIT_LSB_IDX              6
#define P7_BIT_LSB_IDX              7
#define P10_BIT_LSB_IDX             10

// SCU registers
#define LCK_BIT_LSB_IDX             1
#define ENDINIT_BIT_LSB_IDX         0
#define EXIS0_BIT_LSB_IDX           4
#define EXIS1_BIT_LSB_IDX           20
#define FEN0_BIT_LSB_IDX            8
#define FEN1_BIT_LSB_IDX            24
#define REN0_BIT_LSB_IDX            9
#define REN1_BIT_LSB_IDX            25
#define EIEN0_BIT_LSB_IDX           11
#define EIEN1_BIT_LSB_IDX           27
#define INP0_BIT_LSB_IDX            12
#define INP1_BIT_LSB_IDX            28
#define IGP0_BIT_LSB_IDX            14
#define IGP1_BIT_LSB_IDX            30

// SRC registers
#define SRPN_BIT_LSB_IDX            0
#define TOS_BIT_LSB_IDX             11
#define SRE_BIT_LSB_IDX             10

// CCU60 registers
#define DISS_BIT_LSB_IDX            1
#define DISR_BIT_LSB_IDX            0
#define CTM_BIT_LSB_IDX             7
#define T12PRE_BIT_LSB_IDX          3
#define T12CLK_BIT_LSB_IDX          0
#define T12STR_BIT_LSB_IDX          6
#define T12RS_BIT_LSB_IDX           1
#define INPT12_BIT_LSB_IDX          10
#define ENT12PM_BIT_LSB_IDX         7

// VADC registers
#define DISS_BIT_LSB_IDX            1
#define DISR_BIT_LSB_IDX            0
#define ANONC_BIT_LSB_IDX           0
#define ASEN0_BIT_LSB_IDX           24
#define CSM0_BIT_LSB_IDX            3
#define PRIO0_BIT_LSB_IDX           0
#define CMS_BIT_LSB_IDX             8
#define FLUSH_BIT_LSB_IDX           10
#define TREV_BIT_LSB_IDX            9
#define ENGT_BIT_LSB_IDX            0
#define RESPOS_BIT_LSB_IDX          21
#define RESREG_BIT_LSB_IDX          16
#define ICLSEL_BIT_LSB_IDX          0
#define VF_BIT_LSB_IDX              31
#define RESULT_BIT_LSB_IDX          0
#define ASSCH7_BIT_LSB_IDX          7

// GTM registers
#define DISS_BIT_LSB_IDX            1
#define DISR_BIT_LSB_IDX            0
#define SEL7_BIT_LSB_IDX            14
#define SEL8_BIT_LSB_IDX            16
#define SEL9_BIT_LSB_IDX            18
#define SEL11_BIT_LSB_IDX           22
#define EN_FXCLK_BIT_LSB_IDX        22
#define FXCLK_SEL_BIT_LSB_IDX       0

// GTM - TOM0 registers
#define UPEN_CTRL1_BIT_LSB_IDX      18
#define UPEN_CTRL2_BIT_LSB_IDX      20
#define HOST_TRIG_BIT_LSB_IDX       0
#define ENDIS_CTRL1_BIT_LSB_IDX     2
#define ENDIS_CTRL2_BIT_LSB_IDX     4
#define OUTEN_CTRL1_BIT_LSB_IDX     2
#define OUTEN_CTRL2_BIT_LSB_IDX     4
#define RSCNT0_CN1_BIT_LSB_IDX      18
#define FUPD_CTRL1_BIT_LSB_IDX      2
#define CLK_SRC_SR_BIT_LSB_IDX      12
#define SL_BIT_LSB_IDX              11
#define OSM_BIT_LSB_IDX             26
#define TRIOUT_BIT_LSB_IDX          24

#endif /* CPU0_MAIN_H_ */
