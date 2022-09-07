#include "GTM_control_PWM.h"

// PWM 제어
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

    // CCU60 T12 configurations (DISR이 바뀌면 DISS가 따라서 바뀜(데이터 시트 참고), 그거 바뀌는거까지 확인하면서 기다림)
    while((GTM_CLC.U & (1 << DISS_BIT_LSB_IDX)) != 0); // wait until CCU60 module enabled.

    GTM_CMU_FXCLK_CTRL.B.FXCLK_SEL = 0; // 클락을 분주하지 않고 최대 스피드로 설정
    GTM_CMU_CLK_EN.B.EN_FXCLK = 0x2;    //

#if 0   // Red LED로 PWM신호를 출력
    // Time Output Module 0의 1번 채널로 출력
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL1 = 0x2;  // TOM channel 1 update enable
                                                // Period Match가 발생하면 SR0, SR1값을 CM0, CM1에 복사
    // 채널 1번에서 나가는 신호를 스스로 트리거 삼아 뭔가를 작동할수 있도록 세팅
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL1 = 0x2;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL1 = 0x2;   // 채널 1번으로 update trigger 출력

    GTM_TOM0_CH1_CTRL.B.SL = 0x1;           // 언제를 1로 할지 설정. (카운트 올라갈때 1이다가 넘으면 0)
    GTM_TOM0_CH1_CTRL.B.CLK_SRC_SR = 0x1;   // 클락 분주 -> 현재 100MHz/16 = 6250kHz
    GTM_TOM0_CH1_CTRL.B.OSM = 0;            // continuous mode enable
    GTM_TOM0_CH1_CTRL.B.TRIGOUT = 0;        // PWM 1주기 도달 시 Trigger가 발생하는데 이걸 다음 Trigger신호로 이용하기 위함.

    GTM_TOM0_CH1_SR0.U = 12500 - 1;         // 현재 6250kHz로 세팅해놨으니 Cnt는 1ms에 6250-1이 됨. 2ms에는 12500 - 1이 되니까 2ms로 두기 위한 설정임.
    GTM_TOM0_CH1_SR1.U = 1250 - 1;          // 이렇게 하면 0.2ms가 되는거고 듀티는 10%가 됨.

    // 우리가 사용해야할 건 LED인데 P10.1이고 이걸 GTM 출력으로 쓰려면,
    // TOUT103을 봐야함. TOUT103 은 TOUTSEL6번의 7번째에 있음.
    // 이 공간에 2비트가 있는데 각각 A,B,C,D를 맡음.
    // A를 선택 시 TOM0_1를 사용하게 됨.
    GTM_TOUTSEL6.B.SEL7 = 0;
#endif

    // RGB LED에 대한 설정, GTM TOM0 channel 2, 3, 15
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
    GTM_TOM0_CH2_CTRL.B.SL = 0x1;           // 언제를 1로 할지 설정. (카운트 올라갈때 1이다가 넘으면 0)
    GTM_TOM0_CH2_CTRL.B.CLK_SRC_SR = 0x1;   // 클락 분주 -> 현재 100MHz/16 = 6250kHz
    //GTM_TOM0_CH2_CTRL.B.OSM = 0;            // continuous mode enable
    //GTM_TOM0_CH2_CTRL.B.TRIGOUT = 0;        // PWM 1주기 도달 시 Trigger가 발생하는데 이걸 다음 Trigger신호로 이용하기 위함.

    GTM_TOM0_CH3_CTRL.B.SL = 0x1;           // 언제를 1로 할지 설정. (카운트 올라갈때 1이다가 넘으면 0)
    GTM_TOM0_CH3_CTRL.B.CLK_SRC_SR = 0x1;   // 클락 분주 -> 현재 100MHz/16 = 6250kHz
    //GTM_TOM0_CH3_CTRL.B.OSM = 0;            // continuous mode enable
    //GTM_TOM0_CH3_CTRL.B.TRIGOUT = 0;        // PWM 1주기 도달 시 Trigger가 발생하는데 이걸 다음 Trigger신호로 이용하기 위함.

    GTM_TOM0_CH15_CTRL.B.SL = 0x1;           // 언제를 1로 할지 설정. (카운트 올라갈때 1이다가 넘으면 0)
    GTM_TOM0_CH15_CTRL.B.CLK_SRC_SR = 0x1;   // 클락 분주 -> 현재 100MHz/16 = 6250kHz
    //GTM_TOM0_CH15_CTRL.B.OSM = 0;            // continuous mode enable
    //GTM_TOM0_CH15_CTRL.B.TRIGOUT = 0;        // PWM 1주기 도달 시 Trigger가 발생하는데 이걸 다음 Trigger신호로 이용하기 위함.

    GTM_TOM0_CH2_SR0.U = 12500 - 1;         // 현재 6250kHz로 세팅해놨으니 Cnt는 1ms에 6250-1이 됨. 2ms에는 12500 - 1이 되니까 2ms로 두기 위한 설정임.
    GTM_TOM0_CH3_SR0.U = 12500 - 1;         // 현재 6250kHz로 세팅해놨으니 Cnt는 1ms에 6250-1이 됨. 2ms에는 12500 - 1이 되니까 2ms로 두기 위한 설정임.
    GTM_TOM0_CH15_SR0.U = 12500 - 1;         // 현재 6250kHz로 세팅해놨으니 Cnt는 1ms에 6250-1이 됨. 2ms에는 12500 - 1이 되니까 2ms로 두기 위한 설정임.

    GTM_TOUTSEL0.B.SEL7 = 0;
    GTM_TOUTSEL6.B.SEL11 = 0;
    GTM_TOUTSEL6.B.SEL9 = 0;

}



