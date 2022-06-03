################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lab_Drivers/sources/ADC.c \
../Lab_Drivers/sources/GPIO.c \
../Lab_Drivers/sources/Keypad.c \
../Lab_Drivers/sources/interrupts.c 

OBJS += \
./Lab_Drivers/sources/ADC.o \
./Lab_Drivers/sources/GPIO.o \
./Lab_Drivers/sources/Keypad.o \
./Lab_Drivers/sources/interrupts.o 

C_DEPS += \
./Lab_Drivers/sources/ADC.d \
./Lab_Drivers/sources/GPIO.d \
./Lab_Drivers/sources/Keypad.d \
./Lab_Drivers/sources/interrupts.d 


# Each subdirectory must supply rules for building sources it contributes
Lab_Drivers/sources/%.o: ../Lab_Drivers/sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -DUSE_STDPERIPH_DRIVER -I"D:/Mohamed/Third_Year/Second_Term/Digital Systems in Medical Devices/labs projects/ADC_Project/ADC/StdPeriph_Driver/inc" -I"D:/Mohamed/Third_Year/Second_Term/Digital Systems in Medical Devices/labs projects/ADC_Project/ADC/Lab_Drivers/includes" -I"D:/Mohamed/Third_Year/Second_Term/Digital Systems in Medical Devices/labs projects/ADC_Project/ADC/inc" -I"D:/Mohamed/Third_Year/Second_Term/Digital Systems in Medical Devices/labs projects/ADC_Project/ADC/CMSIS/device" -I"D:/Mohamed/Third_Year/Second_Term/Digital Systems in Medical Devices/labs projects/ADC_Project/ADC/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


