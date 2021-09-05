################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/initAIC3204.c \
../src/siren.c \
../src/sirenGenTest.c 

OBJS += \
./src/initAIC3204.obj \
./src/siren.obj \
./src/sirenGenTest.obj 

C_DEPS += \
./src/initAIC3204.pp \
./src/siren.pp \
./src/sirenGenTest.pp 

C_DEPS__QUOTED += \
"src\initAIC3204.pp" \
"src\siren.pp" \
"src\sirenGenTest.pp" 

OBJS__QUOTED += \
"src\initAIC3204.obj" \
"src\siren.obj" \
"src\sirenGenTest.obj" 

C_SRCS__QUOTED += \
"../src/initAIC3204.c" \
"../src/siren.c" \
"../src/sirenGenTest.c" 


# Each subdirectory must supply rules for building sources it contributes
src/initAIC3204.obj: ../src/initAIC3204.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/initAIC3204.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/siren.obj: ../src/siren.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/siren.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sirenGenTest.obj: ../src/sirenGenTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/sirenGenTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


