
CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

CCFLAGS=-mcpu=cortex-m0 -mthumb -g -Wall -Wshadow

GCCARM_ROOT=/usr/local/gcc-arm-none-eabi

LDFLAGS +=-L /usr/local/opt/binutils/lib
LDFLAGS +=-L $(GCCARM_ROOT)/lib/gcc/arm-none-eabi/9.3.1/thumb/v6-m
LDFLAGS+=-L  $(GCCARM_ROOT)/lib/gcc/arm-none-eabi/9.3.1/

OBJS=\
	init.o \
	blinky.o

all: blinky

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

blinky: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -lgcc -T stm32f04f6p6.ld --cref -Map blinky.map -nostartfiles -o blinky.elf
	$(OBJCOPY) -O ihex blinky.elf blinky.hex

.PHONY: all blinky clean
clean:
	rm $(OBJS)
	rm *.elf *.hex *.map
