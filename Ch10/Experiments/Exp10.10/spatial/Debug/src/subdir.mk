################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/spatialSound.c \
../src/spatialTest.c 

OBJS += \
./src/spatialSound.obj \
./src/spatialTest.obj 

C_DEPS += \
./src/spatialSound.pp \
./src/spatialTest.pp 

C_DEPS__QUOTED += \
"src\spatialSound.pp" \
"src\spatialTest.pp" 

OBJS__QUOTED += \
"src\spatialSound.obj" \
"src\spatialTest.obj" 

C_SRCS__QUOTED += \
"../src/spatialSound.c" \
"../src/spatialTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/spatialSound.obj: ../src/spatialSound.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/spatialSound.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/spatialTest.obj: ../src/spatialTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/spatialTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


