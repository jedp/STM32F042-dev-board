
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
	hello.o

all: hello

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

hello: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -lgcc -T stm32f04f6p6.ld --cref -Map hello.map -nostartfiles -o hello.elf
	$(OBJCOPY) -O ihex hello.elf hello.hex

.PHONY: all hello clean
clean:
	rm $(OBJS)
	rm *.elf *.hex *.map
