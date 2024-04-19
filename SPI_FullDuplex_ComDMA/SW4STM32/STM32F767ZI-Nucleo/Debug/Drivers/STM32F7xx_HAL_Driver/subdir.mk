################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c 

OBJS += \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.o \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.o 

C_DEPS += \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.d \
./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.o: C:/Users/bakra/Desktop/STM32F767ZI/SPI_FullDuplex_ComDMA/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c Drivers/STM32F7xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F767xx -DUSE_STM32F7XX_NUCLEO_144 -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32F7xx_Nucleo_144 -I../../../Drivers/BSP/Components/Common -I../../../Utilities/Log -I../../../Utilities/Fonts -I../../../Utilities/CPU -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F7xx_HAL_Driver

clean-Drivers-2f-STM32F7xx_HAL_Driver:
	-$(RM) ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_cortex.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_dma.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_gpio.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_i2c.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_pwr_ex.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_rcc_ex.su ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.cyclo ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.d ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.o ./Drivers/STM32F7xx_HAL_Driver/stm32f7xx_hal_spi.su

.PHONY: clean-Drivers-2f-STM32F7xx_HAL_Driver

