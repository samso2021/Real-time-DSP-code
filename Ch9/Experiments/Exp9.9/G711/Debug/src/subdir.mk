################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/g711.c \
../src/g711Test.c 

OBJS += \
./src/g711.obj \
./src/g711Test.obj 

C_DEPS += \
./src/g711.pp \
./src/g711Test.pp 

C_DEPS__QUOTED += \
"src\g711.pp" \
"src\g711Test.pp" 

OBJS__QUOTED += \
"src\g711.obj" \
"src\g711Test.obj" 

C_SRCS__QUOTED += \
"../src/g711.c" \
"../src/g711Test.c" 


# Each subdirectory must supply rules for building sources it contributes
src/g711.obj: ../src/g711.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/g711.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/g711Test.obj: ../src/g711Test.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/g711Test.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


