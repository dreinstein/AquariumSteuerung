#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-11-01 12:52:17

#include "Arduino.h"
#include "Arduino.h"
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <ds3231.h>
#include <Ethernet.h>
#include <SPI.h>
#include <DallasTemperature.h>
#include <EthernetUdp.h>
#include "Definitions.h"
#include "Display.h"
#include "Light.h"
#include "Heater.h"
#include "Pump.h"
#include "DateTime.h"

void setup() ;
void loop() ;
void sentToWebServer() ;
void getCharFromEthernet() ;
void remoteAction(String rString) ;
bool setServiceMode() ;
bool setOff() ;
bool synchronise() ;
void sendoutputPinState(int pin) ;
void sendTemperaturToClient() ;

#include "AquariumSteuerung.ino"


#endif
