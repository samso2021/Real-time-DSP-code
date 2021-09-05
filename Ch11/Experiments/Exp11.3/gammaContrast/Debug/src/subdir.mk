################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gammaContrastTest.c \
../src/imageMapping.c \
../src/tableGen.c 

OBJS += \
./src/gammaContrastTest.obj \
./src/imageMapping.obj \
./src/tableGen.obj 

C_DEPS += \
./src/gammaContrastTest.pp \
./src/imageMapping.pp \
./src/tableGen.pp 

C_DEPS__QUOTED += \
"src\gammaContrastTest.pp" \
"src\imageMapping.pp" \
"src\tableGen.pp" 

OBJS__QUOTED += \
"src\gammaContrastTest.obj" \
"src\imageMapping.obj" \
"src\tableGen.obj" 

C_SRCS__QUOTED += \
"../src/gammaContrastTest.c" \
"../src/imageMapping.c" \
"../src/tableGen.c" 


# Each subdirectory must supply rules for building sources it contributes
src/gammaContrastTest.obj: ../src/gammaContrastTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/gammaContrastTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/imageMapping.obj: ../src/imageMapping.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/imageMapping.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/tableGen.obj: ../src/tableGen.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/tableGen.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


