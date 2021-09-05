################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fixedPointBlockFir.c \
../src/fixedPointBlockFirTest.c 

OBJS += \
./src/fixedPointBlockFir.obj \
./src/fixedPointBlockFirTest.obj 

C_DEPS += \
./src/fixedPointBlockFir.pp \
./src/fixedPointBlockFirTest.pp 

C_DEPS__QUOTED += \
"src\fixedPointBlockFir.pp" \
"src\fixedPointBlockFirTest.pp" 

OBJS__QUOTED += \
"src\fixedPointBlockFir.obj" \
"src\fixedPointBlockFirTest.obj" 

C_SRCS__QUOTED += \
"../src/fixedPointBlockFir.c" \
"../src/fixedPointBlockFirTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/fixedPointBlockFir.obj: ../src/fixedPointBlockFir.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixedPointBlockFir.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixedPointBlockFirTest.obj: ../src/fixedPointBlockFirTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixedPointBlockFirTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


