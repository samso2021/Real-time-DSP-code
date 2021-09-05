################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fileIOTest.c 

CMD_SRCS += \
../c5505.cmd 

OBJS += \
./fileIOTest.obj 

C_DEPS += \
./fileIOTest.pp 

C_DEPS__QUOTED += \
"fileIOTest.pp" 

OBJS__QUOTED += \
"fileIOTest.obj" 

C_SRCS__QUOTED += \
"../fileIOTest.c" 


# Each subdirectory must supply rules for building sources it contributes
fileIOTest.obj: ../fileIOTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="fileIOTest.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


