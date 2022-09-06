#include "stm32f042f6p6.h"
#include "main.h"

static void init(void);

static void Default_Handler(void);

/* Linker script declarations. */
extern unsigned char INIT_DATA_VALUES;
extern unsigned char INIT_DATA_START;
extern unsigned char INIT_DATA_END;
extern unsigned char BSS_START;
extern unsigned char BSS_END;
extern unsigned char _stack_top;

/* Vectors installed at beginning of flash by the linker script. */
const void *isr[] __attribute__((section(".vectors"))) = {
        &_stack_top,        /* Top of stack. */
        init,               /* 0x0000 0004: Reset Handler */
        Default_Handler,    /* 0x0000 0008: NMI (RCC clock security, RAM parity check) */
        Default_Handler,    /* 0x0000 000c: HardFault (all classes of fault) */
        Default_Handler,
        Default_Handler,
        Default_Handler,
        Default_Handler,
        Default_Handler,
        Default_Handler,
        Default_Handler,
        Default_Handler,    /* 0x0000 002c: System service call via SWI */
        Default_Handler,
        Default_Handler,
        Default_Handler,    /* 0x0000 0038: Pendable request for system service */
        Default_Handler,    /* 0x0000 003c: SysTick */

        /* External interrupt handlers start at 0x0000 0040. */
        Default_Handler,    /* 0: WWDG */
        Default_Handler,    /* 1: PVD and VDDIO2 supply comparator interrupt */
        Default_Handler,    /* 2: RTC */
        Default_Handler,    /* 3: FLASH */
        Default_Handler,    /* 4: RCC_CRS */
        Default_Handler,    /* 5: EXTI0_1 */
        Default_Handler,    /* 6: EXTI2_3 */
        Default_Handler,    /* 7: EXTI4_15 */
        Default_Handler,    /* 8: TSC */
        Default_Handler,    /* 9: DMA_CH1 */
        Default_Handler,    /* 10: DMA_CH2_3, DMA2_CH1_2 */
        Default_Handler,    /* 11: DMA_CH4_5_6_7, DMA2_CH3_4_5 */
        Default_Handler,    /* 12: ADC_COMP */
        Default_Handler,    /* 13: TIM1_BRK_UP_TRG_COM */
        Default_Handler,    /* 14: TIM1_CC */
        Default_Handler,    /* 15: TIM2 */
        Default_Handler,    /* 16: TIM3 */
        Default_Handler,    /* 17: TIM6_DAC*/
        Default_Handler,    /* 18: TIM7 */
        Default_Handler,    /* 19: TIM14 */
        Default_Handler,    /* 20: TIM15 */
        Default_Handler,    /* 21: TIM16 */
        Default_Handler,    /* 22: TIM17 */
        Default_Handler,    /* 23: I2C1 */
        Default_Handler,    /* 24: I2C2 */
        Default_Handler,    /* 25: SPI1 */
        Default_Handler,    /* 26: SPI2 */
        Default_Handler,    /* 27: USART1 */
        Default_Handler,    /* 28: USART2 */
        Default_Handler,    /* 29: USART3_4_5_6_7_8 */
        Default_Handler,    /* 30: CEC_CAN */
        Default_Handler     /* 31: USB */
};

void init() {
    unsigned char *src;
    unsigned char *dest;
    unsigned len;

    // Global / static initialization.
    src = &INIT_DATA_VALUES;
    dest = &INIT_DATA_START;
    len = &INIT_DATA_END - &INIT_DATA_START;
    while (len--)
        *dest++ = *src++;

    // Zero out BSS.
    dest = &BSS_START;
    len = &BSS_END - &BSS_START;
    while (len--)
        *dest++ = 0;

    main();
}

void Default_Handler() {
    while (1);
}
