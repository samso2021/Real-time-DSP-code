################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPointFir.c \
../src/floatingPointFirTest.c 

OBJS += \
./src/floatPointFir.obj \
./src/floatingPointFirTest.obj 

C_DEPS += \
./src/floatPointFir.pp \
./src/floatingPointFirTest.pp 

C_DEPS__QUOTED += \
"src\floatPointFir.pp" \
"src\floatingPointFirTest.pp" 

OBJS__QUOTED += \
"src\floatPointFir.obj" \
"src\floatingPointFirTest.obj" 

C_SRCS__QUOTED += \
"../src/floatPointFir.c" \
"../src/floatingPointFirTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPointFir.obj: ../src/floatPointFir.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPointFir.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatingPointFirTest.obj: ../src/floatingPointFirTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatingPointFirTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


