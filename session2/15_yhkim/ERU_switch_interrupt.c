#include "ERU_switch_interrupt.h"


// 스위치3번에 대한 입력 인터럽트
void initERU(void)
{
    // ERU setting
    //SCU_EICR1.U &= ~(0X7 << EXIS0_BIT_LSB_IDX);
    //SCU_EICR1.U |= (0X1 << EXIS0_BIT_LSB_IDX);
    SCU_EICR1.B.EXIS0 = 0x1;

    //SCU_EICR1.U |= 0X1 << FEN0_BIT_LSB_IDX;
    //SCU_EICR1.U |= 0X1 << EIEN0_BIT_LSB_IDX;
    SCU_EICR1.B.FEN0 = 1;
    SCU_EICR1.B.EIEN0 = 1;

    //SCU_EICR1.U &= ~(0X7 << INP0_BIT_LSB_IDX);
    SCU_EICR1.B.INP0 = 0x0;

    //SCU_IGCR0.U &= ~(0x3 << IGP0_BIT_LSB_IDX);
    //SCU_IGCR0.U |= 0x1 << IGP0_BIT_LSB_IDX;
    SCU_IGCR0.B.IGP0 = 0x1;

    //SRC_SCU_SCU_ERU0.U &= ~(0XFF << SRPN_BIT_LSB_IDX);
    //SRC_SCU_SCU_ERU0.U |= 0X0A << SRPN_BIT_LSB_IDX;
    SRC_SCU_SCU_ERU0.B.SRPN = 0x0A;

    //SRC_SCU_SCU_ERU0.U &= ~(0x3 << TOS_BIT_LSB_IDX);
    SRC_SCU_SCU_ERU0.B.TOS = 0x0;

    // SRC_SCU_SCU_ERU0.U |= 1 << SRE_BIT_LSB_IDX;
    SRC_SCU_SCU_ERU0.B.SRE = 1;
}


// 스위치 인터럽트
__interrupt(0x0A) __vector_table(0)
void ERU0_ISR(void)
{
    P10_OUT.B.P1 ^= 0x1;
    //P10_OUT.U ^= 0x1 << P1_BIT_LSB_IDX;
}
