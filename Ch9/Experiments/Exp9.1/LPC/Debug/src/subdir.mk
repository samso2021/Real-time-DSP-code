################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/intrinsic_lpc_auto.c \
../src/intrinsic_lpc_hamTable.c \
../src/intrinsic_lpc_hamming.c \
../src/intrinsic_lpc_lpc.c \
../src/intrinsic_lpc_mainTest.c 

OBJS += \
./src/intrinsic_lpc_auto.obj \
./src/intrinsic_lpc_hamTable.obj \
./src/intrinsic_lpc_hamming.obj \
./src/intrinsic_lpc_lpc.obj \
./src/intrinsic_lpc_mainTest.obj 

C_DEPS += \
./src/intrinsic_lpc_auto.pp \
./src/intrinsic_lpc_hamTable.pp \
./src/intrinsic_lpc_hamming.pp \
./src/intrinsic_lpc_lpc.pp \
./src/intrinsic_lpc_mainTest.pp 

C_DEPS__QUOTED += \
"src\intrinsic_lpc_auto.pp" \
"src\intrinsic_lpc_hamTable.pp" \
"src\intrinsic_lpc_hamming.pp" \
"src\intrinsic_lpc_lpc.pp" \
"src\intrinsic_lpc_mainTest.pp" 

OBJS__QUOTED += \
"src\intrinsic_lpc_auto.obj" \
"src\intrinsic_lpc_hamTable.obj" \
"src\intrinsic_lpc_hamming.obj" \
"src\intrinsic_lpc_lpc.obj" \
"src\intrinsic_lpc_mainTest.obj" 

C_SRCS__QUOTED += \
"../src/intrinsic_lpc_auto.c" \
"../src/intrinsic_lpc_hamTable.c" \
"../src/intrinsic_lpc_hamming.c" \
"../src/intrinsic_lpc_lpc.c" \
"../src/intrinsic_lpc_mainTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/intrinsic_lpc_auto.obj: ../src/intrinsic_lpc_auto.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_lpc_auto.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_lpc_hamTable.obj: ../src/intrinsic_lpc_hamTable.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_lpc_hamTable.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_lpc_hamming.obj: ../src/intrinsic_lpc_hamming.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_lpc_hamming.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_lpc_lpc.obj: ../src/intrinsic_lpc_lpc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_lpc_lpc.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_lpc_mainTest.obj: ../src/intrinsic_lpc_mainTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_lpc_mainTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


