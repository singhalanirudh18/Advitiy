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
../ax25.c \
../gps.c \
../hm.c \
../hMaster_SlaveSPItest.c \
../mag.c \
../peripherals.c \
../slave_comm.c \
../spi.c \
../sun.c \
../twi.c \
../uart.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ax25.o \
gps.o \
hm.o \
hMaster_SlaveSPItest.o \
mag.o \
peripherals.o \
slave_comm.o \
spi.o \
sun.o \
twi.o \
uart.o

OBJS_AS_ARGS +=  \
ax25.o \
gps.o \
hm.o \
hMaster_SlaveSPItest.o \
mag.o \
peripherals.o \
slave_comm.o \
spi.o \
sun.o \
twi.o \
uart.o

C_DEPS +=  \
ax25.d \
gps.d \
hm.d \
hMaster_SlaveSPItest.d \
mag.d \
peripherals.d \
slave_comm.d \
spi.d \
sun.d \
twi.d \
uart.d

C_DEPS_AS_ARGS +=  \
ax25.d \
gps.d \
hm.d \
hMaster_SlaveSPItest.d \
mag.d \
peripherals.d \
slave_comm.d \
spi.d \
sun.d \
twi.d \
uart.d

OUTPUT_FILE_PATH +=hMaster_SlaveSPItest.elf

OUTPUT_FILE_PATH_AS_ARGS +=hMaster_SlaveSPItest.elf

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
	$(QUOTE)E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="hMaster_SlaveSPItest.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega128 
	@echo Finished building target: $@
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "hMaster_SlaveSPItest.elf" "hMaster_SlaveSPItest.hex"
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "hMaster_SlaveSPItest.elf" "hMaster_SlaveSPItest.eep" || exit 0
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "hMaster_SlaveSPItest.elf" > "hMaster_SlaveSPItest.lss"
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "hMaster_SlaveSPItest.elf" "hMaster_SlaveSPItest.srec"
	"E:\Atmel Toolchain\AVR8 GCC\Native\3.4.2.939\avr8-gnu-toolchain\bin\avr-size.exe" "hMaster_SlaveSPItest.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "hMaster_SlaveSPItest.elf" "hMaster_SlaveSPItest.a" "hMaster_SlaveSPItest.hex" "hMaster_SlaveSPItest.lss" "hMaster_SlaveSPItest.eep" "hMaster_SlaveSPItest.map" "hMaster_SlaveSPItest.srec"
	