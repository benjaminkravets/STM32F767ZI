################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/SEGGER_RTT.c \
../Core/Inc/SEGGER_RTT_Syscalls_GCC.c \
../Core/Inc/SEGGER_RTT_Syscalls_IAR.c \
../Core/Inc/SEGGER_RTT_Syscalls_KEIL.c \
../Core/Inc/SEGGER_RTT_Syscalls_SES.c \
../Core/Inc/SEGGER_RTT_printf.c \
../Core/Inc/SEGGER_SYSVIEW.c \
../Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.c \
../Core/Inc/SEGGER_SYSVIEW_FreeRTOS.c 

S_UPPER_SRCS += \
../Core/Inc/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Core/Inc/SEGGER_RTT.o \
./Core/Inc/SEGGER_RTT_ASM_ARMv7M.o \
./Core/Inc/SEGGER_RTT_Syscalls_GCC.o \
./Core/Inc/SEGGER_RTT_Syscalls_IAR.o \
./Core/Inc/SEGGER_RTT_Syscalls_KEIL.o \
./Core/Inc/SEGGER_RTT_Syscalls_SES.o \
./Core/Inc/SEGGER_RTT_printf.o \
./Core/Inc/SEGGER_SYSVIEW.o \
./Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.o \
./Core/Inc/SEGGER_SYSVIEW_FreeRTOS.o 

S_UPPER_DEPS += \
./Core/Inc/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Core/Inc/SEGGER_RTT.d \
./Core/Inc/SEGGER_RTT_Syscalls_GCC.d \
./Core/Inc/SEGGER_RTT_Syscalls_IAR.d \
./Core/Inc/SEGGER_RTT_Syscalls_KEIL.d \
./Core/Inc/SEGGER_RTT_Syscalls_SES.d \
./Core/Inc/SEGGER_RTT_printf.d \
./Core/Inc/SEGGER_SYSVIEW.d \
./Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.d \
./Core/Inc/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Inc/%.o: ../Core/Inc/%.S Core/Inc/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/SEGGER_RTT.cyclo ./Core/Inc/SEGGER_RTT.d ./Core/Inc/SEGGER_RTT.o ./Core/Inc/SEGGER_RTT.su ./Core/Inc/SEGGER_RTT_ASM_ARMv7M.d ./Core/Inc/SEGGER_RTT_ASM_ARMv7M.o ./Core/Inc/SEGGER_RTT_Syscalls_GCC.cyclo ./Core/Inc/SEGGER_RTT_Syscalls_GCC.d ./Core/Inc/SEGGER_RTT_Syscalls_GCC.o ./Core/Inc/SEGGER_RTT_Syscalls_GCC.su ./Core/Inc/SEGGER_RTT_Syscalls_IAR.cyclo ./Core/Inc/SEGGER_RTT_Syscalls_IAR.d ./Core/Inc/SEGGER_RTT_Syscalls_IAR.o ./Core/Inc/SEGGER_RTT_Syscalls_IAR.su ./Core/Inc/SEGGER_RTT_Syscalls_KEIL.cyclo ./Core/Inc/SEGGER_RTT_Syscalls_KEIL.d ./Core/Inc/SEGGER_RTT_Syscalls_KEIL.o ./Core/Inc/SEGGER_RTT_Syscalls_KEIL.su ./Core/Inc/SEGGER_RTT_Syscalls_SES.cyclo ./Core/Inc/SEGGER_RTT_Syscalls_SES.d ./Core/Inc/SEGGER_RTT_Syscalls_SES.o ./Core/Inc/SEGGER_RTT_Syscalls_SES.su ./Core/Inc/SEGGER_RTT_printf.cyclo ./Core/Inc/SEGGER_RTT_printf.d ./Core/Inc/SEGGER_RTT_printf.o ./Core/Inc/SEGGER_RTT_printf.su ./Core/Inc/SEGGER_SYSVIEW.cyclo ./Core/Inc/SEGGER_SYSVIEW.d ./Core/Inc/SEGGER_SYSVIEW.o ./Core/Inc/SEGGER_SYSVIEW.su ./Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.d ./Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.o ./Core/Inc/SEGGER_SYSVIEW_Config_FreeRTOS.su ./Core/Inc/SEGGER_SYSVIEW_FreeRTOS.cyclo ./Core/Inc/SEGGER_SYSVIEW_FreeRTOS.d ./Core/Inc/SEGGER_SYSVIEW_FreeRTOS.o ./Core/Inc/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-Core-2f-Inc

