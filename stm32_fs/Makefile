
#CC, CFLAGS, etc. are implicit variables used by implicit rules for automatic compilation/linking which allow, for instance, just running 'make file.c' and getting an .elf (check out implicits using make -p)
#here, explicit rules are used

CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m7 -mthumb -nostdlib
CPPFLAGS=-Iandy

LINKER_FILE=linker.ld
LDFLAGS=-T $(LINKER_FILE)

PROGRAMMER= powershell.exe -c "& 'C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe' -c port=SWD -d C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs\blink.elf 0x08000000"

#target: prerequisites
#	command

all: blink.elf

#$^ is an automatic variable and means "all prerequisites". $@ means the name of the target of the rule
blink.elf: main.o startup.o 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o blink.elf

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) main.c -c

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) startup.c -c

flash: blink.elf
	$(PROGRAMMER)
#a phony target has no outputs, it will just run a command
.PHONY: clean
clean:
	rm -f *.o *.elf
