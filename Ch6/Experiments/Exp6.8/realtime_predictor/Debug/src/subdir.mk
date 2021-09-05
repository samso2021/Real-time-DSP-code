################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adaptive_predictor.c \
../src/realtime_predictorTest.c 

ASM_SRCS += \
../src/adaptivePredictor.asm \
../src/vector.asm 

ASM_DEPS += \
./src/adaptivePredictor.pp \
./src/vector.pp 

OBJS += \
./src/adaptivePredictor.obj \
./src/adaptive_predictor.obj \
./src/realtime_predictorTest.obj \
./src/vector.obj 

C_DEPS += \
./src/adaptive_predictor.pp \
./src/realtime_predictorTest.pp 

ASM_DEPS__QUOTED += \
"src\adaptivePredictor.pp" \
"src\vector.pp" 

C_DEPS__QUOTED += \
"src\adaptive_predictor.pp" \
"src\realtime_predictorTest.pp" 

OBJS__QUOTED += \
"src\adaptivePredictor.obj" \
"src\adaptive_predictor.obj" \
"src\realtime_predictorTest.obj" \
"src\vector.obj" 

ASM_SRCS__QUOTED += \
"../src/adaptivePredictor.asm" \
"../src/vector.asm" 

C_SRCS__QUOTED += \
"../src/adaptive_predictor.c" \
"../src/realtime_predictorTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/adaptivePredictor.obj: ../src/adaptivePredictor.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/adaptivePredictor.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/adaptive_predictor.obj: ../src/adaptive_predictor.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/adaptive_predictor.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/realtime_predictorTest.obj: ../src/realtime_predictorTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/realtime_predictorTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/vector.obj: ../src/vector.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/vector.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


