################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPoint_mdct.c \
../src/floatPoint_mdctIinit.c \
../src/floatPoint_mdctTtest.c 

OBJS += \
./src/floatPoint_mdct.obj \
./src/floatPoint_mdctIinit.obj \
./src/floatPoint_mdctTtest.obj 

C_DEPS += \
./src/floatPoint_mdct.pp \
./src/floatPoint_mdctIinit.pp \
./src/floatPoint_mdctTtest.pp 

C_DEPS__QUOTED += \
"src\floatPoint_mdct.pp" \
"src\floatPoint_mdctIinit.pp" \
"src\floatPoint_mdctTtest.pp" 

OBJS__QUOTED += \
"src\floatPoint_mdct.obj" \
"src\floatPoint_mdctIinit.obj" \
"src\floatPoint_mdctTtest.obj" 

C_SRCS__QUOTED += \
"../src/floatPoint_mdct.c" \
"../src/floatPoint_mdctIinit.c" \
"../src/floatPoint_mdctTtest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPoint_mdct.obj: ../src/floatPoint_mdct.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_mdct.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_mdctIinit.obj: ../src/floatPoint_mdctIinit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_mdctIinit.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_mdctTtest.obj: ../src/floatPoint_mdctTtest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_mdctTtest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


