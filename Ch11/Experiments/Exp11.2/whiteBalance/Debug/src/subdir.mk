################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/whitebalance.c \
../src/whitebalanceTest.c 

OBJS += \
./src/whitebalance.obj \
./src/whitebalanceTest.obj 

C_DEPS += \
./src/whitebalance.pp \
./src/whitebalanceTest.pp 

C_DEPS__QUOTED += \
"src\whitebalance.pp" \
"src\whitebalanceTest.pp" 

OBJS__QUOTED += \
"src\whitebalance.obj" \
"src\whitebalanceTest.obj" 

C_SRCS__QUOTED += \
"../src/whitebalance.c" \
"../src/whitebalanceTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/whitebalance.obj: ../src/whitebalance.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/whitebalance.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/whitebalanceTest.obj: ../src/whitebalanceTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/whitebalanceTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


