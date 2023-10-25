################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/AT24CX/at24cx.c 

OBJS += \
./App/AT24CX/at24cx.o 

C_DEPS += \
./App/AT24CX/at24cx.d 


# Each subdirectory must supply rules for building sources it contributes
App/AT24CX/%.o: ../App/AT24CX/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\PROJECT\CH32\BSP\User\inc" -I"F:\PROJECT\CH32\BSP\App" -I"F:\PROJECT\CH32\BSP\Debug" -I"F:\PROJECT\CH32\BSP\Core" -I"F:\PROJECT\CH32\BSP\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

