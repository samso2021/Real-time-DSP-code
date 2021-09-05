################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/intrinsics_IIR.c \
../src/intrinsics_IIRTest.c 

OBJS += \
./src/intrinsics_IIR.obj \
./src/intrinsics_IIRTest.obj 

C_DEPS += \
./src/intrinsics_IIR.pp \
./src/intrinsics_IIRTest.pp 

C_DEPS__QUOTED += \
"src\intrinsics_IIR.pp" \
"src\intrinsics_IIRTest.pp" 

OBJS__QUOTED += \
"src\intrinsics_IIR.obj" \
"src\intrinsics_IIRTest.obj" 

C_SRCS__QUOTED += \
"../src/intrinsics_IIR.c" \
"../src/intrinsics_IIRTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/intrinsics_IIR.obj: ../src/intrinsics_IIR.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsics_IIR.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsics_IIRTest.obj: ../src/intrinsics_IIRTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsics_IIRTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


