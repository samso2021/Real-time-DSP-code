################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/floatPoint_preEchoInit.c \
../src/floatPoint_preEchoMdct.c \
../src/floatPoint_preEchoQnt.c \
../src/floatPoint_preEchoTest.c 

OBJS += \
./src/floatPoint_preEchoInit.obj \
./src/floatPoint_preEchoMdct.obj \
./src/floatPoint_preEchoQnt.obj \
./src/floatPoint_preEchoTest.obj 

C_DEPS += \
./src/floatPoint_preEchoInit.pp \
./src/floatPoint_preEchoMdct.pp \
./src/floatPoint_preEchoQnt.pp \
./src/floatPoint_preEchoTest.pp 

C_DEPS__QUOTED += \
"src\floatPoint_preEchoInit.pp" \
"src\floatPoint_preEchoMdct.pp" \
"src\floatPoint_preEchoQnt.pp" \
"src\floatPoint_preEchoTest.pp" 

OBJS__QUOTED += \
"src\floatPoint_preEchoInit.obj" \
"src\floatPoint_preEchoMdct.obj" \
"src\floatPoint_preEchoQnt.obj" \
"src\floatPoint_preEchoTest.obj" 

C_SRCS__QUOTED += \
"../src/floatPoint_preEchoInit.c" \
"../src/floatPoint_preEchoMdct.c" \
"../src/floatPoint_preEchoQnt.c" \
"../src/floatPoint_preEchoTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/floatPoint_preEchoInit.obj: ../src/floatPoint_preEchoInit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_preEchoInit.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_preEchoMdct.obj: ../src/floatPoint_preEchoMdct.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_preEchoMdct.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_preEchoQnt.obj: ../src/floatPoint_preEchoQnt.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_preEchoQnt.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/floatPoint_preEchoTest.obj: ../src/floatPoint_preEchoTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/floatPoint_preEchoTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


