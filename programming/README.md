# Programming Notes

## Blinky

Use `hello.c` to blink the PB1 LED on the board.

Adjust `Makefile` as necessary for toolchain and versions.

```
make
```

Flash `main.hex` with `st-flash` or `JFlashLite`.

## Application Note Notes

### MCO Selection Code Example

RN0091, Appendix A.3.3, gives this one-line example:

```
/* Select system clock to be output on the MCO without prescaler */
RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;
```

On this board, a little more work is required. First, we must establish the MCO pin. This information is in the
data sheet, Table 14: Alternate functions selected through GPIOA_AFR registers for port A.

Here we see that MCO can either be AF0 on PA8 or AF5 on PA9. This TSSOP20 does not have a pin PA8, so we must configure
PA9 to the correct alternate mode. Back in the programming reference, Table 8.4.10 lists the register values for
GPIO alternate functions (higher register because we are using PA9). AF5 is `0101`.

So to output the MCO on PA9, the complete setup code is:

```
RCC_AHBENR |= BIT_17;           // PORTA IO enable
RCC_CFGR |= (BIT_26 | BIT_24);  // Bits27:24 MCO[3:0] 0101: Internal RC 8 MHz (HSI) oscillator clock selected
GPIOA_MODER |= BIT_19;          // PA9: Enable alternate function mode
GPIOA_AFRH |= (BIT_6 | BIT_4);  // PA9: Configure alternate function mode 5
```

My oscilloscope measures VPP 3.76 to 3.80 and Freq 7.987 to 8.013 MHz.

### Delay Function using general-purpose timer.

Implementation of `void delay(int ms)` using TIM14.

AN4776, Section 1.3.1, Timer time-base configuration, demonstrates the basic scheme of things, though as always it's a
bit elliptical about what needs to be enabled for anything to work.

Here is a complete implementation:

```
static void delay_ms(int millis) {
    // Delay implemented using TIM14.
    // TIM14 is a general purpose timer with the added bonus that it consumes the least current.
    // See datasheet Table 32, Peripheral current consumption. TIM14 consumes 5.5 uA / MHz.

    // Enable TIM14 for use as our delay timer.
    RCC_APB1ENR |= BIT_8;

    TIM14_SR = 0;
    TIM14_PSC = 8 * 1000 - 1;
    TIM14_ARR = millis;
    TIM14_CR1 |= BIT_0;             // Start the timer counter
    while (!(TIM14_SR & BIT_0));    // While UIF not set
}
```

## References

This was my first attempt at writing stm32 code without an IDE (i.e., without CubeMX generating all the low-level code
for me). I found the following references very helpful:

- https://ioprog.com/arm-cortex/the-linker-script-file/
- https://blog.thea.codes/the-most-thoroughly-commented-linker-script/
- https://freeelectron.ro/bare-metal-stm32-led-blink/
 