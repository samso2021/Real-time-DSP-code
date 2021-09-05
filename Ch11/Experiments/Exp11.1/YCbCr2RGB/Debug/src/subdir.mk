################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/RGB2BMPHeader.c \
../src/YCbCr2RGB.c \
../src/YCbCr2RGBTest.c 

OBJS += \
./src/RGB2BMPHeader.obj \
./src/YCbCr2RGB.obj \
./src/YCbCr2RGBTest.obj 

C_DEPS += \
./src/RGB2BMPHeader.pp \
./src/YCbCr2RGB.pp \
./src/YCbCr2RGBTest.pp 

C_DEPS__QUOTED += \
"src\RGB2BMPHeader.pp" \
"src\YCbCr2RGB.pp" \
"src\YCbCr2RGBTest.pp" 

OBJS__QUOTED += \
"src\RGB2BMPHeader.obj" \
"src\YCbCr2RGB.obj" \
"src\YCbCr2RGBTest.obj" 

C_SRCS__QUOTED += \
"../src/RGB2BMPHeader.c" \
"../src/YCbCr2RGB.c" \
"../src/YCbCr2RGBTest.c" 


# Each subdirectory must supply rules for building sources it contributes
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

src/YCbCr2RGBTest.obj: ../src/YCbCr2RGBTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/YCbCr2RGBTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


