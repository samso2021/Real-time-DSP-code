################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPointBlockFir.c \
../src/floatingPointBlockFirTest.c 

OBJS += \
./src/floatPointBlockFir.obj \
./src/floatingPointBlockFirTest.obj 

C_DEPS += \
./src/floatPointBlockFir.pp \
./src/floatingPointBlockFirTest.pp 

C_DEPS__QUOTED += \
"src\floatPointBlockFir.pp" \
"src\floatingPointBlockFirTest.pp" 

OBJS__QUOTED += \
"src\floatPointBlockFir.obj" \
"src\floatingPointBlockFirTest.obj" 

C_SRCS__QUOTED += \
"../src/floatPointBlockFir.c" \
"../src/floatingPointBlockFirTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPointBlockFir.obj: ../src/floatPointBlockFir.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPointBlockFir.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatingPointBlockFirTest.obj: ../src/floatingPointBlockFirTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatingPointBlockFirTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


