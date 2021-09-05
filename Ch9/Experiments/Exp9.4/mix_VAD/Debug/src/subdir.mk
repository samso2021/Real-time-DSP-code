################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ibit_rev.c \
../src/intrinsic_fft.c \
../src/mix_VAD_mainTest.c \
../src/mixed_vad_init.c \
../src/mixed_vad_ss.c \
../src/mixed_vad_tableGen.c \
../src/mixed_vad_vad.c \
../src/mixed_vad_wtable.c 

ASM_SRCS += \
../src/dspFunc55.asm 

ASM_DEPS += \
./src/dspFunc55.pp 

OBJS += \
./src/dspFunc55.obj \
./src/ibit_rev.obj \
./src/intrinsic_fft.obj \
./src/mix_VAD_mainTest.obj \
./src/mixed_vad_init.obj \
./src/mixed_vad_ss.obj \
./src/mixed_vad_tableGen.obj \
./src/mixed_vad_vad.obj \
./src/mixed_vad_wtable.obj 

C_DEPS += \
./src/ibit_rev.pp \
./src/intrinsic_fft.pp \
./src/mix_VAD_mainTest.pp \
./src/mixed_vad_init.pp \
./src/mixed_vad_ss.pp \
./src/mixed_vad_tableGen.pp \
./src/mixed_vad_vad.pp \
./src/mixed_vad_wtable.pp 

ASM_DEPS__QUOTED += \
"src\dspFunc55.pp" 

C_DEPS__QUOTED += \
"src\ibit_rev.pp" \
"src\intrinsic_fft.pp" \
"src\mix_VAD_mainTest.pp" \
"src\mixed_vad_init.pp" \
"src\mixed_vad_ss.pp" \
"src\mixed_vad_tableGen.pp" \
"src\mixed_vad_vad.pp" \
"src\mixed_vad_wtable.pp" 

OBJS__QUOTED += \
"src\dspFunc55.obj" \
"src\ibit_rev.obj" \
"src\intrinsic_fft.obj" \
"src\mix_VAD_mainTest.obj" \
"src\mixed_vad_init.obj" \
"src\mixed_vad_ss.obj" \
"src\mixed_vad_tableGen.obj" \
"src\mixed_vad_vad.obj" \
"src\mixed_vad_wtable.obj" 

ASM_SRCS__QUOTED += \
"../src/dspFunc55.asm" 

C_SRCS__QUOTED += \
"../src/ibit_rev.c" \
"../src/intrinsic_fft.c" \
"../src/mix_VAD_mainTest.c" \
"../src/mixed_vad_init.c" \
"../src/mixed_vad_ss.c" \
"../src/mixed_vad_tableGen.c" \
"../src/mixed_vad_vad.c" \
"../src/mixed_vad_wtable.c" 


# Each subdirectory must supply rules for building sources it contributes
src/dspFunc55.obj: ../src/dspFunc55.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dspFunc55.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ibit_rev.obj: ../src/ibit_rev.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/ibit_rev.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/intrinsic_fft.obj: ../src/intrinsic_fft.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/intrinsic_fft.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mix_VAD_mainTest.obj: ../src/mix_VAD_mainTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/mix_VAD_mainTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mixed_vad_init.obj: ../src/mixed_vad_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/mixed_vad_init.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mixed_vad_ss.obj: ../src/mixed_vad_ss.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/mixed_vad_ss.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mixed_vad_tableGen.obj: ../src/mixed_vad_tableGen.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/mixed_vad_tableGen.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mixed_vad_vad.obj: ../src/mixed_vad_vad.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/mixed_vad_vad.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/mixed_vad_wtable.obj: ../src/mixed_vad_wtable.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/mixed_vad_wtable.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


