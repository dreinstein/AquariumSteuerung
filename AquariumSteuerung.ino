

#include "Arduino.h"


#include <LiquidCrystal_I2C.h>
#include <ds3231.h>
#include <Ethernet.h>
#include <SPI.h>
#include <DallasTemperature.h>
#include <EthernetUdp.h>
#include <OneWire.h>
#include "Definitions.h"
#include "Display.h"
#include "Light.h"
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
class Light *light;
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
	//Serial.println("initialised");

	// start the Ethernet connection and the server:

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

	light = new Light(&rtc);
	remote = new Remote(&rtc,&sensors,light);
	display = new Display(&sensors,&lcd,&rtc);
	heater = new Heater();
	pump = new Pump();

//	dateTime = new DateTime();

	//rtc.setDate(10,02,2019);
	//rtc.setDOW(7);
//	rtc.setTime(18,5,00);

	delay(1000);

//	Serial.println("synchronise");
	remote->synchronise();
	remote->getTiming();
	light->setLighOnOff();
	pump->setPumpOn();
	Serial.println(light->getStatus());
	remote->sentToWebServer(light->getStatus(),pump->getStatus(),heater->getStatus());

}


// The loop function is called in an endless loop
void loop()
{

	//Serial.println("loop begin");
	//lcd.clear();
	//lcd.print(rtc.getTemp());
//	delay(1000);
	//rtc.getDateStr();
//	Serial.print(rtc.getDateStr());

	display->setTime();
	display->setTemperature();


	//delay(DELAYTIME_BASE);
	//Serial.println("loop begin");

	if(TO_ACTUALISE(refresh,TOGGLE_TIME_DISPLAY))
	{
		display->setTemperature();
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
			//	Serial.println("set light on Off");
				light->setLighOnOff();
			//	Serial.println("set light on off done");
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

//	Serial.println("to actualise");
/*	if(TO_ACTUALISE(refresh,ACTUALISE_NTC_MULTIPLIER))
	{
		remote->synchronise();
	}*/
	//remote->getFromPort23();
	remote->getFromPort80();
	if(TO_ACTUALISE(refresh,ACTUALISE_REMOTE_MULTIPLIER))
	{
		remote->sentToWebServer(light->getStatus(),pump->getStatus(),heater->getStatus());
	}
}



bool setServiceMode()
{
	bool retVal=false;

	if((digitalRead(SERVICEBUTTON)==INACTIVE) || serviceModeOn)  //switch on
	{
		//Serial.println("ServiceMode set");
		light->setLightOn();
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
		light->setLightOff();
		pump->setPumpOff();
		heater->setHeaterOff();
		retVal=true;
	}
	return retVal;
}








