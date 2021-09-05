################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sineCosineTest.c 

ASM_SRCS += \
../src/sine_cos.asm 

ASM_DEPS += \
./src/sine_cos.pp 

OBJS += \
./src/sineCosineTest.obj \
./src/sine_cos.obj 

C_DEPS += \
./src/sineCosineTest.pp 

ASM_DEPS__QUOTED += \
"src\sine_cos.pp" 

C_DEPS__QUOTED += \
"src\sineCosineTest.pp" 

OBJS__QUOTED += \
"src\sineCosineTest.obj" \
"src\sine_cos.obj" 

C_SRCS__QUOTED += \
"../src/sineCosineTest.c" 

ASM_SRCS__QUOTED += \
"../src/sine_cos.asm" 


# Each subdirectory must supply rules for building sources it contributes
src/sineCosineTest.obj: ../src/sineCosineTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/sineCosineTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sine_cos.obj: ../src/sine_cos.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/sine_cos.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


