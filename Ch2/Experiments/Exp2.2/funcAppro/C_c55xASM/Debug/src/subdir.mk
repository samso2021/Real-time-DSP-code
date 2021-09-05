################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/c55xxASMTest.c 

ASM_SRCS += \
../src/cos.asm 

ASM_DEPS += \
./src/cos.pp 

OBJS += \
./src/c55xxASMTest.obj \
./src/cos.obj 

C_DEPS += \
./src/c55xxASMTest.pp 

ASM_DEPS__QUOTED += \
"src\cos.pp" 

C_DEPS__QUOTED += \
"src\c55xxASMTest.pp" 

OBJS__QUOTED += \
"src\c55xxASMTest.obj" \
"src\cos.obj" 

C_SRCS__QUOTED += \
"../src/c55xxASMTest.c" 

ASM_SRCS__QUOTED += \
"../src/cos.asm" 


# Each subdirectory must supply rules for building sources it contributes
src/c55xxASMTest.obj: ../src/c55xxASMTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/c55xxASMTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cos.obj: ../src/cos.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/cos.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


