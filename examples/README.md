# Examples

## Blinky

Basic program to blink PB1 LED on the board.

Adjust `Makefile` as necessary for toolchain and versions.

```
make
```

Flash `main.hex` with `st-flash` or `JFlashLite`.

## References

This was my first attempt at writing stm32 code without an IDE (i.e., without CubeMX generating all the low-level code
for me). I found the following references very helpful:

- https://ioprog.com/arm-cortex/the-linker-script-file/
- https://blog.thea.codes/the-most-thoroughly-commented-linker-script/
- https://freeelectron.ro/bare-metal-stm32-led-blink/
 