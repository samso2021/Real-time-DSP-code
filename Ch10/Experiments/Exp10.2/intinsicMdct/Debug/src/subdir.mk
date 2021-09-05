################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/intrinsic_mdct.c \
../src/intrinsic_mdctInit.c \
../src/intrinsic_mdctTest.c 

OBJS += \
./src/intrinsic_mdct.obj \
./src/intrinsic_mdctInit.obj \
./src/intrinsic_mdctTest.obj 

C_DEPS += \
./src/intrinsic_mdct.pp \
./src/intrinsic_mdctInit.pp \
./src/intrinsic_mdctTest.pp 

C_DEPS__QUOTED += \
"src\intrinsic_mdct.pp" \
"src\intrinsic_mdctInit.pp" \
"src\intrinsic_mdctTest.pp" 

OBJS__QUOTED += \
"src\intrinsic_mdct.obj" \
"src\intrinsic_mdctInit.obj" \
"src\intrinsic_mdctTest.obj" 

C_SRCS__QUOTED += \
"../src/intrinsic_mdct.c" \
"../src/intrinsic_mdctInit.c" \
"../src/intrinsic_mdctTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/intrinsic_mdct.obj: ../src/intrinsic_mdct.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_mdct.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_mdctInit.obj: ../src/intrinsic_mdctInit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_mdctInit.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_mdctTest.obj: ../src/intrinsic_mdctTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_mdctTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


