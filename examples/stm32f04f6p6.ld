/*
 * STM32F042F6P6 linker script.
 *
 * Helpful references:
 *
 * https://ioprog.com/arm-cortex/the-linker-script-file/
 * http://web.mit.edu/rhel-doc/3/rhel-ld-en-3/scripts.html
 */

_stack_top = ORIGIN(ram) + LENGTH(ram);

MEMORY
{
    flash : org = 0x8000000, len = 32k
    ram : org = 0x20000000, len = 6k
}

SECTIONS
{
    . = ORIGIN(flash);
        .text : {
            *(.vectors);
            *(.text);
        } >flash

    . = ORIGIN(ram);
        .data : {
            /* Start of initialization data in ROM; Use this to copy init code from ROM to RAM. */
            INIT_DATA_VALUES = LOADADDR(.data);
            INIT_DATA_START = .;
                *(.data);
            INIT_DATA_END = .;
        } >ram AT>flash

    BSS_START = .;
        .bss : {
            *(.bss);
        } >ram
    BSS_END = .;
}