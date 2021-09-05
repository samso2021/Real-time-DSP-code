################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/symFirTest.c 

ASM_SRCS += \
../src/symFir.asm 

ASM_DEPS += \
./src/symFir.pp 

OBJS += \
./src/symFir.obj \
./src/symFirTest.obj 

C_DEPS += \
./src/symFirTest.pp 

ASM_DEPS__QUOTED += \
"src\symFir.pp" 

C_DEPS__QUOTED += \
"src\symFirTest.pp" 

OBJS__QUOTED += \
"src\symFir.obj" \
"src\symFirTest.obj" 

ASM_SRCS__QUOTED += \
"../src/symFir.asm" 

C_SRCS__QUOTED += \
"../src/symFirTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/symFir.obj: ../src/symFir.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/symFir.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/symFirTest.obj: ../src/symFirTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/symFirTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


