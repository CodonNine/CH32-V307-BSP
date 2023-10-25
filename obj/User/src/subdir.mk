################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/src/adc.c \
../User/src/ch32v30x_it.c \
../User/src/dac.c \
../User/src/dma.c \
../User/src/exti.c \
../User/src/gpio.c \
../User/src/iic.c \
../User/src/main.c \
../User/src/nvic.c \
../User/src/spi.c \
../User/src/system_ch32v30x.c \
../User/src/tim.c \
../User/src/usart.c 

OBJS += \
./User/src/adc.o \
./User/src/ch32v30x_it.o \
./User/src/dac.o \
./User/src/dma.o \
./User/src/exti.o \
./User/src/gpio.o \
./User/src/iic.o \
./User/src/main.o \
./User/src/nvic.o \
./User/src/spi.o \
./User/src/system_ch32v30x.o \
./User/src/tim.o \
./User/src/usart.o 

C_DEPS += \
./User/src/adc.d \
./User/src/ch32v30x_it.d \
./User/src/dac.d \
./User/src/dma.d \
./User/src/exti.d \
./User/src/gpio.d \
./User/src/iic.d \
./User/src/main.d \
./User/src/nvic.d \
./User/src/spi.d \
./User/src/system_ch32v30x.d \
./User/src/tim.d \
./User/src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
User/src/%.o: ../User/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\PROJECT\CH32\BSP\User\inc" -I"F:\PROJECT\CH32\BSP\App" -I"F:\PROJECT\CH32\BSP\Debug" -I"F:\PROJECT\CH32\BSP\Core" -I"F:\PROJECT\CH32\BSP\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

