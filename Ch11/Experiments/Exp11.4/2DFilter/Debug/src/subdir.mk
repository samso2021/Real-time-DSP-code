################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/filter2DTest.c 

ASM_SRCS += \
../src/filter2D.asm 

ASM_DEPS += \
./src/filter2D.pp 

OBJS += \
./src/filter2D.obj \
./src/filter2DTest.obj 

C_DEPS += \
./src/filter2DTest.pp 

ASM_DEPS__QUOTED += \
"src\filter2D.pp" 

C_DEPS__QUOTED += \
"src\filter2DTest.pp" 

OBJS__QUOTED += \
"src\filter2D.obj" \
"src\filter2DTest.obj" 

ASM_SRCS__QUOTED += \
"../src/filter2D.asm" 

C_SRCS__QUOTED += \
"../src/filter2DTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/filter2D.obj: ../src/filter2D.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/filter2D.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/filter2DTest.obj: ../src/filter2DTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/filter2DTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


