################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fixPoint_cascadeIIRTest.c \
../src/fixPoint_cascadetIIR.c 

OBJS += \
./src/fixPoint_cascadeIIRTest.obj \
./src/fixPoint_cascadetIIR.obj 

C_DEPS += \
./src/fixPoint_cascadeIIRTest.pp \
./src/fixPoint_cascadetIIR.pp 

C_DEPS__QUOTED += \
"src\fixPoint_cascadeIIRTest.pp" \
"src\fixPoint_cascadetIIR.pp" 

OBJS__QUOTED += \
"src\fixPoint_cascadeIIRTest.obj" \
"src\fixPoint_cascadetIIR.obj" 

C_SRCS__QUOTED += \
"../src/fixPoint_cascadeIIRTest.c" \
"../src/fixPoint_cascadetIIR.c" 


# Each subdirectory must supply rules for building sources it contributes
src/fixPoint_cascadeIIRTest.obj: ../src/fixPoint_cascadeIIRTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_cascadeIIRTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixPoint_cascadetIIR.obj: ../src/fixPoint_cascadetIIR.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_cascadetIIR.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


