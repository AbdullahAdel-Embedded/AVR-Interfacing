################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad/Keypad_Prog.c 

OBJS += \
./HAL/Keypad/Keypad_Prog.o 

C_DEPS += \
./HAL/Keypad/Keypad_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad/%.o: ../HAL/Keypad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Projects\NTI\Project_5_EEPROM\APP" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\EEPROM" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\WIFI" -I"C:\Projects\NTI\Project_5_EEPROM\HAL" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL" -I"C:\Projects\NTI\Project_5_EEPROM\LIB" -I"C:\Projects\NTI\Project_5_EEPROM\APP\Projects" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\Buzzer" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\Keypad" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\LCD" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\LDR" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\LED" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\PushButton" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\Relay" -I"C:\Projects\NTI\Project_5_EEPROM\HAL\SSD" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\ADC" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\DIO" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\EXINT" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\GIE" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\I2C" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\Timer" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\UART" -I"C:\Projects\NTI\Project_5_EEPROM\MCAL\WDT" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


