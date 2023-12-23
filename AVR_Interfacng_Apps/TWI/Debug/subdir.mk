################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../EXT_EEPROM_prog.c \
../LCD_Prog.c \
../TWI_prog.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./EXT_EEPROM_prog.o \
./LCD_Prog.o \
./TWI_prog.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./EXT_EEPROM_prog.d \
./LCD_Prog.d \
./TWI_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


