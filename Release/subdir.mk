################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Encoder.cpp \
../HardwareSerial.cpp \
../IRRangers.cpp \
../Print.cpp \
../Robot.cpp \
../Servo.cpp \
../WMath.cpp \
../main.cpp 

C_SRCS += \
../WInterrupts.c \
../motorcontrol.c \
../pins_arduino.c \
../pwm.c \
../wiring.c \
../wiring_analog.c \
../wiring_digital.c \
../wiring_pulse.c \
../wiring_shift.c 

OBJS += \
./Encoder.o \
./HardwareSerial.o \
./IRRangers.o \
./Print.o \
./Robot.o \
./Servo.o \
./WInterrupts.o \
./WMath.o \
./main.o \
./motorcontrol.o \
./pins_arduino.o \
./pwm.o \
./wiring.o \
./wiring_analog.o \
./wiring_digital.o \
./wiring_pulse.o \
./wiring_shift.o 

C_DEPS += \
./WInterrupts.d \
./motorcontrol.d \
./pins_arduino.d \
./pwm.d \
./wiring.d \
./wiring_analog.d \
./wiring_digital.d \
./wiring_pulse.d \
./wiring_shift.d 

CPP_DEPS += \
./Encoder.d \
./HardwareSerial.d \
./IRRangers.d \
./Print.d \
./Robot.d \
./Servo.d \
./WMath.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-gcc  -s -Os -c -o"$@" "$<" -lm -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


