################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DCTcoefGen.c \
../src/RGB2BMPHeader.c \
../src/YCbCr2RGB.c \
../src/dctTest.c 

ASM_SRCS += \
../src/DCT.asm \
../src/IDCT.asm 

ASM_DEPS += \
./src/DCT.pp \
./src/IDCT.pp 

OBJS += \
./src/DCT.obj \
./src/DCTcoefGen.obj \
./src/IDCT.obj \
./src/RGB2BMPHeader.obj \
./src/YCbCr2RGB.obj \
./src/dctTest.obj 

C_DEPS += \
./src/DCTcoefGen.pp \
./src/RGB2BMPHeader.pp \
./src/YCbCr2RGB.pp \
./src/dctTest.pp 

ASM_DEPS__QUOTED += \
"src\DCT.pp" \
"src\IDCT.pp" 

C_DEPS__QUOTED += \
"src\DCTcoefGen.pp" \
"src\RGB2BMPHeader.pp" \
"src\YCbCr2RGB.pp" \
"src\dctTest.pp" 

OBJS__QUOTED += \
"src\DCT.obj" \
"src\DCTcoefGen.obj" \
"src\IDCT.obj" \
"src\RGB2BMPHeader.obj" \
"src\YCbCr2RGB.obj" \
"src\dctTest.obj" 

ASM_SRCS__QUOTED += \
"../src/DCT.asm" \
"../src/IDCT.asm" 

C_SRCS__QUOTED += \
"../src/DCTcoefGen.c" \
"../src/RGB2BMPHeader.c" \
"../src/YCbCr2RGB.c" \
"../src/dctTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/DCT.obj: ../src/DCT.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/DCT.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/DCTcoefGen.obj: ../src/DCTcoefGen.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/DCTcoefGen.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/IDCT.obj: ../src/IDCT.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/IDCT.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/RGB2BMPHeader.obj: ../src/RGB2BMPHeader.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/RGB2BMPHeader.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/YCbCr2RGB.obj: ../src/YCbCr2RGB.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/YCbCr2RGB.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dctTest.obj: ../src/dctTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dctTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


