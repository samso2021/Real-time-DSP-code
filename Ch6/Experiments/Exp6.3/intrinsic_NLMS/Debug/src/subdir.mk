################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/intrinisc_nlmsTest.c \
../src/intrinsic_nlms.c 

OBJS += \
./src/intrinisc_nlmsTest.obj \
./src/intrinsic_nlms.obj 

C_DEPS += \
./src/intrinisc_nlmsTest.pp \
./src/intrinsic_nlms.pp 

C_DEPS__QUOTED += \
"src\intrinisc_nlmsTest.pp" \
"src\intrinsic_nlms.pp" 

OBJS__QUOTED += \
"src\intrinisc_nlmsTest.obj" \
"src\intrinsic_nlms.obj" 

C_SRCS__QUOTED += \
"../src/intrinisc_nlmsTest.c" \
"../src/intrinsic_nlms.c" 


# Each subdirectory must supply rules for building sources it contributes
src/intrinisc_nlmsTest.obj: ../src/intrinisc_nlmsTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinisc_nlmsTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_nlms.obj: ../src/intrinsic_nlms.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_nlms.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


