################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cng.c \
../src/cng_mainTest.c \
../src/g711.c 

OBJS += \
./src/cng.obj \
./src/cng_mainTest.obj \
./src/g711.obj 

C_DEPS += \
./src/cng.pp \
./src/cng_mainTest.pp \
./src/g711.pp 

C_DEPS__QUOTED += \
"src\cng.pp" \
"src\cng_mainTest.pp" \
"src\g711.pp" 

OBJS__QUOTED += \
"src\cng.obj" \
"src\cng_mainTest.obj" \
"src\g711.obj" 

C_SRCS__QUOTED += \
"../src/cng.c" \
"../src/cng_mainTest.c" \
"../src/g711.c" 


# Each subdirectory must supply rules for building sources it contributes
src/cng.obj: ../src/cng.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/cng.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cng_mainTest.obj: ../src/cng_mainTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/cng_mainTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/g711.obj: ../src/g711.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/g711.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


