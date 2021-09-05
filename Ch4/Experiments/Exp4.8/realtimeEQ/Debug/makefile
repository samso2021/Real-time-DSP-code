################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./src/vector.obj" \
"./src/realtimeEQTest.obj" \
"./src/equalizer.obj" \
"./src/asmIIR.obj" \
-l"libc.a" \
"../lib/myC55xUtil.lib" \
"../c5505.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include lib/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: realtimeEQ.out

# Tool invocations
realtimeEQ.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic -z -m"realtimeEQ.map" --stack_size=1000 --warn_sections -i"C:/ti/ccsv5/tools/compiler/c5500/lib" -i"C:/ti/ccsv5/tools/compiler/c5500/include" -i"C:/ti/bios_5_41_10_36/packages/ti/rtdx/lib/c5500" -i"C:/ti/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Users/DSP_3edFinal/software/Ch4/Experiments/Exp4.8/realtimeEQ" -i"/lib" --reread_libs --entry_point=reset_isr --rom_model --sys_stacksize=1000 -o "realtimeEQ.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_CMDS__QUOTED)$(GEN_SRCS__QUOTED)$(C5500_EXECUTABLE_OUTPUTS__QUOTED) "realtimeEQ.out"
	-$(RM) "src\asmIIR.pp" "src\vector.pp" 
	-$(RM) "src\equalizer.pp" "src\realtimeEQTest.pp" 
	-$(RM) "src\asmIIR.obj" "src\equalizer.obj" "src\realtimeEQTest.obj" "src\vector.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
