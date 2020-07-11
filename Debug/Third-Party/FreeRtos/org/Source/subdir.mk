################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/FreeRtos/org/Source/croutine.c \
../Third-Party/FreeRtos/org/Source/event_groups.c \
../Third-Party/FreeRtos/org/Source/list.c \
../Third-Party/FreeRtos/org/Source/queue.c \
../Third-Party/FreeRtos/org/Source/stream_buffer.c \
../Third-Party/FreeRtos/org/Source/tasks.c \
../Third-Party/FreeRtos/org/Source/timers.c 

OBJS += \
./Third-Party/FreeRtos/org/Source/croutine.o \
./Third-Party/FreeRtos/org/Source/event_groups.o \
./Third-Party/FreeRtos/org/Source/list.o \
./Third-Party/FreeRtos/org/Source/queue.o \
./Third-Party/FreeRtos/org/Source/stream_buffer.o \
./Third-Party/FreeRtos/org/Source/tasks.o \
./Third-Party/FreeRtos/org/Source/timers.o 

C_DEPS += \
./Third-Party/FreeRtos/org/Source/croutine.d \
./Third-Party/FreeRtos/org/Source/event_groups.d \
./Third-Party/FreeRtos/org/Source/list.d \
./Third-Party/FreeRtos/org/Source/queue.d \
./Third-Party/FreeRtos/org/Source/stream_buffer.d \
./Third-Party/FreeRtos/org/Source/tasks.d \
./Third-Party/FreeRtos/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/FreeRtos/org/Source/%.o: ../Third-Party/FreeRtos/org/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DUSE_SEMIHOSTING -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -I"C:/Ac6/STM32_HelloWorld/CMSIS/core" -I"C:/Ac6/STM32_HelloWorld/Config" -I"C:/Ac6/STM32_HelloWorld/Third-Party/FreeRtos/org/Source/portable/GCC/ARM_CM4F" -I"C:/Ac6/STM32_HelloWorld/Third-Party/FreeRtos/org/Source/include" -I"C:/Ac6/STM32_HelloWorld/CMSIS/device" -I"C:/Ac6/STM32_HelloWorld/inc" -I"C:/Ac6/STM32_HelloWorld/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


