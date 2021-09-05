################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/float_lms.c \
../src/float_lmsTest.c 

OBJS += \
./src/float_lms.obj \
./src/float_lmsTest.obj 

C_DEPS += \
./src/float_lms.pp \
./src/float_lmsTest.pp 

C_DEPS__QUOTED += \
"src\float_lms.pp" \
"src\float_lmsTest.pp" 

OBJS__QUOTED += \
"src\float_lms.obj" \
"src\float_lmsTest.obj" 

C_SRCS__QUOTED += \
"../src/float_lms.c" \
"../src/float_lmsTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/float_lms.obj: ../src/float_lms.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/float_lms.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/float_lmsTest.obj: ../src/float_lmsTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/float_lmsTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


