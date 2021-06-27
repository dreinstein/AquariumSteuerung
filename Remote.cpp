/*
 * Remote.cpp
 *
 *  Created on: 18.11.2018
 *      Author: herrm
 */

#include "Remote.h"
#include <Ethernet.h>
#include <DallasTemperature.h>
#include "Light.h"


 Remote::Remote(DS3231* _rtc, DallasTemperature *_tempSensor, Light* _light)
 {
	 rtc = _rtc;
	 light = _light;
	 tempSensors = _tempSensor;
	 dateTime = new DateTime();
	 serviceMode = false;
	 String remoteString = "";
 }


 void Remote::sentToWebServer(String lightStatus, String pumpStatus, String heaterStatus)
{
	EthernetClient client;
	IPAddress webServer(192, 168, 0, 2);
	client.connect(webServer, 80);
	//Serial.println("setToWebServer");
	if(client.connected()){
		tempSensors->requestTemperatures();
	//	Serial.println("WebClient connected, send data");
		client.print("GET /status.php?");
	    client.print("Temperature=");
	    client.print(tempSensors->getTempCByIndex(0));
	    client.print("&Light=");
	    client.print("'");
	    client.print(lightStatus);
	    client.print("'");
	    client.print("&Pump=");
	    client.print("'");
	    client.print(pumpStatus);
	    client.print("'");
	    client.print("&Heating=");
	    client.print("'");
	    client.print(heaterStatus);
	    client.print("'");
		client.println(" HTTP/1.1");
		client.println("Host: 192.168.0.22");
		client.println("Connection: close");
		client.println();
	}
	//client.stop();
}

void Remote::getFromPort80()
{
	EthernetClient client;
	EthernetServer server(Port80);
	server.begin();
	bool isConnected = false;
	client = server.available();
//	Serial.println("try to connect to webserver port 80");

	if (client.available())
	{
	    if (!isConnected)
	    {
		     client.flush();
		     isConnected = true;
		}
	  //  Serial.println("connected to port 80");
	    if(client.find("GET /") )
	    {
	    //	Serial.println("get new char from Ethernet");

	    	char type=client.read();
	    	bool abortReading = false;
	    	while(!abortReading)
	    	{
	    		type = client.read();
	    		remoteString += type;
	    	//	Serial.println(remoteString);
	    		abortReading = remoteAction(remoteString,&client, Port80);
	    		if(remoteString.length() > 200)
	    		{
	    			abortReading = true;

	    		}
	    	}
	    	remoteString="";
	    	client.println("HTTP/1.1 205 OK");
	    	client.stop();
	    //	Serial.println(remoteString);
	    }
	}
}


void Remote::getFromPort23()
{
	EthernetClient client;
	EthernetServer server(Port23);
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
	 //   Serial.println(c);
	    remoteString +=c;
	    remoteAction(remoteString,&client,Port23);
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


void Remote::getTiming()
{
	EthernetClient client;
	IPAddress webServer(192, 168, 0, 2);
	client.connect(webServer, 80);
	//Serial.println("setToWebServer fetch Timing");
	if(client.connected()){
	client.print("GET /fetchTiming.php?");
	client.println(" HTTP/1.1");
	client.println("Host: 192.168.0.22");
	client.println("Connection: close");
	client.println();
	client.stop();
	}
}

bool Remote::remoteAction(String rString,EthernetClient *client, Port port)
{
	/* Verbindung mit Telnet Server
	 * 	 * telnet
	 * open 192.168.0.22
	 * warten
	 * winter - Winterzeit -1h
	 * sommer - Sommerzeit +1 h
	 * sync - mit Timeserver sychronisieren
	 * service - Servicemode einstellen, temperatur und pumpe aus, Licht an
	 * normal  - Normalmode einstellen, d.h SErviceMode zur�ckstellen, tempertur, pumpe,licht an (abh�ngig Uhrzeit)
	 */

	String remoteString = "";
//	Serial.println(rString);
	int hour = rtc->getTime().hour;
	if(rString == WINTER)
	{
		hour = hour -1;
		rtc->setTime(hour,rtc->getTime().min,rtc->getTime().sec);
		//Serial.println("set Wintertime");
		remoteString = "";
		return true;
	}
	else if (rString == SOMMER)
	{
		hour = hour +1;
		rtc->setTime(hour,rtc->getTime().min,rtc->getTime().sec);
		//Serial.println("set Summertime");
		remoteString = "";
		return true;
	}
	else if(rString == SYNC)
	{
		//client->println("HTTP/1.1 205 OK");
		synchronise();
		return true;
	}
	else if(rString == SERVICE)
	{
		//client->println("HTTP/1.1 205 OK");
		serviceMode = true;
		return true;
	}
	else if(rString == NORMAL)
	{
		//client->println("HTTP/1.1 205 OK");
		serviceMode = false;
		return true;
	}
	else if(rString == TEMP)
	{
		//client->println("HTTP/1.1 205 OK");
		//client->stop();
		sendTemperature(client,port);
		return true;
	}
	else if(rString == DPIN1)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(1,client);
		return true;
	}
	else if(rString == DPIN2)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(2,client);
		return true;
	}
	else if(rString == DPIN3)
	{
		sendoutputPinState(3,client);
		return true;
	}
	else if(rString == DPIN4)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(4,client);
		return true;
	}
	else if(rString == DPIN5)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(5,client);
		return true;
	}
	else if(rString == DPIN6)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(6,client);
		return true;
	}
	else if(rString == DPIN7)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(7,client);
		return true;
	}
	else if(rString == DPIN8)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(8,client);
		return true;
	}
	else if(rString == DPIN9)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(9,client);
		return true;
	}
	else if(rString == DPIN10)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(10,client);
		return true;
	}
	else if(rString == DPIN11)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(11,client);
		return true;
	}
	else if(rString == DPIN12)
	{
		//client->println("HTTP/1.1 205 OK");
		sendoutputPinState(12,client);
		return true;
	}
	else if(rString.endsWith(ENDTIMING))
	{
		//client->println("HTTP/1.1 205 OK");
	//	Serial.println("Timeing transfered");
		setTiming(rString);
		return true;
	}
	return false;
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


void Remote::sendTemperature(EthernetClient *client,Port port)
{
	if(port == Port80)
	{
		readTillEnd(client);
		sendTemperaturePort80(client);
	}
	else if(port == Port23)
	{
		sendTemperaturePort23(client);
	}
	else
	{
		Serial.println("error: wrong port");
	}

}

void Remote::readTillEnd(EthernetClient *client)
{
	bool endOfRequest = false;
	while (client->connected()) {
	     if (client->available()) {
	      char c = client->read();
	    //  Serial.println(c);
	      if (endOfRequest &&(c == '\n'))
		  {
	    	Serial.println("read till end");
	    	return;
		  }
	      if((c == '\n') || (c == '\r'))
		  {
	    	  endOfRequest = true;
		  }
	     }
	}

}


void Remote::sendTemperaturePort80(EthernetClient *client)
{
	Serial.println("sentTemperatur:.....");
	//EthernetClient client;
	//IPAddress webServer(192, 168, 0, 2);
	//client.connect(webServer, 80);
	if(client->connected())
	{
		Serial.println("http200 ok");
		client->println("HTTP/1.1 200 OK"); //send new page
		client->println("Content-Type: text/html");
	//	Serial.print("http:/192.168.0.2/?temperature=10");
		client->println();
		client->stop();

	/*	float temp = tempSensors->getTempCByIndex(0);
		client->println("HTTP/1.1 200 OK");
		client->println("Content-Type: text/html");

		//
		client->println();
		client->println("<!DOCTYPE HTML>");
	    client->println("<html>");

	    client->println("</html>");
		client->stop();
		Serial.println("client stopped");
		Serial.println("HTTP/1.1 200 OK");
		Serial.println("Content-Type: text/html");
		Serial.println();
		Serial.println("<html>");
		Serial.println("<body>");
		Serial.println("<hr>");
		Serial.println("<br>");
		Serial.print("<form action = http:/192.168.0.2/?temperature=");
		Serial.print(temp);
		Serial.println(" method=post>");
		Serial.println("<input type=text name=temperature>");
		Serial.println("<button type = submit> Absenden </button>");
		Serial.println("</br>");
		Serial.println("</hr>");
		Serial.println("</body>");
		Serial.println("</html>");*/
	}

}


void Remote::sendTemperaturePort23(EthernetClient *client)
{
  client->print("Temperatur");
  client->print(" is ");
  tempSensors->requestTemperatures();
  	//Serial.print("     Temperature is: ");
  client->print(tempSensors->getTempCByIndex(0));
}


bool Remote::synchronise()
{
	Serial.print("time synchronise ");
	//Serial.println(rtc->getTimeStr());
	int i = 0;
	while(i< 10)
	{
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
			rtc->setDOW();

			Serial.print("The new received UTC time is ");
			Serial.print(hours);
			Serial.print(":");
			Serial.print(minutes);
			Serial.print(":");
			Serial.println(seconds);
			//rtc.setTime(hours,minutes,seconds);
			return true;
		}
	i = i+1;
	delay(500);
	}
	return false;
}

void Remote::setTiming(String timeString)
{
	String delimiter = "&";

	char* ctimeLightOn_firstOverweek= new char[10];
	char* ctimeLightOn_secondOverweek= new char[10];
	char* ctimeLightOff_firstOverweek= new char[10];
	char* ctimeLightOff_secondOverweek= new char[10];
	char* ctimeLightOn_firstWeekend= new char[10];
	char* ctimeLightOn_secondWeekend= new char[10];
	char* ctimeLightOff_firstWeekend= new char[10];
	char* ctimeLightOff_secondWeekend= new char[10];


	int index_1 = timeString.indexOf(delimiter);
	String str = timeString.substring(0,index_1);
	str.toCharArray(ctimeLightOn_firstOverweek,10);

	int index_2 = timeString.indexOf(delimiter, index_1+1);
	str = timeString.substring(index_1+1,index_2);
	str.toCharArray(ctimeLightOn_secondOverweek,10);

	index_1 = timeString.indexOf(delimiter, index_2+1);
	str = timeString.substring(index_2+1,index_1);
	str.toCharArray(ctimeLightOff_firstOverweek,10);

	index_2 = timeString.indexOf(delimiter, index_1+1);
	str = timeString.substring(index_1+1,index_2);
	str.toCharArray(ctimeLightOff_secondOverweek,10);

	index_1 = timeString.indexOf(delimiter,index_2+1);
	str = timeString.substring(index_2+1,index_1);
	str.toCharArray(ctimeLightOn_firstWeekend,10);

	index_2 = timeString.indexOf(delimiter, index_1+1);
	str = timeString.substring(index_1+1,index_2);
	str.toCharArray(ctimeLightOn_secondWeekend,10);

	index_1 = timeString.indexOf(delimiter, index_2+1);
	str = timeString.substring(index_2+1,index_1);
	str.toCharArray(ctimeLightOff_firstWeekend,10);

	index_2 = timeString.indexOf(delimiter, index_1+1);
	str = timeString.substring(index_1+1,index_2);
	str.toCharArray(ctimeLightOff_secondWeekend,10);

/*	Serial.println(timeString);
	Serial.println(ctimeLightOn_firstOverweek);
	Serial.println(ctimeLightOn_secondOverweek);
	Serial.println(ctimeLightOff_firstOverweek);
	Serial.println(ctimeLightOff_secondOverweek);
	Serial.println(ctimeLightOn_firstWeekend);
	Serial.println(ctimeLightOn_secondWeekend);
	Serial.println(ctimeLightOff_firstWeekend);
	Serial.println(ctimeLightOff_secondWeekend);*/

	light->setTiming(ctimeLightOn_firstOverweek, ctimeLightOff_firstOverweek, ctimeLightOn_secondOverweek, ctimeLightOff_secondOverweek,
			ctimeLightOn_firstWeekend, ctimeLightOff_firstWeekend, ctimeLightOn_secondWeekend, ctimeLightOff_secondWeekend);

}




