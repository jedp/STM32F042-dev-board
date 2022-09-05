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

static void delay(int ticks) {
    while (ticks--);
}

int main() {
    setup();

    while (1) {
        // Pin 1 on.
        GPIOB_ODR |= BIT_1;
        delay(1000000);

        // Pin 1 off.
        GPIOB_ODR &= ~BIT_1;
        delay(1000000);
    }
}
