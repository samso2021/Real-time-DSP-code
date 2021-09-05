################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fAecCalc.c \
../src/fAecInit.c \
../src/fAecTest.c \
../src/fAecUtil.c 

OBJS += \
./src/fAecCalc.obj \
./src/fAecInit.obj \
./src/fAecTest.obj \
./src/fAecUtil.obj 

C_DEPS += \
./src/fAecCalc.pp \
./src/fAecInit.pp \
./src/fAecTest.pp \
./src/fAecUtil.pp 

C_DEPS__QUOTED += \
"src\fAecCalc.pp" \
"src\fAecInit.pp" \
"src\fAecTest.pp" \
"src\fAecUtil.pp" 

OBJS__QUOTED += \
"src\fAecCalc.obj" \
"src\fAecInit.obj" \
"src\fAecTest.obj" \
"src\fAecUtil.obj" 

C_SRCS__QUOTED += \
"../src/fAecCalc.c" \
"../src/fAecInit.c" \
"../src/fAecTest.c" \
"../src/fAecUtil.c" 


# Each subdirectory must supply rules for building sources it contributes
src/fAecCalc.obj: ../src/fAecCalc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fAecCalc.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fAecInit.obj: ../src/fAecInit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fAecInit.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fAecTest.obj: ../src/fAecTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fAecTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fAecUtil.obj: ../src/fAecUtil.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fAecUtil.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


