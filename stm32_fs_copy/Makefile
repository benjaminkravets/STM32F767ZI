

#CC, CFLAGS, etc. are implicit variables used by implicit rules for automatic compilation/linking which allow, for instance, just running 'make file.c' and getting an .elf (check out implicits using make -p)
#here, explicit rules are used

CC=arm-none-eabi-gcc
#nano.specs will use nanolib instead of stdlib or newlib
CFLAGS=-mcpu=cortex-m7 -mthumb --specs=nano.specs -DSTM32F767xx -MD -g3 -ggdb -Wall -Wextra
CPPFLAGS=-Ivendor -Isrc

#nanolib doesn't support floats for printf/scanf by default
LINKER_FILE_APP=linker_app.ld -u _printf_float -Wl,-Map="app.map"
LDFLAGS_APP=-T $(LINKER_FILE_APP)

LINKER_FILE_BOOT=linker_boot.ld -u _printf_float -Wl,-Map="boot.map" 
LDFLAGS_BOOT=-T $(LINKER_FILE_BOOT)

OCPY=arm-none-eabi-objcopy

PROGRAMMER_APP= powershell.exe -c "& 'C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe' -c port=SWD -d C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs_copy\app.elf 0x08008000 -rst"
PROGRAMMER_BOOT= powershell.exe -c "& 'C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe' -c port=SWD -d C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs_copy\boot.elf 0x08000000 -rst"

PROGRAMMER_IMAGE= powershell.exe -c "& 'C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe' -c port=SWD -d C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs_copy\image.bin 0x08000000 -rst"

#target: prerequisites
#	command

#objcopies each .elf to a .bin, padding the bottloader with FF up to the app .bin.
image.bin: all
	$(OCPY) boot.elf -O binary "boot.bin" --pad-to=0x08008000 --gap-fill=0xFF
	$(OCPY) app.elf -O binary "app.bin"
	cat boot.bin app.bin > image.bin

all: app.elf boot.elf

OBJS = src/startup.o vendor/system_stm32f7xx.o src/syscalls.o src/usart.o src/dma.o src/spi.o src/exti_gpio_irq.o
       
#$^ is an automatic variable and means "all prerequisites" ($< is first prerequisite). $@ means the name of the target of the rule
app.elf: main_app.o $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS_APP) $^ -o app.elf

boot.elf: main_boot.o $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS_BOOT) $^ -o boot.elf

# main_boot.o: main_boot.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

# main_app.o: main_app.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

# system_stm32f7xx.o: vendor/system_stm32f7xx.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

# dma.o: src/dma.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

# this handles all .o files given their .c, including those in subdirectories src and vendor (instead of above commented rules)
%.o: %.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -Wa,-adhlns=$(@:.o=.lst) $^ -c -o $@

flash_app: app.elf
	$(PROGRAMMER_APP)
flash_boot: boot.elf
	$(PROGRAMMER_BOOT)
flash_image: image.bin
	$(PROGRAMMER_IMAGE)

#a phony target has no outputs, it will just run a command
.PHONY: clean

clean:
	find . -type f \( -name "*.o" -o -name "*.d" -o -name "*.bin" -o -name "*.elf" -o -name "*.lst" \) -delete

#export PATH="/home/ben/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi/bin/:$PATH"

