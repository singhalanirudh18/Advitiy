################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../hSlave_uarttest.c \
../uart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
hSlave_uarttest.o \
uart.o

OBJS_AS_ARGS +=  \
hSlave_uarttest.o \
uart.o

C_DEPS +=  \
hSlave_uarttest.d \
uart.d

C_DEPS_AS_ARGS +=  \
hSlave_uarttest.d \
uart.d

OUTPUT_FILE_PATH +=hSlave_uarttest.elf

OUTPUT_FILE_PATH_AS_ARGS +=hSlave_uarttest.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler





./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 3.4.2
	$(QUOTE)E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -funsigned-char -funsigned-bitfields -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega128 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 3.4.2
	$(QUOTE)E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="hSlave_uarttest.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega128 
	@echo Finished building target: $@
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "hSlave_uarttest.elf" "hSlave_uarttest.hex"
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "hSlave_uarttest.elf" "hSlave_uarttest.eep" || exit 0
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "hSlave_uarttest.elf" > "hSlave_uarttest.lss"
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "hSlave_uarttest.elf" "hSlave_uarttest.srec"
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-size.exe" "hSlave_uarttest.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "hSlave_uarttest.elf" "hSlave_uarttest.a" "hSlave_uarttest.hex" "hSlave_uarttest.lss" "hSlave_uarttest.eep" "hSlave_uarttest.map" "hSlave_uarttest.srec"
	