/*
 * Light.h
 *
 *  Created on: 28.05.2017
 *      Author: Udo
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include <DS3231.h>

// default Timesettings for overweek and weekend
#define TIMELIGHTON_FIRST_OVERWEEK   "07:00:00"
#define TIMELIGHTOFF_FIRST_OVERWEEK  "12:00:00"
#define TIMELIGHTON_SECOND_OVERWEEK  "13:00:00"
#define TIMELIGHTOFF_SECOND_OVERWEEK "21:45:00"
#define TIMELIGHTON_FIRST_WEEKEND    "08:30:00"
#define TIMELIGHTOFF_FIRST_WEEKEND   "12:00:00"
#define TIMELIGHTON_SECOND_WEEKEND    "13:30:00"
#define TIMELIGHTOFF_SECOND_WEEKEND   "23:00:00"



// stati for light
enum class LIGHT_STATUS
{
	LIGHT_ON=0,
	LIGHT_OFF,
	LIGHT_NOCHANGE
};


class Light {
public:
	Light(DS3231  *_rtc);
	virtual ~Light();
	void setLighOnOff();
	void setLightOn();
	void setLightOff();
	String getStatus();

	void setTiming(char* _timeLightOn_first_overWeek, char* _timeLightOff_first_overWeek, char* _timeLightOn_second_overWeek,
			char*_timeLightOff_second_overWeek, char* _timeLightOn_first_weekEnd,char* _timeLightOff_first_weekEnd,
			char* _timeLightOn_second_weekEnd, char* _timeLightOff_second_weekEnd);
private:
	LIGHT_STATUS isLightOn();
	bool isWeekend();
	DS3231  *rtc;
	char* timeLightOn_first_overWeek;
	char* timeLightOff_first_overWeek;
	char* timeLightOn_second_overWeek;
	char* timeLightOff_second_overWeek;
	char* timeLightOn_first_weekEnd;
	char* timeLightOff_first_weekEnd;
	char* timeLightOn_second_weekEnd;
	char* timeLightOff_second_weekEnd;


	const char* saturday = "Sat";
	const char*  sunday =  "Sun";
};

#endif /* LIGHT_H_ */
