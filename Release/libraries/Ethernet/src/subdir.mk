################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dhcp.cpp \
C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dns.cpp \
C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/Ethernet.cpp \
C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetClient.cpp \
C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetServer.cpp \
C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetUdp.cpp 

LINK_OBJ += \
./libraries/Ethernet/src/Dhcp.cpp.o \
./libraries/Ethernet/src/Dns.cpp.o \
./libraries/Ethernet/src/Ethernet.cpp.o \
./libraries/Ethernet/src/EthernetClient.cpp.o \
./libraries/Ethernet/src/EthernetServer.cpp.o \
./libraries/Ethernet/src/EthernetUdp.cpp.o 

CPP_DEPS += \
.\libraries\Ethernet\src\Dhcp.cpp.d \
.\libraries\Ethernet\src\Dns.cpp.d \
.\libraries\Ethernet\src\Ethernet.cpp.d \
.\libraries\Ethernet\src\EthernetClient.cpp.d \
.\libraries\Ethernet\src\EthernetServer.cpp.d \
.\libraries\Ethernet\src\EthernetUdp.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Ethernet/src/Dhcp.cpp.o: C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dhcp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\EclipseArduino\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\cores\arduino" -I"C:\AController\AquariumSteuerung\DallasTemperature" -I"C:\AController\AquariumSteuerung\DS3231" -I"C:\AController\AquariumSteuerung\OneWire-master" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\variants\standard" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI\src" -I"C:\AController\AquariumSteuerung\NTPClient-3.1.0" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/Dns.cpp.o: C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dns.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\EclipseArduino\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\cores\arduino" -I"C:\AController\AquariumSteuerung\DallasTemperature" -I"C:\AController\AquariumSteuerung\DS3231" -I"C:\AController\AquariumSteuerung\OneWire-master" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\variants\standard" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI\src" -I"C:\AController\AquariumSteuerung\NTPClient-3.1.0" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/Ethernet.cpp.o: C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/Ethernet.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\EclipseArduino\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\cores\arduino" -I"C:\AController\AquariumSteuerung\DallasTemperature" -I"C:\AController\AquariumSteuerung\DS3231" -I"C:\AController\AquariumSteuerung\OneWire-master" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\variants\standard" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI\src" -I"C:\AController\AquariumSteuerung\NTPClient-3.1.0" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/EthernetClient.cpp.o: C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetClient.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\EclipseArduino\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\cores\arduino" -I"C:\AController\AquariumSteuerung\DallasTemperature" -I"C:\AController\AquariumSteuerung\DS3231" -I"C:\AController\AquariumSteuerung\OneWire-master" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\variants\standard" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI\src" -I"C:\AController\AquariumSteuerung\NTPClient-3.1.0" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/EthernetServer.cpp.o: C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetServer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\EclipseArduino\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\cores\arduino" -I"C:\AController\AquariumSteuerung\DallasTemperature" -I"C:\AController\AquariumSteuerung\DS3231" -I"C:\AController\AquariumSteuerung\OneWire-master" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\variants\standard" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI\src" -I"C:\AController\AquariumSteuerung\NTPClient-3.1.0" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/EthernetUdp.cpp.o: C:/EclipseArduino/sloeber/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetUdp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\EclipseArduino\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\cores\arduino" -I"C:\AController\AquariumSteuerung\DallasTemperature" -I"C:\AController\AquariumSteuerung\DS3231" -I"C:\AController\AquariumSteuerung\OneWire-master" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\variants\standard" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\Wire\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI" -I"C:\EclipseArduino\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.18\libraries\SPI\src" -I"C:\AController\AquariumSteuerung\NTPClient-3.1.0" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4" -I"C:\EclipseArduino\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


