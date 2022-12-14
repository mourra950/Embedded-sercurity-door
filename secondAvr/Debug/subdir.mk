################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../buzzer.c \
../dcMotor.c \
../external_eeprom.c \
../gpio.c \
../lcd.c \
../secondAvr.c \
../timer0.c \
../twi.c \
../uart.c 

OBJS += \
./buzzer.o \
./dcMotor.o \
./external_eeprom.o \
./gpio.o \
./lcd.o \
./secondAvr.o \
./timer0.o \
./twi.o \
./uart.o 

C_DEPS += \
./buzzer.d \
./dcMotor.d \
./external_eeprom.d \
./gpio.d \
./lcd.d \
./secondAvr.d \
./timer0.d \
./twi.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


