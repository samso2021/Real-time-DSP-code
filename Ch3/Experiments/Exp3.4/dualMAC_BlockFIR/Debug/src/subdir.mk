################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dualMacFirTest.c 

ASM_SRCS += \
../src/dualMacFir.asm 

ASM_DEPS += \
./src/dualMacFir.pp 

OBJS += \
./src/dualMacFir.obj \
./src/dualMacFirTest.obj 

C_DEPS += \
./src/dualMacFirTest.pp 

ASM_DEPS__QUOTED += \
"src\dualMacFir.pp" 

C_DEPS__QUOTED += \
"src\dualMacFirTest.pp" 

OBJS__QUOTED += \
"src\dualMacFir.obj" \
"src\dualMacFirTest.obj" 

ASM_SRCS__QUOTED += \
"../src/dualMacFir.asm" 

C_SRCS__QUOTED += \
"../src/dualMacFirTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/dualMacFir.obj: ../src/dualMacFir.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dualMacFir.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dualMacFirTest.obj: ../src/dualMacFirTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dualMacFirTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


