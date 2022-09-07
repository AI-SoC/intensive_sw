#include "CCU_Timer.h"


// Ÿ�̸� ���ͷ�Ʈ��
void initCCU60(void)
{
    //Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while ((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0 );

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);    // wait until locked

    CCU60_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);    // enable CCY

    //Password Access to unlock SCU_WDTCON0
    //Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while ((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0 );

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);    // wait until locked

    // CCU60 T12 configurations (DISR�� �ٲ�� DISS�� ���� �ٲ�(������ ��Ʈ ����), �װ� �ٲ�°ű��� Ȯ���ϸ鼭 ��ٸ�)
    while((CCU60_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled.

    CCU60_TCTR0.U &= ~(0x7 << T12CLK_BIT_LSB_IDX);  // f_T12 = f_CCU6 / prescaler
    CCU60_TCTR0.U |= 0x2 << T12CLK_BIT_LSB_IDX;     // f_CCU6 = 50MHz, prescaler = 1024
    CCU60_TCTR0.U |= 0x1 << T12PRE_BIT_LSB_IDX;     // f_T12 = 48,828 Hz

    CCU60_TCTR0.U &= ~(0x1 << CTM_BIT_LSB_IDX);     // T12 auto reset when period match (PM) occur

    CCU60_T12PR.U = 24413;      // PM interrupt freq. = f_T12 / (T12PR + 1)
                                // ���ļ��� 48,848Hz�ϱ� 1�ʿ� 0 ~ 48,847 �� ��. -> 0.5�ʿ��� 0 ~ 24,413�̴ϱ� 0.5�� ���� Ÿ�̸� �����Ҷ��� �̷���!
    CCU60_TCTR4.U |= 0x1 << T12STR_BIT_LSB_IDX;

    CCU60_T12.U = 0;    // clear T12 counter register

    // CCU60 T12 PM interrupt setting
    CCU60_INP.U &= ~(0x3 << INPT12_BIT_LSB_IDX);
    CCU60_IEN.U |= 0x1 << ENT12PM_BIT_LSB_IDX;

    // SRC setting for CCU60
    SRC_CCU6_CCU60_SR0.U &= ~(0xFF << SRPN_BIT_LSB_IDX);
    SRC_CCU6_CCU60_SR0.U |= 0x0B << SRPN_BIT_LSB_IDX;   //set priority 0x0B

    SRC_CCU6_CCU60_SR0.U &= ~(0x3 << TOS_BIT_LSB_IDX);  // CPU0 service T12 PM interrupt

    SRC_CCU6_CCU60_SR0.U |= 0x1 << SRE_BIT_LSB_IDX;     // SR0 enabled

    // CCU60 T12 counting start
    CCU60_TCTR4.U = 0x1 << T12RS_BIT_LSB_IDX;   // T12 start counting


}


// Ÿ�̸� ���ͷ�Ʈ
__interrupt(0x0B) __vector_table(0)
void CCU60_T12_ISR(void)
{
    //P10_OUT.B.P1 ^= 0x1;
}
