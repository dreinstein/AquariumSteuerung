/*
 * Light.cpp
 *
 *  Created on: 28.05.2017
 *      Author: Udo
 */

#include "Light.h"

#include <Arduino.h>
#include <HardwareSerial.h>
#include <stdlib.h>

#include "Definitions.h"


Light::Light(DS3231  *_rtc) {
	// TODO Auto-generated constructor stub
	rtc = _rtc;
	timeLightOn_first_overWeek = (char*)TIMELIGHTON_FIRST_OVERWEEK;
	timeLightOff_first_overWeek = (char*)TIMELIGHTOFF_FIRST_OVERWEEK;
	timeLightOn_second_overWeek = (char*)TIMELIGHTON_SECOND_OVERWEEK;
	timeLightOff_second_overWeek = (char*)TIMELIGHTOFF_SECOND_OVERWEEK;
	timeLightOn_first_weekEnd = (char*)TIMELIGHTON_FIRST_WEEKEND;
	timeLightOff_first_weekEnd = (char*)TIMELIGHTOFF_FIRST_WEEKEND;
	timeLightOn_second_weekEnd = (char*)TIMELIGHTON_SECOND_WEEKEND;
	timeLightOff_second_weekEnd = (char*)TIMELIGHTOFF_SECOND_WEEKEND;
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

void Light::setTiming(char* _timeLightOn_first_overWeek, char* _timeLightOff_first_overWeek, char* _timeLightOn_second_overWeek,
		char*_timeLightOff_second_overWeek, char* _timeLightOn_first_weekEnd,char* _timeLightOff_first_weekEnd,
		char* _timeLightOn_second_weekEnd, char* _timeLightOff_second_weekEnd)
{
	timeLightOn_first_overWeek = _timeLightOn_first_overWeek;
	timeLightOff_first_overWeek = _timeLightOff_first_overWeek;
	timeLightOn_second_overWeek = _timeLightOn_second_overWeek;
	timeLightOff_second_overWeek = _timeLightOff_second_overWeek;
	timeLightOn_first_weekEnd = _timeLightOn_first_weekEnd;
	timeLightOff_first_weekEnd = _timeLightOff_first_weekEnd;
	timeLightOn_second_weekEnd = _timeLightOn_second_weekEnd;
	timeLightOff_second_weekEnd = _timeLightOff_second_weekEnd;

}


void Light::setLighOnOff()
{
	if(isLightOn() == LIGHT_STATUS::LIGHT_ON)
	{
		Serial.println("light on");
		setLightOn();
	}
	else
	{
		//Serial.println("light off");
		setLightOff();
	}
}


void Light::setLightOn()
{
	//Serial.println("Light On\n");
	digitalWrite(RELAIS2,ACTIVE);
}

void Light::setLightOff()
{
	//Serial.println("Light Off\n");
	digitalWrite(RELAIS2,INACTIVE);
}

String Light::getStatus()
{
	if(isLightOn()== LIGHT_STATUS::LIGHT_ON)
	{
		return "on";
	}
	else
	{
		return "off";
	}

}



LIGHT_STATUS Light::isLightOn()
{

	long unixOnTime_first = 0;
	long unixOffTime_first = 0;
	long unixOnTime_second = 0;
	long unixOffTime_second = 0;
	char* timeLightOn_first;
	char* timeLightOff_first;
	char* timeLightOn_second;
	char* timeLightOff_second;


	if(isWeekend())
	{
		timeLightOn_first = timeLightOn_first_weekEnd;
		timeLightOff_first = timeLightOff_first_weekEnd;
		timeLightOn_second = timeLightOn_second_weekEnd;
		timeLightOff_second = timeLightOff_second_weekEnd;



	}
	else
	{
		timeLightOn_first = timeLightOn_first_overWeek;
		timeLightOff_first = timeLightOff_first_overWeek;
		timeLightOn_second = timeLightOn_second_overWeek;
		timeLightOff_second = timeLightOff_second_overWeek;
	}

/*	Serial.println("");
	Serial.print("timeLightOn_first");
	Serial.println(timeLightOn_first);
	Serial.print("timeLightOn_second");
	Serial.println(timeLightOn_second);
	Serial.print("timeLightOff_first");
	Serial.println(timeLightOff_first);
	Serial.print("timeLightOff_second");
	Serial.println(timeLightOff_second);*/



	Time lightOn_first;
	lightOn_first.date = rtc->getTime().date;
	lightOn_first.year = rtc->getTime().year;
	lightOn_first.mon = rtc->getTime().mon;
	lightOn_first.dow = rtc->getTime().dow;
	lightOn_first.hour = atoi(timeLightOn_first);
	lightOn_first.min = atoi(timeLightOn_first+3);
	lightOn_first.sec = atoi(timeLightOn_first+6);
	unixOnTime_first = rtc->getUnixTime(lightOn_first);


	Time lightOff_first;
	lightOff_first.date = rtc->getTime().date;
	lightOff_first.year = rtc->getTime().year;
	lightOff_first.mon = rtc->getTime().mon;
	lightOff_first.dow = rtc->getTime().dow;
	lightOff_first.hour = atoi(timeLightOff_first);
	lightOff_first.min = atoi(timeLightOff_first+3);
	lightOff_first.sec = atoi(timeLightOff_first+6);
	unixOffTime_first= rtc->getUnixTime(lightOff_first);

	Time lightOn_second;
	lightOn_second.date = rtc->getTime().date;
	lightOn_second.year = rtc->getTime().year;
	lightOn_second.mon = rtc->getTime().mon;
	lightOn_second.dow = rtc->getTime().dow;
	lightOn_second.hour =  atoi(timeLightOn_second);
	lightOn_second.min = atoi(timeLightOn_second+3);
	lightOn_second.sec = atoi(timeLightOn_second+6);
	unixOnTime_second = rtc->getUnixTime(lightOn_second);


	Time lightOff_second;
	lightOff_second.date = rtc->getTime().date;
	lightOff_second.year = rtc->getTime().year;
	lightOff_second.mon = rtc->getTime().mon;
	lightOff_second.dow = rtc->getTime().dow;
	lightOff_second.hour = atoi(timeLightOff_second);
	lightOff_second.min = atoi(timeLightOff_second+3);
	lightOff_second.sec = atoi(timeLightOff_second+6);
	unixOffTime_second = rtc->getUnixTime(lightOff_second);


	long unixActualTime = rtc->getUnixTime(rtc->getTime());
	//Serial.println(rtc->getTimeStr(FORMAT_LONG));



	// before 0:00, set offtime to next day
/*	if((unixOnTime_first > unixOffTime_first ) && (unixActualTime > unixOnTime_first))
	{
		lightOff_first.date = rtc->getTime().date+1;
		lightOff_first.hour = intOffHour;
		lightOff_first.min = intOffMinute;
		lightOff_first.sec = intOffSecond;
		unixOffTime_first = rtc->getUnixTime(lightOff_first);
		Serial.print("unixoffTime + 1 Day   ");
		Serial.println(unixOffTime_first);
	}

	// if offtime next day
	//after 0:00, set ontime one day before
	if((unixOnTime_first > unixOffTime_first) && (unixActualTime < unixOffTime_first))
	{
		lightOn_first.date = rtc->getTime().date-1;
		lightOn_first.hour = intOnHour;
		lightOn_first.min = intOnMinute;
		lightOn_first.sec = intOnSecond;
		unixOnTime_first = rtc->getUnixTime(lightOn_first);
		Serial.print("unixonTime - 1 Day   ");
		Serial.println(unixOnTime_first);
	}*/

	if(unixActualTime > unixOffTime_second)
	{
		return LIGHT_STATUS::LIGHT_OFF;
	}
	else if(unixActualTime > unixOnTime_second)
	{
		return LIGHT_STATUS::LIGHT_ON;
	}

	else if(unixActualTime > unixOffTime_first)
	{
		Serial.println("Light off");
		return LIGHT_STATUS::LIGHT_OFF;
	}
	else if(unixActualTime > unixOnTime_first)
	{
		Serial.println("Light on");
		return LIGHT_STATUS::LIGHT_ON;
	}

	return LIGHT_STATUS::LIGHT_OFF;
}





bool Light::isWeekend()
{
	char* dayOfWeek = rtc->getDOWStr(FORMAT_SHORT);
	if((dayOfWeek == saturday) || (dayOfWeek == sunday))
	{
		return true;
	}
	return false;
}


