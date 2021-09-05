################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fast_convTest.c \
../src/intrinsic_fft.c \
../src/olap_add.c \
../src/w_table.c 

ASM_SRCS += \
../src/bit_rev.asm \
../src/freqflt.asm 

ASM_DEPS += \
./src/bit_rev.pp \
./src/freqflt.pp 

OBJS += \
./src/bit_rev.obj \
./src/fast_convTest.obj \
./src/freqflt.obj \
./src/intrinsic_fft.obj \
./src/olap_add.obj \
./src/w_table.obj 

C_DEPS += \
./src/fast_convTest.pp \
./src/intrinsic_fft.pp \
./src/olap_add.pp \
./src/w_table.pp 

ASM_DEPS__QUOTED += \
"src\bit_rev.pp" \
"src\freqflt.pp" 

C_DEPS__QUOTED += \
"src\fast_convTest.pp" \
"src\intrinsic_fft.pp" \
"src\olap_add.pp" \
"src\w_table.pp" 

OBJS__QUOTED += \
"src\bit_rev.obj" \
"src\fast_convTest.obj" \
"src\freqflt.obj" \
"src\intrinsic_fft.obj" \
"src\olap_add.obj" \
"src\w_table.obj" 

ASM_SRCS__QUOTED += \
"../src/bit_rev.asm" \
"../src/freqflt.asm" 

C_SRCS__QUOTED += \
"../src/fast_convTest.c" \
"../src/intrinsic_fft.c" \
"../src/olap_add.c" \
"../src/w_table.c" 


# Each subdirectory must supply rules for building sources it contributes
src/bit_rev.obj: ../src/bit_rev.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/bit_rev.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fast_convTest.obj: ../src/fast_convTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fast_convTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/freqflt.obj: ../src/freqflt.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/freqflt.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_fft.obj: ../src/intrinsic_fft.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_fft.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/olap_add.obj: ../src/olap_add.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/olap_add.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/w_table.obj: ../src/w_table.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/w_table.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


