/*
 * Remote.h
 *
 *  Created on: 18.11.2018
 *      Author: herrm
 */

#ifndef REMOTE_H_
#define REMOTE_H_

#include "Arduino.h"
#include <ds3231.h>
#include <Ethernet.h>
#include <DallasTemperature.h>
#include "DateTime.h"





class Remote {
public:
	enum Port
	{
		Port23 = 23,
		Port80 = 80
	};

	Remote(DS3231* _rtc,DallasTemperature *_tempSensor);
	~Remote();
	void sentToWebServer(String lightStatus, String pumpStatus, String heaterStatus);
	void getFromPort80();
	void getFromPort23();

	void sendTemperature(EthernetClient *client, Port port);
	bool synchronise();
private:
	void sendoutputPinState(int pin,EthernetClient *client);
	void readTillEnd(EthernetClient *client);
	DS3231 *rtc;
	class DateTime* dateTime;
	DallasTemperature *tempSensors;
	String remoteString;

	bool serviceMode;

	bool remoteAction(String rString,EthernetClient *client, Port port);
	void sendTemperaturePort23(EthernetClient *client);
	void sendTemperaturePort80(EthernetClient *client);

	const String WINTER  = "winter";
	const String SOMMER = "sommer";
	const String SYNC = "sync";
	const String SERVICE = "service";
	const String TEMP = "temperatur";
	const String NORMAL = "normal";
	//const String NO = "no";
	const String DPIN1 = "pin1";
	const String DPIN2 = "pin2";
	const String DPIN3 = "pin3";
	const String DPIN4 = "pin4";
	const String DPIN5 = "pin5";
	const String DPIN6 = "pin6";
	const String DPIN7 = "pin7";     // Service
	const String DPIN8 = "pin8";     // onOff
	const String DPIN9 = "pin9";     //Light
	const String DPIN10 = "pin10";   // Pump
	const String DPIN11 = "pin11";   // Heater
	const String DPIN12 = "pin12";


};

#endif /* REMOTE_H_ */
