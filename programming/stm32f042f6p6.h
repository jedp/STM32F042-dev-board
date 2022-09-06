#ifndef SRC_MAIN_STM32F042F6P6_H
#define SRC_MAIN_STM32F042F6P6_H

/*
 * STM32F042F6P6
 *
 * IC MCU 32BIT 32KB FLASH 20TSSOP
 *
 * TSSOP20 Pinout, with alternate and additional functions.
 *
 *   1 PB8, BOOT0
 *   2 PF0, OSC_IN, CRS_SYNC, I2C1_SDA
 *   3 PF1, OSC_OUT, I2C1_SCL
 *   4 NRST
 *   5 VDDA
 *   6 PA0, USART2_CTS, TIM2_CH1_ETR, TSC_G1_IO1, RTC_TAMP2, WKUP1, ADC_IN0
 *   7 PA1, USART2_RTS, TIM2_CH2, TSC_G1_IO2, EVENTOUT, ADC_IN1
 *   8 PA2, USART2_TX, TIM2_CH3, TSC_G1_IO3, ADC_IN2, WKUP4
 *   9 PA3, USART2_RX, TIM2_CH4, TSC_G1_IO4, ADC_IN3
 *  10 PA4, SPI1_NSS, I2S1_WS, TIM14_CH1, TSC_G2_IO1, USART2_CK USB_NOE, ADC_IN4
 *  11 PA5, SPI1_SCK, I2S1_CK, CEC, TIM2_CH1_ETR, TSC_G2_IO2, ADC_IN5
 *  12 PA6, SPI1_MISO, I2S1_MCK, TIM3_CH1, TIM1_BKIN, TIM16_CH1, TSC_G2_IO3, EVENTOUT, ADC_IN6
 *  13 PA7, SPI1_MOSI, I2S1_SD, TIM3_CH2, TIM14_CH1, TIM1_CH1N, TIM17_CH1, TSC_G2_IO4, EVENTOUT, ADC_IN7
 *  14 PB1, TIM3_CH4, TIM14_CH1, TIM1_CH3N, TSC_G3_IO3, ADC_IN9
 *  15 VSS
 *  16 VDD
 *  17 PA9, USART1_TX, TIM1_CH2, TSC_G4_IO1, I2C1_SCL
 *     PA11, CAN_RX, USART1_CTS, TIM1_CH4, TSC_G4_IO3, EVENTOUT, I2C1_SCL, USB_DM
 *  18 PA10, USART1_RX, TIM1_CH3, TIM17_BKIN, TSC_G4_IO2, I2C1_SDA
 *     PA12, CAN_TX,USART1_RTS, TIM1_ETR, TSC_G4_IO4, EVENTOUT, I2C1_SDA, USB_DP
 *  19 PA13, IR_OUT, SWDIO USB_NOE
 *  20 PA14, USART2_TX, SWCLK
 */

#define BIT_0           (1 <<  0)
#define BIT_1           (1 <<  1)
#define BIT_2           (1 <<  2)
#define BIT_3           (1 <<  3)
#define BIT_4           (1 <<  4)
#define BIT_5           (1 <<  5)
#define BIT_6           (1 <<  6)
#define BIT_7           (1 <<  7)
#define BIT_8           (1 <<  8)
#define BIT_9           (1 <<  9)
#define BIT_10          (1 << 10)
#define BIT_11          (1 << 11)
#define BIT_12          (1 << 12)
#define BIT_13          (1 << 13)
#define BIT_14          (1 << 14)
#define BIT_15          (1 << 15)
#define BIT_16          (1 << 16)
#define BIT_17          (1 << 17)
#define BIT_18          (1 << 18)
#define BIT_19          (1 << 19)
#define BIT_20          (1 << 20)
#define BIT_21          (1 << 21)
#define BIT_22          (1 << 22)
#define BIT_23          (1 << 23)
#define BIT_24          (1 << 24)
#define BIT_25          (1 << 25)
#define BIT_26          (1 << 26)
#define BIT_27          (1 << 27)
#define BIT_28          (1 << 28)
#define BIT_29          (1 << 29)
#define BIT_30          (1 << 30)
#define BIT_31          (1 << 31)

/* Memory map. */

// AHB2
#define GPIOF_BASE      0x48001400
#define GPIOC_BASE      0x48000800
#define GPIOB_BASE      0x48000400
#define GPIOA_BASE      0x48000000

// AHB1
#define TSC_BASE        0x40024000
#define CRC_BASE        0x40023000
#define FLASH_BASE      0x40022000
#define RCC_BASE        0x40021000
#define DMA_BASE        0x40020000

// APB
#define DBGMCU_BASE     0x40015800
#define TIM17_BASE      0x40014800
#define TIM16_BASE      0x40014400
#define USART1_BASE     0x40013800
#define DBGMCU_BASE     0x40015800
#define SPI1_BASE       0x40013000
#define I2S1_BASE       0x40013000
#define TIM1_BASE       0x40012C00
#define ADC_BASE        0x40012400
#define EXTI_BASE       0x40010400
#define SYSCFG_BASE     0x40012000
#define CEC_BASE        0x40007800
#define PWR_BASE        0x40007000
#define CRS_BASE        0x40006C00
#define BXCAN_BASE      0x40006400
#define CAN_RAM_BASE    0x40006000
#define USB_RAM_BASE    0x40006000
#define USB_BASE        0x40005C00
#define I2C1_BASE       0x40005400
#define USART2_BASE     0x40004400
#define SPI2_BASE       0x40003800
#define IWDG_BASE       0x40003000
#define WWDG_BASE       0x40002C00
#define RTC_BASE        0x40002800
#define TIM14_BASE      0x40002000
#define TIM3_BASE       0x40000400
#define TIM2_BASE       0x40000000

/*
 * SRAM base            0x20000000
 * Option bytes base    0x1FFFF800
 * System memory base   0x1FFFC400
 * Flash memory base    0x08000000 up to 0x08008000
 * Flash / sysmem /sram 0x00000000 up to 0x00008000
 */

/* Ports. */

/*
 * For GPIO configuration and power usage considerations, see AN4899, section 8.
 */

#define REG_32(ADDR)    (*((volatile unsigned int *) (ADDR)))
#define REG_16(ADDR)    (*((volatile unsigned int *) (ADDR)))

/*
 * For register configuration, see reference manual RM0091, section 8.4.
 *
 * Summary:
 *
 * Name         Register function            Address
 *
 * MODER        Port IO mode register.       base + 0x00
 *              Reset value: 0x2800 0000 for port A
 *              Reset value: 0x0000 0000 for other ports
 *              Bits 31:0 MODER[15:0][1:0]: pin y (y=15 to 0)
 *                  00: Input mode (reset state)
 *                  01: General purpose output mode
 *                  10: Alternate function mode
 *                  11: Analog mode
 *
 * OTYPER       Port output type.                   0x04
 *              Reset value: 0x0000 0000
 *              Bits 15:0 OT[15:0]: pin y (y=15 to 0)
 *                  0: Output push-pull (reset state)
 *                  1: Output open-drain
 *
 * OSPEEDR      Port output speed.                  0x08
 *              Reset value: 0x0C00 0000 (for port A)
 *              Reset value: 0x0000 0000 (for other ports)
 *              Bits31:0 OSPEEDR[15:0][1:0]: pin y (y=15 to 0)
 *                  x0: Low speed
 *                  01: Medium speed
 *                  11: High speed
 *
 * PUPDR        Port pull-up/pull-down.             0x0C
 *              Reset value: 0x2400 0000 (for port A)
 *              Reset value: 0x0000 0000 (for other ports)
 *              Bits31:0 PUPDR[15:0][1:0]: pin y (y=15 to 0)
 *                  00: No pull-up, pull-down
 *                  01: Pull-up
 *                  10: Pull-down
 *                  11: Reserved
 *
 * IDR          Port input data.                    0x10
 *              Reset value: 0x0000 XXXX
 *              Bits15:0 IDR[15:0]: pin y (y=15 to 0)
 *                  Read-only: The input value of the corresponding I/O port.
 *
 * ODR          Port output data.                   0x14
 *              Reset value: 0x0000 0000
 *              ODR[15:0]: pin y (y=15 to 0)
 *                  These bits can be read and written by software.
 *                  Note: For atomic bit set/reset, the ODR bits can be individually set and/or reset
 *                  by writing to the GPIOx_BSRR register (x = A..F)
 *
 * BSRR         Port bit set/reset.                 0x1A
 *              Reset value: 0x0000 0000
 *              Write-only.
 *              Bits31:16 BR[15:0]: pin y(y=15 to 0)
 *                  0: No action on the corresponding ODRx bit
 *                  1: Resets the corresponding ODRx bit
 *              Bits15:0 BS[15:0]: pin y(y=15 to 0)
 *                  0: No action on the corresponding ODRx bit
 *                  1: Sets the corresponding ODRx bit
 *              Note: If both BSx and BRx are set, BSx has priority.
 *
 * LCKR         Port configuration lock.            0x1C
 *              See Reference Manual for details.
 *
 * AFRL         Alternate function 1.               0x20
 *              Reset value: 0x0000 0000
 *
 *              Bits31:0 AFSELy[3:0]: pin y (y=7 to 0)
 *                  0000: AF0
 *                  0001: AF1
 *                  0010: AF2
 *                  0011: AF3
 *                  0100: AF4
 *                  0101: AF5
 *                  0110: AF6
 *                  0111: AF7
 *
 * AFRH         Alternate function 2.               0x24
 *              Reset value: 0x0000 0000
 *              Bits31:0 AFSELy[3:0]: pin y (y=15 to 8)
 *                  0000: AF0
 *                  0001: AF1
 *                  0010: AF2
 *                  0011: AF3
 *                  0100: AF4
 *                  0101: AF5
 *                  0110: AF6
 *                  0111: AF7
 *
 * BRR          Bit reset.                          0x28
 *              Reset value: 0x0000 0000
 *              Bits15:0 BR[15:0]: pin y (y=15 to 0)
 *              Write-only.
 *                  0: No action on the corresponding ODx bit
 *                  1: Reset the corresponding ODx bit
 */

#define GPIOA_MODER     REG_32(GPIOA_BASE + 0x00)
#define GPIOA_OTYPER    REG_32(GPIOA_BASE + 0x04)
#define GPIOA_OSPEEDR   REG_32(GPIOA_BASE + 0x08)
#define GPIOA_PUPDR     REG_32(GPIOA_BASE + 0x0C)
#define GPIOA_IDR       REG_32(GPIOA_BASE + 0x10)
#define GPIOA_ODR       REG_32(GPIOA_BASE + 0x14)
#define GPIOA_BSRR      REG_32(GPIOA_BASE + 0x18)
#define GPIOA_LCKR      REG_32(GPIOA_BASE + 0x1C)
#define GPIOA_AFRL      REG_32(GPIOA_BASE + 0x20)
#define GPIOA_AFRH      REG_32(GPIOA_BASE + 0x24)
#define GPIOA_BRR       REG_32(GPIOA_BASE + 0x28)

#define GPIOB_MODER     REG_32(GPIOB_BASE + 0x00)
#define GPIOB_OTYPER    REG_32(GPIOB_BASE + 0x04)
#define GPIOB_OSPEEDR   REG_32(GPIOB_BASE + 0x08)
#define GPIOB_PUPDR     REG_32(GPIOB_BASE + 0x0C)
#define GPIOB_IDR       REG_32(GPIOB_BASE + 0x10)
#define GPIOB_ODR       REG_32(GPIOB_BASE + 0x14)
#define GPIOB_BSRR      REG_32(GPIOB_BASE + 0x18)
#define GPIOB_LCKR      REG_32(GPIOB_BASE + 0x1C)
#define GPIOB_AFRL      REG_32(GPIOB_BASE + 0x20)
#define GPIOB_AFRH      REG_32(GPIOB_BASE + 0x24)
#define GPIOB_BRR       REG_32(GPIOB_BASE + 0x28)

#define GPIOF_MODER     REG_32(GPIOB_BASE + 0x00)
#define GPIOF_OTYPER    REG_32(GPIOB_BASE + 0x04)
#define GPIOF_OSPEEDR   REG_32(GPIOB_BASE + 0x08)
#define GPIOF_PUPDR     REG_32(GPIOB_BASE + 0x0C)
#define GPIOF_IDR       REG_32(GPIOB_BASE + 0x10)
#define GPIOF_ODR       REG_32(GPIOB_BASE + 0x14)
#define GPIOF_BSRR      REG_32(GPIOB_BASE + 0x18)
#define GPIOF_LCKR      REG_32(GPIOB_BASE + 0x1C)
#define GPIOF_AFRL      REG_32(GPIOB_BASE + 0x20)
#define GPIOF_AFRH      REG_32(GPIOB_BASE + 0x24)
#define GPIOF_BRR       REG_32(GPIOB_BASE + 0x28)

/* Clock control registers. */

#define RCC_CR          REG_32(RCC_BASE + 0x00)     // Clock control
#define RCC_CFGR        REG_32(RCC_BASE + 0x04)     // Clock configuration
#define RCC_CIR         REG_32(RCC_BASE + 0x08)     // Clock interrupt
#define RCC_APB2RSTR    REG_32(RCC_BASE + 0x0C)     // APB peripheral reset 2
#define RCC_APB1RSTR    REG_32(RCC_BASE + 0x10)     // APB peripheral reset 1
#define RCC_AHBENR      REG_32(RCC_BASE + 0x14)     // AHB peripheral clock enable
#define RCC_APB2ENR     REG_32(RCC_BASE + 0x18)     // APB peripheral clock enable 2
#define RCC_APB1ENR     REG_32(RCC_BASE + 0x1C)     // APB peripheral clock enable 1
#define RCC_BDCR        REG_32(RCC_BASE + 0x20)     // RTC domain control
#define RCC_CSR         REG_32(RCC_BASE + 0x24)     // Control/status
#define RCC_AHBRSTR     REG_32(RCC_BASE + 0x28)     // AHB peripheral reset
#define RCC_CFGR2       REG_32(RCC_BASE + 0x2C)     // Clock configuration 2
#define RCC_CFGR3       REG_32(RCC_BASE + 0x30)     // Clock configuration 3
#define RCC_CR2         REG_32(RCC_BASE + 0x34)     // Clock control register 2

/* Advanced control timer 1. */

#define TIM1_CR1	    REG_16(TIM1_BASE + 0x00)    // Control register 1
#define TIM1_CR2	    REG_16(TIM1_BASE + 0x04)    // Control register 2
#define TIM1_SMCR	    REG_16(TIM1_BASE + 0x08)    // Slave mode control register
#define TIM1_DIER	    REG_16(TIM1_BASE + 0x0c)    // DMA interrupt enable
#define TIM1_SR		    REG_16(TIM1_BASE + 0x10)    // Status register
#define TIM1_EGR	    REG_16(TIM1_BASE + 0x14)    // Event generation
#define TIM1_CCMR1	    REG_16(TIM1_BASE + 0x18)    // Capture/compare mode register 1
#define TIM1_CCMR2	    REG_16(TIM1_BASE + 0x1c)    // Capture/compare mode register 2
#define TIM1_CCER	    REG_16(TIM1_BASE + 0x20)    // Capture/compare enable register
#define TIM1_CNT	    REG_16(TIM1_BASE + 0x24)    // Counter
#define TIM1_PSC	    REG_16(TIM1_BASE + 0x28)    // Prescaler
#define TIM1_ARR	    REG_16(TIM1_BASE + 0x2c)    // Auto-reload register
#define TIM1_RCR	    REG_16(TIM1_BASE + 0x30)    // Repetition count register
#define TIM1_CCR1	    REG_16(TIM1_BASE + 0x34)    // Capture/compare register 1
#define TIM1_CCR2	    REG_16(TIM1_BASE + 0x38)    // Capture/compare register 2
#define TIM1_CCR3	    REG_16(TIM1_BASE + 0x3c)    // Capture/compare register 3
#define TIM1_CCR4	    REG_16(TIM1_BASE + 0x40)    // Capture/compare register 4
#define TIM1_BDTR	    REG_16(TIM1_BASE + 0x44)    // Break and dead-time register
#define TIM1_DCR	    REG_16(TIM1_BASE + 0x48)    // DMA control register
#define TIM1_DMAR	    REG_16(TIM1_BASE + 0x4c)    // DMA address register for full transfer

/* General purpose timers 2 and 3. */

#define TIM2_CR1        REG_16(TIM2_BASE + 0x00)    // Control register 1
#define TIM2_CR2        REG_16(TIM2_BASE + 0x04)    // Control register 2
#define TIM2_SMCR       REG_16(TIM2_BASE + 0x08)    // Slave mode control register
#define TIM2_DIER       REG_16(TIM2_BASE + 0x0c)    // DMA interrupt enable register
#define TIM2_SR         REG_16(TIM2_BASE + 0x10)    // Status register
#define TIM2_EGR        REG_16(TIM2_BASE + 0x14)    // Event generation register
#define TIM2_CCMR1      REG_16(TIM2_BASE + 0x18)    // Capture/compare mode register 1
#define TIM2_CCMR2      REG_16(TIM2_BASE + 0x1c)    // Capture/compare mode register 2
#define TIM2_CCER       REG_16(TIM2_BASE + 0x20)    // Capture/compare enable register
#define TIM2_CNT        REG_16(TIM2_BASE + 0x24)    // Counter
#define TIM2_PSC        REG_16(TIM2_BASE + 0x28)    // Prescaler
#define TIM2_ARR        REG_16(TIM2_BASE + 0x2c)    // Auto-reload register
#define TIM2_CCR1       REG_16(TIM2_BASE + 0x34)    // Capture/compare register 1
#define TIM2_CCR2       REG_16(TIM2_BASE + 0x38)    // Capture/compare register 2
#define TIM2_CCR3       REG_16(TIM2_BASE + 0x3c)    // Capture/compare register 3
#define TIM2_CCR4       REG_16(TIM2_BASE + 0x40)    // Capture/compare register 4
#define TIM2_DCR        REG_16(TIM2_BASE + 0x48)    // DMA control register
#define TIM2_DMAR       REG_16(TIM2_BASE + 0x4c)    // DMA address register for full transfer

#define TIM3_CR1        REG_16(TIM3_BASE + 0x00)    // Control register 1
#define TIM3_CR2        REG_16(TIM3_BASE + 0x04)    // Control register 2
#define TIM3_SMCR       REG_16(TIM3_BASE + 0x08)    // Slave mode control register
#define TIM3_DIER       REG_16(TIM3_BASE + 0x0c)    // DMA interrupt enable register
#define TIM3_SR         REG_16(TIM3_BASE + 0x10)    // Status register
#define TIM3_EGR        REG_16(TIM3_BASE + 0x14)    // Event generation register
#define TIM3_CCMR1      REG_16(TIM3_BASE + 0x18)    // Capture/compare mode register 1
#define TIM3_CCMR2      REG_16(TIM3_BASE + 0x1c)    // Capture/compare mode register 2
#define TIM3_CCER       REG_16(TIM3_BASE + 0x20)    // Capture/compare enable register
#define TIM3_CNT        REG_16(TIM3_BASE + 0x24)    // Counter
#define TIM3_PSC        REG_16(TIM3_BASE + 0x28)    // Prescaler
#define TIM3_ARR        REG_16(TIM3_BASE + 0x2c)    // Auto-reload register
#define TIM3_CCR1       REG_16(TIM3_BASE + 0x34)    // Capture/compare register 1
#define TIM3_CCR2       REG_16(TIM3_BASE + 0x38)    // Capture/compare register 2
#define TIM3_CCR3       REG_16(TIM3_BASE + 0x3c)    // Capture/compare register 3
#define TIM3_CCR4       REG_16(TIM3_BASE + 0x40)    // Capture/compare register 4
#define TIM3_DCR        REG_16(TIM3_BASE + 0x48)    // DMA control register
#define TIM3_DMAR       REG_16(TIM3_BASE + 0x4c)    // DMA address register for full transfer

/* General purpose timer 14. */

#define TIM14_CR1	    REG_16(TIM14_BASE + 0x00)    // Control register 1
#define TIM14_DIER	    REG_16(TIM14_BASE + 0x0c)    // DMA interrupt enable register
#define TIM14_SR		REG_16(TIM14_BASE + 0x10)    // Status register
#define TIM14_EGR	    REG_16(TIM14_BASE + 0x14)    // Event generation
#define TIM14_CCMR1	    REG_16(TIM14_BASE + 0x18)    // Capture/compare mode register 1 [alternate]
#define TIM14_CCER	    REG_16(TIM14_BASE + 0x20)    // Capture/compare enable register
#define TIM14_CNT	    REG_16(TIM14_BASE + 0x24)    // Counter
#define TIM14_PSC	    REG_16(TIM14_BASE + 0x28)    // Prescaler
#define TIM14_ARR	    REG_16(TIM14_BASE + 0x2c)    // Auto-reload register
#define TIM14_CCR1	    REG_16(TIM14_BASE + 0x34)    // Capture/compare register 1
#define TIM14_OR	    REG_16(TIM14_BASE + 0x50)    // Option register

/* General purpose 16 and 17. */

#define TIM16_CR1       REG_16(TIM16_BASE + 0x00)   // Control register 1
#define TIM16_CR2       REG_16(TIM16_BASE + 0x04)   // Control register 2
#define TIM16_DIER      REG_16(TIM16_BASE + 0x0c)   // DMA interrupt enable register
#define TIM16_SR        REG_16(TIM16_BASE + 0x10)   // Status register
#define TIM16_EGR       REG_16(TIM16_BASE + 0x14)   // Event generation register
#define TIM16_CCMR1     REG_16(TIM16_BASE + 0x18)   // Capture/compare mode register 1 [alternate]
#define TIM16_CCER      REG_16(TIM16_BASE + 0x20)   // Capture/compare enable register
#define TIM16_CNT       REG_16(TIM16_BASE + 0x24)   // Counter
#define TIM16_PSC       REG_16(TIM16_BASE + 0x28)   // Prescaler
#define TIM16_ARR	    REG_16(TIM16_BASE + 0x2c)   // Auto-reload register
#define TIM16_RCR       REG_16(TIM16_BASE + 0x30)   // Repetition counter register
#define TIM16_CCR1	    REG_16(TIM16_BASE + 0x34)   // Capture/compare register 1
#define TIM16_BDTR      REG_16(TIM16_BASE + 0x44)   // Break and dead-time register
#define TIM16_DCR	    REG_16(TIM16_BASE + 0x48)   // DMA control register
#define TIM16_DMAR	    REG_16(TIM16_BASE + 0x4c)   // DMA address register for full transfer

#define TIM17_CR1       REG_16(TIM17_BASE + 0x00)   // Control register 1
#define TIM17_CR2       REG_16(TIM17_BASE + 0x04)   // Control register 2
#define TIM17_DIER      REG_16(TIM17_BASE + 0x0c)   // DMA interrupt enable register
#define TIM17_SR        REG_16(TIM17_BASE + 0x10)   // Status register
#define TIM17_EGR       REG_16(TIM17_BASE + 0x14)   // Event generation register
#define TIM17_CCMR1     REG_16(TIM17_BASE + 0x18)   // Capture/compare mode register 1 [alternate]
#define TIM17_CCER      REG_16(TIM17_BASE + 0x20)   // Capture/compare enable register
#define TIM17_CNT       REG_16(TIM17_BASE + 0x24)   // Counter
#define TIM17_PSC       REG_16(TIM17_BASE + 0x28)   // Prescaler
#define TIM17_ARR	    REG_16(TIM17_BASE + 0x2c)   // Auto-reload register
#define TIM17_RCR       REG_16(TIM17_BASE + 0x30)   // Repetition counter register
#define TIM17_CCR1	    REG_16(TIM17_BASE + 0x34)   // Capture/compare register 1
#define TIM17_BDTR      REG_16(TIM17_BASE + 0x44)   // Break and dead-time register
#define TIM17_DCR	    REG_16(TIM17_BASE + 0x48)   // DMA control register
#define TIM17_DMAR	    REG_16(TIM17_BASE + 0x4c)   // DMA address register for full transfer

/* Flash registers. */

#define FLASH_ACR	    REG_32(FLASH_BASE + 0x00)
#define FLASH_KEYR	    REG_32(FLASH_BASE + 0x04)
#define FLASH_OPTKEYR	REG_32(FLASH_BASE + 0x08)
#define FLASH_SR	    REG_32(FLASH_BASE + 0x0c)
#define FLASH_CR	    REG_32(FLASH_BASE + 0x10)
#define FLASH_AR	    REG_32(FLASH_BASE + 0x14)
#define FLASH_OBR	    REG_32(FLASH_BASE + 0x1c)
#define FLASH_WRPR	    REG_32(FLASH_BASE + 0x20)

#endif
