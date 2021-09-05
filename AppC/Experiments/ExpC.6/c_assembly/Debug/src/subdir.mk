################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/c_assemblyTest.c \
../src/sort.c 

ASM_SRCS += \
../src/arraySort.asm \
../src/findMax.asm 

ASM_DEPS += \
./src/arraySort.pp \
./src/findMax.pp 

OBJS += \
./src/arraySort.obj \
./src/c_assemblyTest.obj \
./src/findMax.obj \
./src/sort.obj 

C_DEPS += \
./src/c_assemblyTest.pp \
./src/sort.pp 

ASM_DEPS__QUOTED += \
"src\arraySort.pp" \
"src\findMax.pp" 

C_DEPS__QUOTED += \
"src\c_assemblyTest.pp" \
"src\sort.pp" 

OBJS__QUOTED += \
"src\arraySort.obj" \
"src\c_assemblyTest.obj" \
"src\findMax.obj" \
"src\sort.obj" 

ASM_SRCS__QUOTED += \
"../src/arraySort.asm" \
"../src/findMax.asm" 

C_SRCS__QUOTED += \
"../src/c_assemblyTest.c" \
"../src/sort.c" 


# Each subdirectory must supply rules for building sources it contributes
src/arraySort.obj: ../src/arraySort.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/arraySort.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/c_assemblyTest.obj: ../src/c_assemblyTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/c_assemblyTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/findMax.obj: ../src/findMax.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/findMax.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sort.obj: ../src/sort.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/sort.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


