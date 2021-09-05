################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPoint_aecNr_mainTest.c \
../src/floatPoint_aec_calc.c \
../src/floatPoint_aec_init.c \
../src/floatPoint_aec_util.c \
../src/floatPoint_nr_fft.c \
../src/floatPoint_nr_hwindow.c \
../src/floatPoint_nr_init.c \
../src/floatPoint_nr_proc.c \
../src/floatPoint_nr_ss.c \
../src/floatPoint_nr_vad.c 

OBJS += \
./src/floatPoint_aecNr_mainTest.obj \
./src/floatPoint_aec_calc.obj \
./src/floatPoint_aec_init.obj \
./src/floatPoint_aec_util.obj \
./src/floatPoint_nr_fft.obj \
./src/floatPoint_nr_hwindow.obj \
./src/floatPoint_nr_init.obj \
./src/floatPoint_nr_proc.obj \
./src/floatPoint_nr_ss.obj \
./src/floatPoint_nr_vad.obj 

C_DEPS += \
./src/floatPoint_aecNr_mainTest.pp \
./src/floatPoint_aec_calc.pp \
./src/floatPoint_aec_init.pp \
./src/floatPoint_aec_util.pp \
./src/floatPoint_nr_fft.pp \
./src/floatPoint_nr_hwindow.pp \
./src/floatPoint_nr_init.pp \
./src/floatPoint_nr_proc.pp \
./src/floatPoint_nr_ss.pp \
./src/floatPoint_nr_vad.pp 

C_DEPS__QUOTED += \
"src\floatPoint_aecNr_mainTest.pp" \
"src\floatPoint_aec_calc.pp" \
"src\floatPoint_aec_init.pp" \
"src\floatPoint_aec_util.pp" \
"src\floatPoint_nr_fft.pp" \
"src\floatPoint_nr_hwindow.pp" \
"src\floatPoint_nr_init.pp" \
"src\floatPoint_nr_proc.pp" \
"src\floatPoint_nr_ss.pp" \
"src\floatPoint_nr_vad.pp" 

OBJS__QUOTED += \
"src\floatPoint_aecNr_mainTest.obj" \
"src\floatPoint_aec_calc.obj" \
"src\floatPoint_aec_init.obj" \
"src\floatPoint_aec_util.obj" \
"src\floatPoint_nr_fft.obj" \
"src\floatPoint_nr_hwindow.obj" \
"src\floatPoint_nr_init.obj" \
"src\floatPoint_nr_proc.obj" \
"src\floatPoint_nr_ss.obj" \
"src\floatPoint_nr_vad.obj" 

C_SRCS__QUOTED += \
"../src/floatPoint_aecNr_mainTest.c" \
"../src/floatPoint_aec_calc.c" \
"../src/floatPoint_aec_init.c" \
"../src/floatPoint_aec_util.c" \
"../src/floatPoint_nr_fft.c" \
"../src/floatPoint_nr_hwindow.c" \
"../src/floatPoint_nr_init.c" \
"../src/floatPoint_nr_proc.c" \
"../src/floatPoint_nr_ss.c" \
"../src/floatPoint_nr_vad.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPoint_aecNr_mainTest.obj: ../src/floatPoint_aecNr_mainTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_aecNr_mainTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_aec_calc.obj: ../src/floatPoint_aec_calc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_aec_calc.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_aec_init.obj: ../src/floatPoint_aec_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_aec_init.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_aec_util.obj: ../src/floatPoint_aec_util.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_aec_util.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_nr_fft.obj: ../src/floatPoint_nr_fft.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_nr_fft.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_nr_hwindow.obj: ../src/floatPoint_nr_hwindow.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_nr_hwindow.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_nr_init.obj: ../src/floatPoint_nr_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_nr_init.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_nr_proc.obj: ../src/floatPoint_nr_proc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_nr_proc.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_nr_ss.obj: ../src/floatPoint_nr_ss.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_nr_ss.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_nr_vad.obj: ../src/floatPoint_nr_vad.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_nr_vad.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


