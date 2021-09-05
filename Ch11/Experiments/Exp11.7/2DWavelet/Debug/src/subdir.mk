################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2DWavelet.c \
../src/2DWaveletTest.c \
../src/RGB2BMPHeader.c \
../src/YCbCr2RGB.c 

ASM_SRCS += \
../src/col2rowmn.asm \
../src/decInplcemn.asm \
../src/decomColmn.asm \
../src/interColmn.asm \
../src/recInplcemn.asm \
../src/reconColmn.asm 

ASM_DEPS += \
./src/col2rowmn.pp \
./src/decInplcemn.pp \
./src/decomColmn.pp \
./src/interColmn.pp \
./src/recInplcemn.pp \
./src/reconColmn.pp 

OBJS += \
./src/2DWavelet.obj \
./src/2DWaveletTest.obj \
./src/RGB2BMPHeader.obj \
./src/YCbCr2RGB.obj \
./src/col2rowmn.obj \
./src/decInplcemn.obj \
./src/decomColmn.obj \
./src/interColmn.obj \
./src/recInplcemn.obj \
./src/reconColmn.obj 

C_DEPS += \
./src/2DWavelet.pp \
./src/2DWaveletTest.pp \
./src/RGB2BMPHeader.pp \
./src/YCbCr2RGB.pp 

ASM_DEPS__QUOTED += \
"src\col2rowmn.pp" \
"src\decInplcemn.pp" \
"src\decomColmn.pp" \
"src\interColmn.pp" \
"src\recInplcemn.pp" \
"src\reconColmn.pp" 

C_DEPS__QUOTED += \
"src\2DWavelet.pp" \
"src\2DWaveletTest.pp" \
"src\RGB2BMPHeader.pp" \
"src\YCbCr2RGB.pp" 

OBJS__QUOTED += \
"src\2DWavelet.obj" \
"src\2DWaveletTest.obj" \
"src\RGB2BMPHeader.obj" \
"src\YCbCr2RGB.obj" \
"src\col2rowmn.obj" \
"src\decInplcemn.obj" \
"src\decomColmn.obj" \
"src\interColmn.obj" \
"src\recInplcemn.obj" \
"src\reconColmn.obj" 

C_SRCS__QUOTED += \
"../src/2DWavelet.c" \
"../src/2DWaveletTest.c" \
"../src/RGB2BMPHeader.c" \
"../src/YCbCr2RGB.c" 

ASM_SRCS__QUOTED += \
"../src/col2rowmn.asm" \
"../src/decInplcemn.asm" \
"../src/decomColmn.asm" \
"../src/interColmn.asm" \
"../src/recInplcemn.asm" \
"../src/reconColmn.asm" 


# Each subdirectory must supply rules for building sources it contributes
src/2DWavelet.obj: ../src/2DWavelet.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/2DWavelet.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/2DWaveletTest.obj: ../src/2DWaveletTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/2DWaveletTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RGB2BMPHeader.obj: ../src/RGB2BMPHeader.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/RGB2BMPHeader.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/YCbCr2RGB.obj: ../src/YCbCr2RGB.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/YCbCr2RGB.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/col2rowmn.obj: ../src/col2rowmn.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/col2rowmn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/decInplcemn.obj: ../src/decInplcemn.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/decInplcemn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/decomColmn.obj: ../src/decomColmn.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/decomColmn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/interColmn.obj: ../src/interColmn.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/interColmn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/recInplcemn.obj: ../src/recInplcemn.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/recInplcemn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/reconColmn.obj: ../src/reconColmn.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="src/reconColmn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


