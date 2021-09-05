################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/blockFirTest.c 

ASM_SRCS += \
../src/blockFir.asm 

ASM_DEPS += \
./src/blockFir.pp 

OBJS += \
./src/blockFir.obj \
./src/blockFirTest.obj 

C_DEPS += \
./src/blockFirTest.pp 

ASM_DEPS__QUOTED += \
"src\blockFir.pp" 

C_DEPS__QUOTED += \
"src\blockFirTest.pp" 

OBJS__QUOTED += \
"src\blockFir.obj" \
"src\blockFirTest.obj" 

ASM_SRCS__QUOTED += \
"../src/blockFir.asm" 

C_SRCS__QUOTED += \
"../src/blockFirTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/blockFir.obj: ../src/blockFir.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/blockFir.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/blockFirTest.obj: ../src/blockFirTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/blockFirTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


