################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/interpolate.c \
../src/interpolateTest.c 

OBJS += \
./src/interpolate.obj \
./src/interpolateTest.obj 

C_DEPS += \
./src/interpolate.pp \
./src/interpolateTest.pp 

C_DEPS__QUOTED += \
"src\interpolate.pp" \
"src\interpolateTest.pp" 

OBJS__QUOTED += \
"src\interpolate.obj" \
"src\interpolateTest.obj" 

C_SRCS__QUOTED += \
"../src/interpolate.c" \
"../src/interpolateTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/interpolate.obj: ../src/interpolate.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/interpolate.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/interpolateTest.obj: ../src/interpolateTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/interpolateTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


