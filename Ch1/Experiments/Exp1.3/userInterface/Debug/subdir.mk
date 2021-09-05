################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UITest.c 

CMD_SRCS += \
../c5505.cmd 

OBJS += \
./UITest.obj 

C_DEPS += \
./UITest.pp 

C_DEPS__QUOTED += \
"UITest.pp" 

OBJS__QUOTED += \
"UITest.obj" 

C_SRCS__QUOTED += \
"../UITest.c" 


# Each subdirectory must supply rules for building sources it contributes
UITest.obj: ../UITest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=huge --preproc_with_compile --preproc_dependency="UITest.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


