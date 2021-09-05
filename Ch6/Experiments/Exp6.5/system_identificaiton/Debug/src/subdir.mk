################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/system_identificaitonTest.c 

ASM_SRCS += \
../src/sysIdentification.asm \
../src/unknowFirFilter.asm 

ASM_DEPS += \
./src/sysIdentification.pp \
./src/unknowFirFilter.pp 

OBJS += \
./src/sysIdentification.obj \
./src/system_identificaitonTest.obj \
./src/unknowFirFilter.obj 

C_DEPS += \
./src/system_identificaitonTest.pp 

ASM_DEPS__QUOTED += \
"src\sysIdentification.pp" \
"src\unknowFirFilter.pp" 

C_DEPS__QUOTED += \
"src\system_identificaitonTest.pp" 

OBJS__QUOTED += \
"src\sysIdentification.obj" \
"src\system_identificaitonTest.obj" \
"src\unknowFirFilter.obj" 

ASM_SRCS__QUOTED += \
"../src/sysIdentification.asm" \
"../src/unknowFirFilter.asm" 

C_SRCS__QUOTED += \
"../src/system_identificaitonTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/sysIdentification.obj: ../src/sysIdentification.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/sysIdentification.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/system_identificaitonTest.obj: ../src/system_identificaitonTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/system_identificaitonTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/unknowFirFilter.obj: ../src/unknowFirFilter.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/unknowFirFilter.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


