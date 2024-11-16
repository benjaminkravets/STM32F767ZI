

#CC, CFLAGS, etc. are implicit variables used by implicit rules for automatic compilation/linking which allow, for instance, just running 'make file.c' and getting an .elf (check out implicits using make -p)
#here, explicit rules are used

CC=arm-none-eabi-gcc
#nano.specs will use nanolib instead of stdlib or newlib
CFLAGS=-mcpu=cortex-m7 -mthumb --specs=nano.specs -DSTM32F767xx
CPPFLAGS=-Ivendor

#nanolib doesn't support floats for printf/scanf by default
LINKER_FILE=linker.ld -u _printf_float
LDFLAGS=-T $(LINKER_FILE)

LINKER_FILE_BOOT=linker_boot.ld -u _printf_float
LDFLAGS_BOOT=-T $(LINKER_FILE_BOOT)

PROGRAMMER= powershell.exe -c "& 'C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe' -c port=SWD -d C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs_copy\blink.elf 0x08008000 -rst"
PROGRAMMER_BOOT= powershell.exe -c "& 'C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe' -c port=SWD -d C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs_copy\boot.elf 0x08000000 -rst"

#target: prerequisites
#	command

all: blink.elf boot.elf

#$^ is an automatic variable and means "all prerequisites". $@ means the name of the target of the rule
blink.elf: main.o startup.o system_stm32f7xx.o syscalls.o usart.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o blink.elf

boot.elf: main_boot.o startup.o system_stm32f7xx.o syscalls.o usart.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS_BOOT) $^ -o boot.elf

main_boot.o: main_boot.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

system_stm32f7xx.o: vendor/system_stm32f7xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

syscalls.o: syscalls.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

usart.o: usart.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

flash: blink.elf
	$(PROGRAMMER)
flash_boot: boot.elf
	$(PROGRAMMER_BOOT)
#a phony target has no outputs, it will just run a command
.PHONY: clean
clean:
	rm -f *.o *.elf