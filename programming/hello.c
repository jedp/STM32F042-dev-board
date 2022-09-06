#include "stm32f042f6p6.h"
#include "main.h"

/*
 * Blink the on-board LED, which is PB1.
 */

static void setup(void) {
    // Enable peripheral clock for PORTB.
    RCC_AHBENR |= BIT_18;

    // Set mode to 01 (output) for PB1.
    GPIOB_MODER |= BIT_2;
    GPIOB_MODER &= ~BIT_3;

    // We can now blink the LED on PB1 by toggling bit 1 on GPIOB_ODR.
}

static void delay_ms(int delay_ms) {
    // Delay implemented using TIM14.
    // TIM14 is a general purpose timer with the added bonus that it consumes the least current.
    // See datasheet Table 32, Peripheral current consumption. TIM14 consumes 5.5 uA / MHz.

    // Enable TIM14 for use as our delay timer.
    RCC_APB1ENR |= BIT_8;

    TIM14_SR = 0;                   // Reset status register. (Cancel UIF etc.)
    TIM14_PSC = 8 * 1000 - 1;
    TIM14_ARR = delay_ms;
    TIM14_CR1 |= BIT_0;             // Start the timer counter
    while (!(TIM14_SR & BIT_0));    // Wait until update interrupt flag is set.
}

int main() {
    setup();

    while (1) {
        // Pin 1 on.
        GPIOB_ODR |= BIT_1;
        delay_ms(1000);

        // Pin 1 off.
        GPIOB_ODR &= ~BIT_1;
        delay_ms(1000);
    }
}
