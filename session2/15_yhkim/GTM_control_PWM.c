#include "GTM_control_PWM.h"

// PWM ����
void initGTM(void)
{
    //Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while ((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0 );

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) & ~(1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);    // wait until locked

    GTM_CLC.U &= ~(1 << DISR_BIT_LSB_IDX);    // enable VADC

    //Password Access to unlock SCU_WDTSCON0
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) & ~(1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while ((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) != 0 );

    // Modify Access to clear ENDINIT
    SCU_WDTCPU0_CON0.U = ((SCU_WDTCPU0_CON0.U ^ 0xFC) | (1 << LCK_BIT_LSB_IDX)) | (1 << ENDINIT_BIT_LSB_IDX);
    while((SCU_WDTCPU0_CON0.U & (1 << LCK_BIT_LSB_IDX)) == 0);    // wait until locked

    // CCU60 T12 configurations (DISR�� �ٲ�� DISS�� ���� �ٲ�(������ ��Ʈ ����), �װ� �ٲ�°ű��� Ȯ���ϸ鼭 ��ٸ�)
    while((GTM_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled.

    GTM_CMU_FXCLK_CTRL.B.FXCLK_SEL = 0; // Ŭ���� �������� �ʰ� �ִ� ���ǵ�� ����
    GTM_CMU_CLK_EN.B.EN_FXCLK = 0x2;    //

#if 0   // Red LED�� PWM��ȣ�� ���
    // Time Output Module 0�� 1�� ä�η� ���
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL1 = 0x2;  // TOM channel 1 update enable
                                                // Period Match�� �߻��ϸ� SR0, SR1���� CM0, CM1�� ����
    // ä�� 1������ ������ ��ȣ�� ������ Ʈ���� ��� ������ �۵��Ҽ� �ֵ��� ����
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL1 = 0x2;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL1 = 0x2;   // ä�� 1������ update trigger ���

    GTM_TOM0_CH1_CTRL.B.SL = 0x1;           // ������ 1�� ���� ����. (ī��Ʈ �ö󰥶� 1�̴ٰ� ������ 0)
    GTM_TOM0_CH1_CTRL.B.CLK_SRC_SR = 0x1;   // Ŭ�� ���� -> ���� 100MHz/16 = 6250kHz
    GTM_TOM0_CH1_CTRL.B.OSM = 0;            // continuous mode enable
    GTM_TOM0_CH1_CTRL.B.TRIGOUT = 0;        // PWM 1�ֱ� ���� �� Trigger�� �߻��ϴµ� �̰� ���� Trigger��ȣ�� �̿��ϱ� ����.

    GTM_TOM0_CH1_SR0.U = 12500 - 1;         // ���� 6250kHz�� �����س����� Cnt�� 1ms�� 6250-1�� ��. 2ms���� 12500 - 1�� �Ǵϱ� 2ms�� �α� ���� ������.
    GTM_TOM0_CH1_SR1.U = 1250 - 1;          // �̷��� �ϸ� 0.2ms�� �Ǵ°Ű� ��Ƽ�� 10%�� ��.

    // �츮�� ����ؾ��� �� LED�ε� P10.1�̰� �̰� GTM ������� ������,
    // TOUT103�� ������. TOUT103 �� TOUTSEL6���� 7��°�� ����.
    // �� ������ 2��Ʈ�� �ִµ� ���� A,B,C,D�� ����.
    // A�� ���� �� TOM0_1�� ����ϰ� ��.
    GTM_TOUTSEL6.B.SEL7 = 0;
#endif

    // RGB LED�� ���� ����, GTM TOM0 channel 2, 3, 15
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL2 = 0x2;  // TOM0 channel 2 enable
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL3 = 0x2;  // TOM0 channel 3 enable
    GTM_TOM0_TGC1_GLB_CTRL.B.UPEN_CTRL7 = 0x2;  // TOM0 channel 15 enable

    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL2 = 0x2;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL3 = 0x2;
    GTM_TOM0_TGC1_ENDIS_CTRL.B.ENDIS_CTRL7 = 0x2;

    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL2 = 0x2;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL3 = 0x2;
    GTM_TOM0_TGC1_OUTEN_CTRL.B.OUTEN_CTRL7 = 0x2;

    // TOM 0_2
    GTM_TOM0_CH2_CTRL.B.SL = 0x1;           // ������ 1�� ���� ����. (ī��Ʈ �ö󰥶� 1�̴ٰ� ������ 0)
    GTM_TOM0_CH2_CTRL.B.CLK_SRC_SR = 0x1;   // Ŭ�� ���� -> ���� 100MHz/16 = 6250kHz
    //GTM_TOM0_CH2_CTRL.B.OSM = 0;            // continuous mode enable
    //GTM_TOM0_CH2_CTRL.B.TRIGOUT = 0;        // PWM 1�ֱ� ���� �� Trigger�� �߻��ϴµ� �̰� ���� Trigger��ȣ�� �̿��ϱ� ����.

    GTM_TOM0_CH3_CTRL.B.SL = 0x1;           // ������ 1�� ���� ����. (ī��Ʈ �ö󰥶� 1�̴ٰ� ������ 0)
    GTM_TOM0_CH3_CTRL.B.CLK_SRC_SR = 0x1;   // Ŭ�� ���� -> ���� 100MHz/16 = 6250kHz
    //GTM_TOM0_CH3_CTRL.B.OSM = 0;            // continuous mode enable
    //GTM_TOM0_CH3_CTRL.B.TRIGOUT = 0;        // PWM 1�ֱ� ���� �� Trigger�� �߻��ϴµ� �̰� ���� Trigger��ȣ�� �̿��ϱ� ����.

    GTM_TOM0_CH15_CTRL.B.SL = 0x1;           // ������ 1�� ���� ����. (ī��Ʈ �ö󰥶� 1�̴ٰ� ������ 0)
    GTM_TOM0_CH15_CTRL.B.CLK_SRC_SR = 0x1;   // Ŭ�� ���� -> ���� 100MHz/16 = 6250kHz
    //GTM_TOM0_CH15_CTRL.B.OSM = 0;            // continuous mode enable
    //GTM_TOM0_CH15_CTRL.B.TRIGOUT = 0;        // PWM 1�ֱ� ���� �� Trigger�� �߻��ϴµ� �̰� ���� Trigger��ȣ�� �̿��ϱ� ����.

    GTM_TOM0_CH2_SR0.U = 12500 - 1;         // ���� 6250kHz�� �����س����� Cnt�� 1ms�� 6250-1�� ��. 2ms���� 12500 - 1�� �Ǵϱ� 2ms�� �α� ���� ������.
    GTM_TOM0_CH3_SR0.U = 12500 - 1;         // ���� 6250kHz�� �����س����� Cnt�� 1ms�� 6250-1�� ��. 2ms���� 12500 - 1�� �Ǵϱ� 2ms�� �α� ���� ������.
    GTM_TOM0_CH15_SR0.U = 12500 - 1;         // ���� 6250kHz�� �����س����� Cnt�� 1ms�� 6250-1�� ��. 2ms���� 12500 - 1�� �Ǵϱ� 2ms�� �α� ���� ������.

    GTM_TOUTSEL0.B.SEL7 = 0;
    GTM_TOUTSEL6.B.SEL11 = 0;
    GTM_TOUTSEL6.B.SEL9 = 0;

}



