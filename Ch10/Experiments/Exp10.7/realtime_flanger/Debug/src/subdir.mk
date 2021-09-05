################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/realtime_flanger.c \
../src/realtime_flangerTest.c 

ASM_SRCS += \
../src/dataMove.asm \
../src/vector.asm 

ASM_DEPS += \
./src/dataMove.pp \
./src/vector.pp 

OBJS += \
./src/dataMove.obj \
./src/realtime_flanger.obj \
./src/realtime_flangerTest.obj \
./src/vector.obj 

C_DEPS += \
./src/realtime_flanger.pp \
./src/realtime_flangerTest.pp 

ASM_DEPS__QUOTED += \
"src\dataMove.pp" \
"src\vector.pp" 

C_DEPS__QUOTED += \
"src\realtime_flanger.pp" \
"src\realtime_flangerTest.pp" 

OBJS__QUOTED += \
"src\dataMove.obj" \
"src\realtime_flanger.obj" \
"src\realtime_flangerTest.obj" \
"src\vector.obj" 

ASM_SRCS__QUOTED += \
"../src/dataMove.asm" \
"../src/vector.asm" 

C_SRCS__QUOTED += \
"../src/realtime_flanger.c" \
"../src/realtime_flangerTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/dataMove.obj: ../src/dataMove.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --opt_for_speed=2 --preproc_with_compile --preproc_dependency="src/dataMove.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/realtime_flanger.obj: ../src/realtime_flanger.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --opt_for_speed=2 --preproc_with_compile --preproc_dependency="src/realtime_flanger.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/realtime_flangerTest.obj: ../src/realtime_flangerTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --opt_for_speed=2 --preproc_with_compile --preproc_dependency="src/realtime_flangerTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/vector.obj: ../src/vector.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --opt_for_speed=2 --preproc_with_compile --preproc_dependency="src/vector.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


