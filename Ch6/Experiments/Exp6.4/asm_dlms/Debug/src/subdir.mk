################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/asm_dlmsTest.c 

ASM_SRCS += \
../src/asm_dlms.asm 

ASM_DEPS += \
./src/asm_dlms.pp 

OBJS += \
./src/asm_dlms.obj \
./src/asm_dlmsTest.obj 

C_DEPS += \
./src/asm_dlmsTest.pp 

ASM_DEPS__QUOTED += \
"src\asm_dlms.pp" 

C_DEPS__QUOTED += \
"src\asm_dlmsTest.pp" 

OBJS__QUOTED += \
"src\asm_dlms.obj" \
"src\asm_dlmsTest.obj" 

ASM_SRCS__QUOTED += \
"../src/asm_dlms.asm" 

C_SRCS__QUOTED += \
"../src/asm_dlmsTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/asm_dlms.obj: ../src/asm_dlms.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="..\inc" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/asm_dlms.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/asm_dlmsTest.obj: ../src/asm_dlmsTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="..\inc" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/asm_dlmsTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


