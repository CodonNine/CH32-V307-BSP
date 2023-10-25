################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/LCD/lcd.c \
../App/LCD/lcd_init.c 

OBJS += \
./App/LCD/lcd.o \
./App/LCD/lcd_init.o 

C_DEPS += \
./App/LCD/lcd.d \
./App/LCD/lcd_init.d 


# Each subdirectory must supply rules for building sources it contributes
App/LCD/%.o: ../App/LCD/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\PROJECT\CH32\BSP\User\inc" -I"F:\PROJECT\CH32\BSP\App" -I"F:\PROJECT\CH32\BSP\Debug" -I"F:\PROJECT\CH32\BSP\Core" -I"F:\PROJECT\CH32\BSP\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

