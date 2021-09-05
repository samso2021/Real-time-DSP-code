################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPoint_dtx.c \
../src/floatPoint_dtx_mainTest.c \
../src/floatPoint_sid.c \
../src/floatPoint_vad_fft.c \
../src/floatPoint_vad_hwindow.c \
../src/floatPoint_vad_init.c \
../src/floatPoint_vad_ss.c \
../src/floatPoint_vad_vad.c \
../src/g711.c 

OBJS += \
./src/floatPoint_dtx.obj \
./src/floatPoint_dtx_mainTest.obj \
./src/floatPoint_sid.obj \
./src/floatPoint_vad_fft.obj \
./src/floatPoint_vad_hwindow.obj \
./src/floatPoint_vad_init.obj \
./src/floatPoint_vad_ss.obj \
./src/floatPoint_vad_vad.obj \
./src/g711.obj 

C_DEPS += \
./src/floatPoint_dtx.pp \
./src/floatPoint_dtx_mainTest.pp \
./src/floatPoint_sid.pp \
./src/floatPoint_vad_fft.pp \
./src/floatPoint_vad_hwindow.pp \
./src/floatPoint_vad_init.pp \
./src/floatPoint_vad_ss.pp \
./src/floatPoint_vad_vad.pp \
./src/g711.pp 

C_DEPS__QUOTED += \
"src\floatPoint_dtx.pp" \
"src\floatPoint_dtx_mainTest.pp" \
"src\floatPoint_sid.pp" \
"src\floatPoint_vad_fft.pp" \
"src\floatPoint_vad_hwindow.pp" \
"src\floatPoint_vad_init.pp" \
"src\floatPoint_vad_ss.pp" \
"src\floatPoint_vad_vad.pp" \
"src\g711.pp" 

OBJS__QUOTED += \
"src\floatPoint_dtx.obj" \
"src\floatPoint_dtx_mainTest.obj" \
"src\floatPoint_sid.obj" \
"src\floatPoint_vad_fft.obj" \
"src\floatPoint_vad_hwindow.obj" \
"src\floatPoint_vad_init.obj" \
"src\floatPoint_vad_ss.obj" \
"src\floatPoint_vad_vad.obj" \
"src\g711.obj" 

C_SRCS__QUOTED += \
"../src/floatPoint_dtx.c" \
"../src/floatPoint_dtx_mainTest.c" \
"../src/floatPoint_sid.c" \
"../src/floatPoint_vad_fft.c" \
"../src/floatPoint_vad_hwindow.c" \
"../src/floatPoint_vad_init.c" \
"../src/floatPoint_vad_ss.c" \
"../src/floatPoint_vad_vad.c" \
"../src/g711.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPoint_dtx.obj: ../src/floatPoint_dtx.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_dtx.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_dtx_mainTest.obj: ../src/floatPoint_dtx_mainTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_dtx_mainTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_sid.obj: ../src/floatPoint_sid.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_sid.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_vad_fft.obj: ../src/floatPoint_vad_fft.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_vad_fft.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_vad_hwindow.obj: ../src/floatPoint_vad_hwindow.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_vad_hwindow.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_vad_init.obj: ../src/floatPoint_vad_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_vad_init.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_vad_ss.obj: ../src/floatPoint_vad_ss.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_vad_ss.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_vad_vad.obj: ../src/floatPoint_vad_vad.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_vad_vad.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/g711.obj: ../src/g711.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/g711.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


