################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adaptive_predictorTest.c 

ASM_SRCS += \
../src/adaptivePredictor.asm 

ASM_DEPS += \
./src/adaptivePredictor.pp 

OBJS += \
./src/adaptivePredictor.obj \
./src/adaptive_predictorTest.obj 

C_DEPS += \
./src/adaptive_predictorTest.pp 

ASM_DEPS__QUOTED += \
"src\adaptivePredictor.pp" 

C_DEPS__QUOTED += \
"src\adaptive_predictorTest.pp" 

OBJS__QUOTED += \
"src\adaptivePredictor.obj" \
"src\adaptive_predictorTest.obj" 

ASM_SRCS__QUOTED += \
"../src/adaptivePredictor.asm" 

C_SRCS__QUOTED += \
"../src/adaptive_predictorTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/adaptivePredictor.obj: ../src/adaptivePredictor.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/adaptivePredictor.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/adaptive_predictorTest.obj: ../src/adaptive_predictorTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/adaptive_predictorTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


