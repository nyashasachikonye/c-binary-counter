CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m0 -mthumb -g -std=c99

AS = arm-none-eabi-as
ASFLAGS = -mcpu=cortex-m0 -mthumb -g

LD = arm-none-eabi-ld
LINKER_FILE = linker.ld
LDFLAGS = -T $(LINKER_FILE) -nostartfiles

OBJS = \
       main.o \
       startup.o \

main.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o main.elf $(OBJS)
	
main.o: main.c
startup.o: startup.s

clean:
	$(RM) *.o *.elf *.bin

run:
	arm-none-eabi-gdb main.elf
