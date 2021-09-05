################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/asmIIRTest.c 

ASM_SRCS += \
../src/asmIIR.asm 

ASM_DEPS += \
./src/asmIIR.pp 

OBJS += \
./src/asmIIR.obj \
./src/asmIIRTest.obj 

C_DEPS += \
./src/asmIIRTest.pp 

ASM_DEPS__QUOTED += \
"src\asmIIR.pp" 

C_DEPS__QUOTED += \
"src\asmIIRTest.pp" 

OBJS__QUOTED += \
"src\asmIIR.obj" \
"src\asmIIRTest.obj" 

ASM_SRCS__QUOTED += \
"../src/asmIIR.asm" 

C_SRCS__QUOTED += \
"../src/asmIIRTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/asmIIR.obj: ../src/asmIIR.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/asmIIR.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/asmIIRTest.obj: ../src/asmIIRTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/asmIIRTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


