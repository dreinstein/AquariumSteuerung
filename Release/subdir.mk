################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\AquariumSteuerung.ino 

CPP_SRCS += \
..\DateTime.cpp \
..\Display.cpp \
..\Heater.cpp \
..\Light.cpp \
..\Pump.cpp \
..\sloeber.ino.cpp 

LINK_OBJ += \
.\DateTime.cpp.o \
.\Display.cpp.o \
.\Heater.cpp.o \
.\Light.cpp.o \
.\Pump.cpp.o \
.\sloeber.ino.cpp.o 

INO_DEPS += \
.\AquariumSteuerung.ino.d 

CPP_DEPS += \
.\DateTime.cpp.d \
.\Display.cpp.d \
.\Heater.cpp.d \
.\Light.cpp.d \
.\Pump.cpp.d \
.\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
AquariumSteuerung.o: ..\AquariumSteuerung.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

DateTime.cpp.o: ..\DateTime.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Display.cpp.o: ..\Display.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Heater.cpp.o: ..\Heater.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Light.cpp.o: ..\Light.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Pump.cpp.o: ..\Pump.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\cores\arduino" -I"D:\code\Neu\AController\AquariumSteuerung\DallasTemperature" -I"D:\code\Neu\AController\AquariumSteuerung\DS3231" -I"D:\code\Neu\AController\AquariumSteuerung\OneWire-master" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\variants\standard" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\Wire\src" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"D:\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\SPI\src" -I"D:\code\Neu\AController\AquariumSteuerung\NTPClient-3.1.0" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6" -I"D:\sloeber\arduinoPlugin\libraries\WiFi\1.2.6\src" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1" -I"D:\sloeber\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID" -I"D:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.21\libraries\HID\src" -I"D:\sloeber\arduinoPlugin\libraries\LiquidCrystal_I2C-1.1.2\1.1.2" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


