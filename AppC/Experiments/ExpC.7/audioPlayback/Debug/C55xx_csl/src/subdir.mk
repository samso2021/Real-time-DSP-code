################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../C55xx_csl/src/csl_dma.c \
../C55xx_csl/src/csl_gpio.c \
../C55xx_csl/src/csl_gpt.c \
../C55xx_csl/src/csl_i2c.c \
../C55xx_csl/src/csl_i2s.c \
../C55xx_csl/src/csl_intc.c \
../C55xx_csl/src/csl_pll.c \
../C55xx_csl/src/csl_rtc.c 

OBJS += \
./C55xx_csl/src/csl_dma.obj \
./C55xx_csl/src/csl_gpio.obj \
./C55xx_csl/src/csl_gpt.obj \
./C55xx_csl/src/csl_i2c.obj \
./C55xx_csl/src/csl_i2s.obj \
./C55xx_csl/src/csl_intc.obj \
./C55xx_csl/src/csl_pll.obj \
./C55xx_csl/src/csl_rtc.obj 

C_DEPS += \
./C55xx_csl/src/csl_dma.pp \
./C55xx_csl/src/csl_gpio.pp \
./C55xx_csl/src/csl_gpt.pp \
./C55xx_csl/src/csl_i2c.pp \
./C55xx_csl/src/csl_i2s.pp \
./C55xx_csl/src/csl_intc.pp \
./C55xx_csl/src/csl_pll.pp \
./C55xx_csl/src/csl_rtc.pp 

C_DEPS__QUOTED += \
"C55xx_csl\src\csl_dma.pp" \
"C55xx_csl\src\csl_gpio.pp" \
"C55xx_csl\src\csl_gpt.pp" \
"C55xx_csl\src\csl_i2c.pp" \
"C55xx_csl\src\csl_i2s.pp" \
"C55xx_csl\src\csl_intc.pp" \
"C55xx_csl\src\csl_pll.pp" \
"C55xx_csl\src\csl_rtc.pp" 

OBJS__QUOTED += \
"C55xx_csl\src\csl_dma.obj" \
"C55xx_csl\src\csl_gpio.obj" \
"C55xx_csl\src\csl_gpt.obj" \
"C55xx_csl\src\csl_i2c.obj" \
"C55xx_csl\src\csl_i2s.obj" \
"C55xx_csl\src\csl_intc.obj" \
"C55xx_csl\src\csl_pll.obj" \
"C55xx_csl\src\csl_rtc.obj" 

C_SRCS__QUOTED += \
"../C55xx_csl/src/csl_dma.c" \
"../C55xx_csl/src/csl_gpio.c" \
"../C55xx_csl/src/csl_gpt.c" \
"../C55xx_csl/src/csl_i2c.c" \
"../C55xx_csl/src/csl_i2s.c" \
"../C55xx_csl/src/csl_intc.c" \
"../C55xx_csl/src/csl_pll.c" \
"../C55xx_csl/src/csl_rtc.c" 


# Each subdirectory must supply rules for building sources it contributes
C55xx_csl/src/csl_dma.obj: ../C55xx_csl/src/csl_dma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_dma.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_gpio.obj: ../C55xx_csl/src/csl_gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_gpio.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_gpt.obj: ../C55xx_csl/src/csl_gpt.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_gpt.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_i2c.obj: ../C55xx_csl/src/csl_i2c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_i2c.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_i2s.obj: ../C55xx_csl/src/csl_i2s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_i2s.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_intc.obj: ../C55xx_csl/src/csl_intc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_intc.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_pll.obj: ../C55xx_csl/src/csl_pll.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_pll.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

C55xx_csl/src/csl_rtc.obj: ../C55xx_csl/src/csl_rtc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="C55xx_csl/src/csl_rtc.pp" --obj_directory="C55xx_csl/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


