

for headers and addresses, get:
    https://github.com/ARM-software/CMSIS_6.git
    https://github.com/STMicroelectronics/cmsis_device_f7.git


install gcc tools:
    from https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads download
    wget https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi.tar.xz
    tar -xf package.tar.xz
    export PATH="/home/ben/arm-gnu-toolchain-14.2.rel1-x86_64-arm-none-eabi/bin/:$PATH" to add to path

to compile:
arm-none-eabi-gcc main.c startup.c -T linker.ld -o blink.elf -mcpu=cortex-m7 -mthumb -nostdlib

to copy to bin:
    arm-none-eabi-objcopy -O binary blink.elf "blink.bin"

    arm-none-eabi-gcc main.c startup.c vendor/CMSIS/Device/ST/STM32F4/Source/Templates/system_stm32f4xx.c -T linker_script.ld -o blink.elf -Ivendor/CMSIS/CMSIS/Core/Include -Ivendor/CMSIS/Device/ST/STM32F4/Include -mcpu=cortex-m4 -mthumb -nostdlib -DSTM32F410Rx


how vendor dir was made:
    add all .c/.h from vendor code: 
        find mints -type f -exec cp {} vendor/ \;
    copy m-profile dir to vendor

making sure type names resolve correctly for vscode:

    make sure ' "__CC_ARM"' is under 'defines' in C/C++ JSON configuration (may need created)

Debugging
    (details from UM2576)
    Run ST-link debug server:
        ST-LINK_gdbserver.exe -d -v -cp path-to-stm-32-programmer
        ..or..
        C:\ST\STM32CubeIDE_1.11.2\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.stlink-gdb-server.win32_2.1.400.202404281720\tools\bin\ST-LINK_gdbserver.exe -d -v -e -cp C:\ST\STM32CubeIDE_1.11.2\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.win32_2.1.400.202404281720\tools\bin

    Run GDB:
        arm-none-eabi-gdb.exe target.elf
        ..or..
        C:\Users\bakra\Desktop\arm-none-eabi\arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi\arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-gdb.exe C:\Users\bakra\Desktop\STM32F767ZI\stm32_fs_copy\app.elf

        then target remote localhost:61234

