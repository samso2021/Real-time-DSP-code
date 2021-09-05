################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dtmfGenTest.c \
../src/dtmfTone.c \
../src/initAIC3204.c 

OBJS += \
./src/dtmfGenTest.obj \
./src/dtmfTone.obj \
./src/initAIC3204.obj 

C_DEPS += \
./src/dtmfGenTest.pp \
./src/dtmfTone.pp \
./src/initAIC3204.pp 

C_DEPS__QUOTED += \
"src\dtmfGenTest.pp" \
"src\dtmfTone.pp" \
"src\initAIC3204.pp" 

OBJS__QUOTED += \
"src\dtmfGenTest.obj" \
"src\dtmfTone.obj" \
"src\initAIC3204.obj" 

C_SRCS__QUOTED += \
"../src/dtmfGenTest.c" \
"../src/dtmfTone.c" \
"../src/initAIC3204.c" 


# Each subdirectory must supply rules for building sources it contributes
src/dtmfGenTest.obj: ../src/dtmfGenTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dtmfGenTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dtmfTone.obj: ../src/dtmfTone.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/dtmfTone.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/initAIC3204.obj: ../src/initAIC3204.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/initAIC3204.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


