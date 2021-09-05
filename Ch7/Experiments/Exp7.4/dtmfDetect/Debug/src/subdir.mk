################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/checkKey.c \
../src/computeOutput.c \
../src/dtmfDecodeTest.c \
../src/dtmfFreq.c \
../src/gFilter.c \
../src/gFreqDetect.c \
../src/init.c 

OBJS += \
./src/checkKey.obj \
./src/computeOutput.obj \
./src/dtmfDecodeTest.obj \
./src/dtmfFreq.obj \
./src/gFilter.obj \
./src/gFreqDetect.obj \
./src/init.obj 

C_DEPS += \
./src/checkKey.pp \
./src/computeOutput.pp \
./src/dtmfDecodeTest.pp \
./src/dtmfFreq.pp \
./src/gFilter.pp \
./src/gFreqDetect.pp \
./src/init.pp 

C_DEPS__QUOTED += \
"src\checkKey.pp" \
"src\computeOutput.pp" \
"src\dtmfDecodeTest.pp" \
"src\dtmfFreq.pp" \
"src\gFilter.pp" \
"src\gFreqDetect.pp" \
"src\init.pp" 

OBJS__QUOTED += \
"src\checkKey.obj" \
"src\computeOutput.obj" \
"src\dtmfDecodeTest.obj" \
"src\dtmfFreq.obj" \
"src\gFilter.obj" \
"src\gFreqDetect.obj" \
"src\init.obj" 

C_SRCS__QUOTED += \
"../src/checkKey.c" \
"../src/computeOutput.c" \
"../src/dtmfDecodeTest.c" \
"../src/dtmfFreq.c" \
"../src/gFilter.c" \
"../src/gFreqDetect.c" \
"../src/init.c" 


# Each subdirectory must supply rules for building sources it contributes
src/checkKey.obj: ../src/checkKey.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/checkKey.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/computeOutput.obj: ../src/computeOutput.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/computeOutput.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dtmfDecodeTest.obj: ../src/dtmfDecodeTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dtmfDecodeTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dtmfFreq.obj: ../src/dtmfFreq.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dtmfFreq.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/gFilter.obj: ../src/gFilter.c $(GEN_OPTS) $(GEN_SRCS)
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


