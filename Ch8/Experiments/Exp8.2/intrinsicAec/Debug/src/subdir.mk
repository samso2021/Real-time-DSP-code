################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/fixPoint_aec_init.c \
../src/fixPoint_double_talk.c \
../src/fixPoint_nlms.c \
../src/fixPoint_nlmsTest.c \
../src/fixPoint_nlp.c \
../src/utility.c 

OBJS += \
./src/fixPoint_aec_init.obj \
./src/fixPoint_double_talk.obj \
./src/fixPoint_nlms.obj \
./src/fixPoint_nlmsTest.obj \
./src/fixPoint_nlp.obj \
./src/utility.obj 

C_DEPS += \
./src/fixPoint_aec_init.pp \
./src/fixPoint_double_talk.pp \
./src/fixPoint_nlms.pp \
./src/fixPoint_nlmsTest.pp \
./src/fixPoint_nlp.pp \
./src/utility.pp 

C_DEPS__QUOTED += \
"src\fixPoint_aec_init.pp" \
"src\fixPoint_double_talk.pp" \
"src\fixPoint_nlms.pp" \
"src\fixPoint_nlmsTest.pp" \
"src\fixPoint_nlp.pp" \
"src\utility.pp" 

OBJS__QUOTED += \
"src\fixPoint_aec_init.obj" \
"src\fixPoint_double_talk.obj" \
"src\fixPoint_nlms.obj" \
"src\fixPoint_nlmsTest.obj" \
"src\fixPoint_nlp.obj" \
"src\utility.obj" 

C_SRCS__QUOTED += \
"../src/fixPoint_aec_init.c" \
"../src/fixPoint_double_talk.c" \
"../src/fixPoint_nlms.c" \
"../src/fixPoint_nlmsTest.c" \
"../src/fixPoint_nlp.c" \
"../src/utility.c" 


# Each subdirectory must supply rules for building sources it contributes
src/fixPoint_aec_init.obj: ../src/fixPoint_aec_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_aec_init.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixPoint_double_talk.obj: ../src/fixPoint_double_talk.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_double_talk.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixPoint_nlms.obj: ../src/fixPoint_nlms.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_nlms.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixPoint_nlmsTest.obj: ../src/fixPoint_nlmsTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_nlmsTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/fixPoint_nlp.obj: ../src/fixPoint_nlp.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/fixPoint_nlp.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/utility.obj: ../src/utility.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 -g --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="src/utility.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


