
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
	main.o

main.elf : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -lgcc -T stm32f04f6p6.ld --cref -Map main.map -nostartfiles -o main.elf

	$(OBJCOPY) -O ihex main.elf main.hex

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o

init.o: init.c
	$(CC) -c $(CCFLAGS) init.c -o init.o

clean:
	rm $(OBJS)
	rm main.elf main.hex main.map
