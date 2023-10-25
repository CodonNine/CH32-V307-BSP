################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/src/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include App/W25Q/subdir.mk
-include App/LCD/subdir.mk
-include App/AT24CX/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
BSP.hex \

SECONDARY_LIST += \
BSP.lst \

SECONDARY_SIZE += \
BSP.siz \


# 所有目标
all: BSP.elf secondary-outputs

# 工具调用
BSP.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "F:\PROJECT\CH32\BSP\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"BSP.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -o "BSP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
BSP.hex: BSP.elf
	@	riscv-none-embed-objcopy -O ihex "BSP.elf"  "BSP.hex"
	@	@
BSP.lst: BSP.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "BSP.elf" > "BSP.lst"
	@	@
BSP.siz: BSP.elf
	@	riscv-none-embed-size --format=berkeley "BSP.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) BSP.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
