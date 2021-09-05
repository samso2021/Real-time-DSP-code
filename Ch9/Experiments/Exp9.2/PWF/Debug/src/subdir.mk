################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/intrinsic_pwf_auto.c \
../src/intrinsic_pwf_hamTable.c \
../src/intrinsic_pwf_hamming.c \
../src/intrinsic_pwf_lpc.c \
../src/intrinsic_pwf_mainTest.c \
../src/intrinsic_pwf_wz.c 

OBJS += \
./src/intrinsic_pwf_auto.obj \
./src/intrinsic_pwf_hamTable.obj \
./src/intrinsic_pwf_hamming.obj \
./src/intrinsic_pwf_lpc.obj \
./src/intrinsic_pwf_mainTest.obj \
./src/intrinsic_pwf_wz.obj 

C_DEPS += \
./src/intrinsic_pwf_auto.pp \
./src/intrinsic_pwf_hamTable.pp \
./src/intrinsic_pwf_hamming.pp \
./src/intrinsic_pwf_lpc.pp \
./src/intrinsic_pwf_mainTest.pp \
./src/intrinsic_pwf_wz.pp 

C_DEPS__QUOTED += \
"src\intrinsic_pwf_auto.pp" \
"src\intrinsic_pwf_hamTable.pp" \
"src\intrinsic_pwf_hamming.pp" \
"src\intrinsic_pwf_lpc.pp" \
"src\intrinsic_pwf_mainTest.pp" \
"src\intrinsic_pwf_wz.pp" 

OBJS__QUOTED += \
"src\intrinsic_pwf_auto.obj" \
"src\intrinsic_pwf_hamTable.obj" \
"src\intrinsic_pwf_hamming.obj" \
"src\intrinsic_pwf_lpc.obj" \
"src\intrinsic_pwf_mainTest.obj" \
"src\intrinsic_pwf_wz.obj" 

C_SRCS__QUOTED += \
"../src/intrinsic_pwf_auto.c" \
"../src/intrinsic_pwf_hamTable.c" \
"../src/intrinsic_pwf_hamming.c" \
"../src/intrinsic_pwf_lpc.c" \
"../src/intrinsic_pwf_mainTest.c" \
"../src/intrinsic_pwf_wz.c" 


# Each subdirectory must supply rules for building sources it contributes
src/intrinsic_pwf_auto.obj: ../src/intrinsic_pwf_auto.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_pwf_auto.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_pwf_hamTable.obj: ../src/intrinsic_pwf_hamTable.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_pwf_hamTable.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_pwf_hamming.obj: ../src/intrinsic_pwf_hamming.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_pwf_hamming.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_pwf_lpc.obj: ../src/intrinsic_pwf_lpc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_pwf_lpc.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_pwf_mainTest.obj: ../src/intrinsic_pwf_mainTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_pwf_mainTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_pwf_wz.obj: ../src/intrinsic_pwf_wz.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_pwf_wz.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


