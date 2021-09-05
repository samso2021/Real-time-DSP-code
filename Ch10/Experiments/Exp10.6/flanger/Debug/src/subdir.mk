################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/flanger.c \
../src/flangerTest.c 

OBJS += \
./src/flanger.obj \
./src/flangerTest.obj 

C_DEPS += \
./src/flanger.pp \
./src/flangerTest.pp 

C_DEPS__QUOTED += \
"src\flanger.pp" \
"src\flangerTest.pp" 

OBJS__QUOTED += \
"src\flanger.obj" \
"src\flangerTest.obj" 

C_SRCS__QUOTED += \
"../src/flanger.c" \
"../src/flangerTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/flanger.obj: ../src/flanger.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/flanger.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/flangerTest.obj: ../src/flangerTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/flangerTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


