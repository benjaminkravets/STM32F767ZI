################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_TwoBoards_FullDuplex_DMA/Src/main.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_TwoBoards_FullDuplex_DMA/Src/stm32f7xx_it.c 

OBJS += \
./Example/User/main.o \
./Example/User/stm32f7xx_it.o 

C_DEPS += \
./Example/User/main.d \
./Example/User/stm32f7xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Example/User/main.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_TwoBoards_FullDuplex_DMA/Src/main.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000U -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -Wno-strict-aliasing -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Example/User/stm32f7xx_it.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_TwoBoards_FullDuplex_DMA/Src/stm32f7xx_it.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000U -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -Wno-strict-aliasing -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Example-2f-User

clean-Example-2f-User:
	-$(RM) ./Example/User/main.cyclo ./Example/User/main.d ./Example/User/main.o ./Example/User/main.su ./Example/User/stm32f7xx_it.cyclo ./Example/User/stm32f7xx_it.d ./Example/User/stm32f7xx_it.o ./Example/User/stm32f7xx_it.su

.PHONY: clean-Example-2f-User

