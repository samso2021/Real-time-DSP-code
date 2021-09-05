################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adaptiveEQ.c \
../src/channel.c \
../src/channel_equalizerTest.c \
../src/signalGen.c 

OBJS += \
./src/adaptiveEQ.obj \
./src/channel.obj \
./src/channel_equalizerTest.obj \
./src/signalGen.obj 

C_DEPS += \
./src/adaptiveEQ.pp \
./src/channel.pp \
./src/channel_equalizerTest.pp \
./src/signalGen.pp 

C_DEPS__QUOTED += \
"src\adaptiveEQ.pp" \
"src\channel.pp" \
"src\channel_equalizerTest.pp" \
"src\signalGen.pp" 

OBJS__QUOTED += \
"src\adaptiveEQ.obj" \
"src\channel.obj" \
"src\channel_equalizerTest.obj" \
"src\signalGen.obj" 

C_SRCS__QUOTED += \
"../src/adaptiveEQ.c" \
"../src/channel.c" \
"../src/channel_equalizerTest.c" \
"../src/signalGen.c" 


# Each subdirectory must supply rules for building sources it contributes
src/adaptiveEQ.obj: ../src/adaptiveEQ.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/adaptiveEQ.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/channel.obj: ../src/channel.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/channel.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/channel_equalizerTest.obj: ../src/channel_equalizerTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/channel_equalizerTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/signalGen.obj: ../src/signalGen.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/signalGen.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


