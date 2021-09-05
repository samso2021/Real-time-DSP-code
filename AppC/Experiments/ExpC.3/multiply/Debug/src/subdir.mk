################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/multiplyTest.c 

OBJS += \
./src/multiplyTest.obj 

C_DEPS += \
./src/multiplyTest.pp 

C_DEPS__QUOTED += \
"src\multiplyTest.pp" 

OBJS__QUOTED += \
"src\multiplyTest.obj" 

C_SRCS__QUOTED += \
"../src/multiplyTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/multiplyTest.obj: ../src/multiplyTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/multiplyTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


