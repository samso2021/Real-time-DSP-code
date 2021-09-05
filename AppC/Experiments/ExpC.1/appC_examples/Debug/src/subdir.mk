################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/appC_examplesTest.c 

ASM_SRCS += \
../src/Examples.asm 

ASM_DEPS += \
./src/Examples.pp 

OBJS += \
./src/Examples.obj \
./src/appC_examplesTest.obj 

C_DEPS += \
./src/appC_examplesTest.pp 

ASM_DEPS__QUOTED += \
"src\Examples.pp" 

C_DEPS__QUOTED += \
"src\appC_examplesTest.pp" 

OBJS__QUOTED += \
"src\Examples.obj" \
"src\appC_examplesTest.obj" 

ASM_SRCS__QUOTED += \
"../src/Examples.asm" 

C_SRCS__QUOTED += \
"../src/appC_examplesTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/Examples.obj: ../src/Examples.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/Examples.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appC_examplesTest.obj: ../src/appC_examplesTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/appC_examplesTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


