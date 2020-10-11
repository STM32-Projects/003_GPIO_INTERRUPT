################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Driver/Src/Legacy/stm32f4xx_hal_can.c 

OBJS += \
./HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o 

C_DEPS += \
./HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Driver/Src/Legacy/%.o: ../HAL_Driver/Src/Legacy/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_HAL_DRIVER -I"/home/super/Desktop/Desktop_SUPER/Mastering_STM32_Projects/003_GPIO_INTERRUPT/HAL_Driver/Inc/Legacy" -I"/home/super/Desktop/Desktop_SUPER/Mastering_STM32_Projects/003_GPIO_INTERRUPT/Utilities/STM32F4xx-Nucleo" -I"/home/super/Desktop/Desktop_SUPER/Mastering_STM32_Projects/003_GPIO_INTERRUPT/inc" -I"/home/super/Desktop/Desktop_SUPER/Mastering_STM32_Projects/003_GPIO_INTERRUPT/CMSIS/device" -I"/home/super/Desktop/Desktop_SUPER/Mastering_STM32_Projects/003_GPIO_INTERRUPT/CMSIS/core" -I"/home/super/Desktop/Desktop_SUPER/Mastering_STM32_Projects/003_GPIO_INTERRUPT/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


