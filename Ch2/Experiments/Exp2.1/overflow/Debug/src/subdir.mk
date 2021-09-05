################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/overflowTest.c 

ASM_SRCS += \
../src/ovf_sat.asm 

ASM_DEPS += \
./src/ovf_sat.pp 

OBJS += \
./src/overflowTest.obj \
./src/ovf_sat.obj 

C_DEPS += \
./src/overflowTest.pp 

ASM_DEPS__QUOTED += \
"src\ovf_sat.pp" 

C_DEPS__QUOTED += \
"src\overflowTest.pp" 

OBJS__QUOTED += \
"src\overflowTest.obj" \
"src\ovf_sat.obj" 

C_SRCS__QUOTED += \
"../src/overflowTest.c" 

ASM_SRCS__QUOTED += \
"../src/ovf_sat.asm" 


# Each subdirectory must supply rules for building sources it contributes
src/overflowTest.obj: ../src/overflowTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/overflowTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ovf_sat.obj: ../src/ovf_sat.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/ovf_sat.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


