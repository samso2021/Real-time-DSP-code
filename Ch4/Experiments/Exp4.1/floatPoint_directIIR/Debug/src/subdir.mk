################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPoint_directIIR.c \
../src/floatPoint_directIIRTest.c 

OBJS += \
./src/floatPoint_directIIR.obj \
./src/floatPoint_directIIRTest.obj 

C_DEPS += \
./src/floatPoint_directIIR.pp \
./src/floatPoint_directIIRTest.pp 

C_DEPS__QUOTED += \
"src\floatPoint_directIIR.pp" \
"src\floatPoint_directIIRTest.pp" 

OBJS__QUOTED += \
"src\floatPoint_directIIR.obj" \
"src\floatPoint_directIIRTest.obj" 

C_SRCS__QUOTED += \
"../src/floatPoint_directIIR.c" \
"../src/floatPoint_directIIRTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPoint_directIIR.obj: ../src/floatPoint_directIIR.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_directIIR.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_directIIRTest.obj: ../src/floatPoint_directIIRTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_directIIRTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


