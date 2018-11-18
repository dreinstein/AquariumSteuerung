/*
 * Remote.cpp
 *
 *  Created on: 18.11.2018
 *      Author: herrm
 */

#include "Remote.h"
#include <Ethernet.h>


 Remote::Remote(DS3231* _rtc, DallasTemperature *_tempSensor)
 {
	 rtc = _rtc;
	 tempSensors = _tempSensor;
	 dateTime = new DateTime();
	 serviceMode = false;
	 String remoteString = "";
 }


void Remote::sentToWebServer(char* timeStr,String lightStatus, String pumpStatus, String heaterStatus)
{
	EthernetClient client;
	IPAddress webServer(192, 168, 0, 2);
	client.connect(webServer, 80);
	if(client.connected()){
		tempSensors->requestTemperatures();
		//Serial.println("WebClient connected");
		client.print("GET http://192.168.0.2/index.php?Time=");
		client.print(timeStr);
	    client.print("&Temperatur=");
	    client.print(tempSensors->getTempCByIndex(0));
	    client.print("&Licht=");
	    client.print(lightStatus);
	    client.print("&Pumpe=");
	    client.print(pumpStatus);
	    client.print("&Heizung=");
	    client.print(heaterStatus);
		client.println(" HTTP/1.0");
		client.println("Host: http://192.168.0.2");
		client.println();
	}
	client.stop();
}


void Remote::getCharFromEthernet(EthernetServer* eServer)
{
	IPAddress webServer(192, 168, 0, 2);
	EthernetClient client;
	EthernetServer server(23);
	//Serial.println("getCharFromEthernet");

	bool isConnected = false;
	client = server.available();
//	Serial.println("getCharFromEthernet- eServer availible");
	if (client.available()) {
		    if (!isConnected) {
		      client.flush();
		      isConnected = true;
		    }

	    char c = client.read();
	    if((c > 56) && (c < 128))
	    {
	    	remoteString +=c;
	    	remoteAction(remoteString,&client);
	    }
	  }
	 else
	 {
	//	 Serial.println("client not availible");
	 }
	  // if the server's disconnected, stop the client:
	  if (!client.connected()) {

	    client.stop();
	    remoteString = "";
	  }
}



void Remote::remoteAction(String rString,EthernetClient *client)
{
	/* Verbindung mit Telnet Server
	 * 	 * telnet
	 * open 192.168.0.22
	 * warten
	 * winter - Winterzeit -1h
	 * sommer - Sommerzeit +1 h
	 * sync - mit Timeserver sychronisieren
	 * service - Servicemode einstellen, temperatur und pumpe aus, Licht an
	 * normal  - Normalmode einstellen, d.h SErviceMode zurückstellen, tempertur, pumpe,licht an (abhängig Uhrzeit)
	 */

	String remoteString = "";
	Serial.println(rString);
	int hour = rtc->getTime().hour;
	if(rString == WINTER)
	{
		hour = hour -1;
		rtc->setTime(hour,rtc->getTime().min,rtc->getTime().sec);
		Serial.println("set Wintertime");
		remoteString = "";

	}
	else if (rString == SOMMER)
	{
		hour = hour +1;
		rtc->setTime(hour,rtc->getTime().min,rtc->getTime().sec);
		Serial.println("set Summertime");
		remoteString = "";
	}
	else if(rString == SYNC)
	{
		synchronise();
	}
	else if(rString == SERVICE)
	{
		serviceMode = true;
	}
	else if(rString == NORMAL)
	{
		serviceMode = false;
	}
	else if(rString == TEMP)
	{
		sendTemperaturToClient();
	}
	else if(rString == DPIN1)
	{
		sendoutputPinState(1,client);
	}
	else if(rString == DPIN2)
	{
		sendoutputPinState(2,client);
	}
	else if(rString == DPIN3)
	{
		sendoutputPinState(3,client);
	}
	else if(rString == DPIN4)
	{
		sendoutputPinState(4,client);
	}
	else if(rString == DPIN5)
	{
		sendoutputPinState(5,client);
	}
	else if(rString == DPIN6)
	{
		sendoutputPinState(6,client);
	}
	else if(rString == DPIN7)
	{
		sendoutputPinState(7,client);
	}
	else if(rString == DPIN8)
	{
		sendoutputPinState(8,client);
	}
	else if(rString == DPIN9)
	{
		sendoutputPinState(9,client);
	}
	else if(rString == DPIN10)
	{
		sendoutputPinState(10,client);
	}
	else if(rString == DPIN11)
	{
		sendoutputPinState(11,client);
	}
	else if(rString == DPIN12)
	{
		sendoutputPinState(12,client);
	}
}

void Remote::sendoutputPinState(int pin,EthernetClient *client)
{
//  client = eserver.available();
  client->print("digital pin ");
  client->print(pin);
  client->print(" is ");
  if (digitalRead(pin)) {
    client->println("HIGH");
  }
  else
    client->println("LOW");
}


void Remote::sendTemperaturToClient()
{
  EthernetClient client;
  IPAddress webServer(192, 168, 0, 2);
  client.connect(webServer, 80);
  client.print("Temperatur");
  client.print(" is ");
  tempSensors->requestTemperatures();
  	//Serial.print("     Temperature is: ");
  client.print(tempSensors->getTempCByIndex(0));
}


bool Remote::synchronise()
{
	bool sync = false;
	//Serial.print("actualise ");
	//Serial.println(rtc->getTimeStr());

	int i = 0;
	while(i< 10)
	{
		if(sync)
			break;


		if(dateTime->isNewSync())
		{
			//Serial.print("Have new Synchronisation ");
			int hours = dateTime->getHours();
			int minutes = dateTime->getMinutes();
			int seconds = dateTime->getSeconds();
			int diff = dateTime->getTimeDiff(rtc->getTime());
			hours = hours + diff;
			//Serial.print("set the time ");
			rtc->setTime(hours,minutes,seconds);

			//Serial.print("The new received UTC time is ");
			//Serial.print(hours);
			//Serial.print(":");
			//Serial.print(minutes);
			//Serial.print(":");
			//Serial.println(seconds);
			//rtc.setTime(hours,minutes,seconds);
			sync = true;
		}
	delay(500);
	i = i+1;
	}
	return sync;
}




