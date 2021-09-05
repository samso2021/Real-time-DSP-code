################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/asmDTMFDetTest.c \
../src/checkKey.c \
../src/gFreqDetect.c \
../src/init.c 

ASM_SRCS += \
../src/computeOutput.asm \
../src/dtmfFreq.asm \
../src/gFilter.asm 

ASM_DEPS += \
./src/computeOutput.pp \
./src/dtmfFreq.pp \
./src/gFilter.pp 

OBJS += \
./src/asmDTMFDetTest.obj \
./src/checkKey.obj \
./src/computeOutput.obj \
./src/dtmfFreq.obj \
./src/gFilter.obj \
./src/gFreqDetect.obj \
./src/init.obj 

C_DEPS += \
./src/asmDTMFDetTest.pp \
./src/checkKey.pp \
./src/gFreqDetect.pp \
./src/init.pp 

ASM_DEPS__QUOTED += \
"src\computeOutput.pp" \
"src\dtmfFreq.pp" \
"src\gFilter.pp" 

C_DEPS__QUOTED += \
"src\asmDTMFDetTest.pp" \
"src\checkKey.pp" \
"src\gFreqDetect.pp" \
"src\init.pp" 

OBJS__QUOTED += \
"src\asmDTMFDetTest.obj" \
"src\checkKey.obj" \
"src\computeOutput.obj" \
"src\dtmfFreq.obj" \
"src\gFilter.obj" \
"src\gFreqDetect.obj" \
"src\init.obj" 

C_SRCS__QUOTED += \
"../src/asmDTMFDetTest.c" \
"../src/checkKey.c" \
"../src/gFreqDetect.c" \
"../src/init.c" 

ASM_SRCS__QUOTED += \
"../src/computeOutput.asm" \
"../src/dtmfFreq.asm" \
"../src/gFilter.asm" 


# Each subdirectory must supply rules for building sources it contributes
src/asmDTMFDetTest.obj: ../src/asmDTMFDetTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/asmDTMFDetTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/checkKey.obj: ../src/checkKey.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/checkKey.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/computeOutput.obj: ../src/computeOutput.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/computeOutput.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dtmfFreq.obj: ../src/dtmfFreq.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dtmfFreq.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/gFilter.obj: ../src/gFilter.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/gFilter.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/gFreqDetect.obj: ../src/gFreqDetect.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/gFreqDetect.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/init.obj: ../src/init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/init.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


