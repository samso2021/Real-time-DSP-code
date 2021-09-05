################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USBSTK_bsl/bsl/usbstk5505.c \
../USBSTK_bsl/bsl/usbstk5505_gpio.c \
../USBSTK_bsl/bsl/usbstk5505_i2c.c \
../USBSTK_bsl/bsl/usbstk5505_i2s.c \
../USBSTK_bsl/bsl/usbstk5505_led.c 

OBJS += \
./USBSTK_bsl/bsl/usbstk5505.obj \
./USBSTK_bsl/bsl/usbstk5505_gpio.obj \
./USBSTK_bsl/bsl/usbstk5505_i2c.obj \
./USBSTK_bsl/bsl/usbstk5505_i2s.obj \
./USBSTK_bsl/bsl/usbstk5505_led.obj 

C_DEPS += \
./USBSTK_bsl/bsl/usbstk5505.pp \
./USBSTK_bsl/bsl/usbstk5505_gpio.pp \
./USBSTK_bsl/bsl/usbstk5505_i2c.pp \
./USBSTK_bsl/bsl/usbstk5505_i2s.pp \
./USBSTK_bsl/bsl/usbstk5505_led.pp 

C_DEPS__QUOTED += \
"USBSTK_bsl\bsl\usbstk5505.pp" \
"USBSTK_bsl\bsl\usbstk5505_gpio.pp" \
"USBSTK_bsl\bsl\usbstk5505_i2c.pp" \
"USBSTK_bsl\bsl\usbstk5505_i2s.pp" \
"USBSTK_bsl\bsl\usbstk5505_led.pp" 

OBJS__QUOTED += \
"USBSTK_bsl\bsl\usbstk5505.obj" \
"USBSTK_bsl\bsl\usbstk5505_gpio.obj" \
"USBSTK_bsl\bsl\usbstk5505_i2c.obj" \
"USBSTK_bsl\bsl\usbstk5505_i2s.obj" \
"USBSTK_bsl\bsl\usbstk5505_led.obj" 

C_SRCS__QUOTED += \
"../USBSTK_bsl/bsl/usbstk5505.c" \
"../USBSTK_bsl/bsl/usbstk5505_gpio.c" \
"../USBSTK_bsl/bsl/usbstk5505_i2c.c" \
"../USBSTK_bsl/bsl/usbstk5505_i2s.c" \
"../USBSTK_bsl/bsl/usbstk5505_led.c" 


# Each subdirectory must supply rules for building sources it contributes
USBSTK_bsl/bsl/usbstk5505.obj: ../USBSTK_bsl/bsl/usbstk5505.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="USBSTK_bsl/bsl/usbstk5505.pp" --obj_directory="USBSTK_bsl/bsl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

USBSTK_bsl/bsl/usbstk5505_gpio.obj: ../USBSTK_bsl/bsl/usbstk5505_gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="USBSTK_bsl/bsl/usbstk5505_gpio.pp" --obj_directory="USBSTK_bsl/bsl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

USBSTK_bsl/bsl/usbstk5505_i2c.obj: ../USBSTK_bsl/bsl/usbstk5505_i2c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="USBSTK_bsl/bsl/usbstk5505_i2c.pp" --obj_directory="USBSTK_bsl/bsl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

USBSTK_bsl/bsl/usbstk5505_i2s.obj: ../USBSTK_bsl/bsl/usbstk5505_i2s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="USBSTK_bsl/bsl/usbstk5505_i2s.pp" --obj_directory="USBSTK_bsl/bsl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

USBSTK_bsl/bsl/usbstk5505_led.obj: ../USBSTK_bsl/bsl/usbstk5505_led.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="..\USBSTK_bsl\inc" --include_path="..\C55xx_csl\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="USBSTK_bsl/bsl/usbstk5505_led.pp" --obj_directory="USBSTK_bsl/bsl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


