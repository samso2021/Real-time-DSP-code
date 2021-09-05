################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fixPoint_leaky_lms.c \
../src/fixPoint_leaky_lmsTest.c 

OBJS += \
./src/fixPoint_leaky_lms.obj \
./src/fixPoint_leaky_lmsTest.obj 

C_DEPS += \
./src/fixPoint_leaky_lms.pp \
./src/fixPoint_leaky_lmsTest.pp 

C_DEPS__QUOTED += \
"src\fixPoint_leaky_lms.pp" \
"src\fixPoint_leaky_lmsTest.pp" 

OBJS__QUOTED += \
"src\fixPoint_leaky_lms.obj" \
"src\fixPoint_leaky_lmsTest.obj" 

C_SRCS__QUOTED += \
"../src/fixPoint_leaky_lms.c" \
"../src/fixPoint_leaky_lmsTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/fixPoint_leaky_lms.obj: ../src/fixPoint_leaky_lms.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_leaky_lms.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixPoint_leaky_lmsTest.obj: ../src/fixPoint_leaky_lmsTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_leaky_lmsTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


