################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/assembly_programTest.c 

ASM_SRCS += \
../src/assembly.asm \
../src/dft_128.asm \
../src/mag_128.asm 

ASM_DEPS += \
./src/assembly.pp \
./src/dft_128.pp \
./src/mag_128.pp 

OBJS += \
./src/assembly.obj \
./src/assembly_programTest.obj \
./src/dft_128.obj \
./src/mag_128.obj 

C_DEPS += \
./src/assembly_programTest.pp 

ASM_DEPS__QUOTED += \
"src\assembly.pp" \
"src\dft_128.pp" \
"src\mag_128.pp" 

C_DEPS__QUOTED += \
"src\assembly_programTest.pp" 

OBJS__QUOTED += \
"src\assembly.obj" \
"src\assembly_programTest.obj" \
"src\dft_128.obj" \
"src\mag_128.obj" 

ASM_SRCS__QUOTED += \
"../src/assembly.asm" \
"../src/dft_128.asm" \
"../src/mag_128.asm" 

C_SRCS__QUOTED += \
"../src/assembly_programTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/assembly.obj: ../src/assembly.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/assembly.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/assembly_programTest.obj: ../src/assembly_programTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/assembly_programTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dft_128.obj: ../src/dft_128.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/dft_128.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mag_128.obj: ../src/mag_128.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/mag_128.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


