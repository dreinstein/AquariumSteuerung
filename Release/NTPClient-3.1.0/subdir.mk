################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\NTPClient-3.1.0\NTPClient.cpp 

LINK_OBJ += \
.\NTPClient-3.1.0\NTPClient.cpp.o 

CPP_DEPS += \
.\NTPClient-3.1.0\NTPClient.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
NTPClient-3.1.0\NTPClient.cpp.o: ..\NTPClient-3.1.0\NTPClient.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


