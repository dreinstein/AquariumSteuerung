

#include "Arduino.h"


#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Ethernet.h>
#include <SPI.h>
#include <DallasTemperature.h>
#include <EthernetUdp.h>
#include <OneWire.h>
#include "Definitions.h"
#include "Display.h"
#include "Heater.h"
#include "Pump.h"
#include "DateTime.h"
#include "Remote.h"





long refresh=0;
bool serviceModeOn = false;


// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
OneWire  ds(TEMPSENSOR);
DallasTemperature sensors(&ds);
/// Belegung SDA, SCL
/// Arduino SDA = PinAnalog 4
///         SLC = Pin Analog 5

LiquidCrystal_I2C lcd(0x27,16,2);

// functionDeclaration
bool setServiceMode();
bool setOff();
bool connected;

class Display *display;
class Heater *heater;
class Pump *pump;
class DateTime* dateTime;
class Remote* remote;


// assign a MAC address for the Ethernet controller.
// fill in your address here:


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// assign an IP address for the controller:
IPAddress ip(192, 168, 0, 22);
EthernetServer eserver(23);
//void getCharFromEthernet();
String remoteString;



void setup()
{
// Add your initialization code here
	Serial.begin(9600);
	while (!Serial) {
		    ; // wait for serial port to connect. Needed for native USB port only
		  }
//	Serial.println("Setup\n");
	lcd.init();
	rtc.begin();
	lcd.begin(16,2);
	lcd.backlight();
	connected = false;

	//Serial.println("ready setup");
	rtc.begin();
	sensors.begin();
	sensors.setResolution(TEMP_RESOLUTION);


	refresh = 0;
	Ethernet.begin(mac, ip);
	Serial.begin(9600);
	while(!Serial)
	{;
	}
	delay(1000);
	eserver.begin();


	pinMode(RELAIS2,OUTPUT);
	pinMode(RELAIS3,OUTPUT);
	pinMode(RELAIS4,OUTPUT);

	pinMode(SERVICEBUTTON,INPUT_PULLUP);
	pinMode(ONOFFBUTTON,INPUT_PULLUP);
	pinMode(TEMPSENSOR,INPUT);

	remote = new Remote(&rtc,&sensors);
	display = new Display(&sensors,&lcd,&rtc);
	heater = new Heater();
	pump = new Pump();

	// set date manually if arduino was inactive to long
	// do not need it anymore with version 4.0
	//rtc.setDate(13,05,2021);
	//rtc.setDOW(1);

	delay(1000);

//	Serial.println("synchronise");
	remote->synchronise();
	remote->getTiming();
	pump->setPumpOn();
	remote->sentToWebServer("N/A",pump->getStatus(),heater->getStatus());

}


// The loop function is called in an endless loop
void loop()
{
	if(TO_ACTUALISE(refresh,TOGGLE_TIME_DISPLAY))
	{
		display->setTemperature();
		display->setTime();
	}

	if(!setOff())
	{
		if(!setServiceMode())
		{
		//	Serial.println("ServiceModeOff");

			float celsius = display->getWaterTemperature();
			//Serial.println("celsius");
			heater->setHeaterOnOff(celsius);

			if(TO_ACTUALISE(refresh,ACTUALISE_LIGHT_MULTiPLIER))
			{
				pump->setPumpOn();
			}
		}
	}
	refresh = refresh+1;
   //Serial.println("Loop");
	if(refresh> REFRESHVARIABLE_MAX)
	{
		refresh = 0;
	}

	remote->getFromPort80();
	if(TO_ACTUALISE(refresh,ACTUALISE_REMOTE_MULTIPLIER))
	{
		remote->sentToWebServer("N/A",pump->getStatus(),heater->getStatus());
	}
}



bool setServiceMode()
{
	bool retVal=false;

	if((digitalRead(SERVICEBUTTON)==INACTIVE) || serviceModeOn)  //switch on
	{
		//Serial.println("ServiceMode set");
		pump->setPumpOff();
		heater->setHeaterOff();
		retVal=true;
	}
	return retVal;
}

bool setOff()
{
	bool retVal = false;
	if(digitalRead(ONOFFBUTTON)==INACTIVE) // Switch on
	{
		pump->setPumpOff();
		heater->setHeaterOff();
		retVal=true;
	}
	return retVal;
}








