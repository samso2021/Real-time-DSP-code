################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/icosTest.c 

OBJS += \
./src/icosTest.obj 

C_DEPS += \
./src/icosTest.pp 

C_DEPS__QUOTED += \
"src\icosTest.pp" 

OBJS__QUOTED += \
"src\icosTest.obj" 

C_SRCS__QUOTED += \
"../src/icosTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/icosTest.obj: ../src/icosTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/icosTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


