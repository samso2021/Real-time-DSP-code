################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/loopTest.c 

ASM_SRCS += \
../src/asmLoop.asm 

ASM_DEPS += \
./src/asmLoop.pp 

OBJS += \
./src/asmLoop.obj \
./src/loopTest.obj 

C_DEPS += \
./src/loopTest.pp 

ASM_DEPS__QUOTED += \
"src\asmLoop.pp" 

C_DEPS__QUOTED += \
"src\loopTest.pp" 

OBJS__QUOTED += \
"src\asmLoop.obj" \
"src\loopTest.obj" 

ASM_SRCS__QUOTED += \
"../src/asmLoop.asm" 

C_SRCS__QUOTED += \
"../src/loopTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/asmLoop.obj: ../src/asmLoop.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/asmLoop.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/loopTest.obj: ../src/loopTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/loopTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


