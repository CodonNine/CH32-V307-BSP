################################################################################
# MRS Version: 1.9.0
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/W25Q/w25q.c 

OBJS += \
./App/W25Q/w25q.o 

C_DEPS += \
./App/W25Q/w25q.d 


# Each subdirectory must supply rules for building sources it contributes
App/W25Q/%.o: ../App/W25Q/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\PROJECT\CH32\BSP\User\inc" -I"F:\PROJECT\CH32\BSP\App" -I"F:\PROJECT\CH32\BSP\Debug" -I"F:\PROJECT\CH32\BSP\Core" -I"F:\PROJECT\CH32\BSP\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

